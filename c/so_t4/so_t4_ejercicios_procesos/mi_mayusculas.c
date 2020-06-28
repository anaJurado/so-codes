/*
TEMA 4  - EJERCICIOS PROPUESTOS - PROCESOS (2)
Escriba un programa en C llamado “mayusculas” que haga lo siguiente: 
-Cree un proceso hijo. 
-El proceso padre y el proceso hijo se comunicarán de forma bidireccional utilizando tuberías. 
-El proceso padre leerá líneas de la entrada estándar y las enviará por una tubería al proceso hijo. 
-El proceso hijo leerá por una tubería el texto que le envía el padre, 
 lo transformará todo a letras mayúsculas y se lo enviará al padre por otra tubería. 
-El padre imprimirá en pantalla lo que recibe del hijo. 

Ejemplo de ejecución: 

$ ./mayusculas hola 
(enter) HOLA mundo 
(enter) MUNDO 

*/


// ANOTACIONES
/*
VARIABLES
Necesito dos tuberías para poder hacer la "tubería bidireccional"
Para manejar una tubería necesito un array de dos integers. Estos integers representan los descriptores de fichero (fd)
int pipe(int filedes[2])

Vamos a crear un proceso hijo, a si que necesitamos un pid_t para guardar el pid del proceso 

Necesitamos pasar una cadena de characters a si que creamos una array de tipo char con 1024 posiciones llamado texto
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main (int argc, char **argv){

	// VARIABLES

	//pipes
	int pipe_1[2]; 
	int pipe_2[2];
	//proceso hijo
	pid_t pid;
	//string a guardar
	char texto[1024];
	// Los pipes se pueden manejar con descriptores de fichero o con tipo de datos FILE *
	// Es como guardar en FILE * las cosas que pasan por el pipe
	// La ventaja es que podemos utilizar métodos como: fread(3),fwrite(3), fclose(3), fputs(3), fgets(3)
	FILE *fpipe_1;
	FILE *fpipe_2;  
    

	// CREAMOS LOS PIPES
	/*
		int pipe(int filedes[2]): crea una tubería y asigna el
		descriptor de fichero de la entrada a filedes[1] y el
		descriptor de la salida a filedes[0]. 
	*/
	pipe(pipe_1);
    pipe(pipe_2);

    // CREAMOS PROCESO HIJO
	// Para tener un proceso PADRE y un proceso HIJO hacemos el FORK()
	/*
	fork:
		§ Crea un proceso clonando al padre
		§ Copia la imagen del padre en otra zona de memoria
		§ Copia el PCB en la tabla de procesos
		§ Cambia el pid y la descripción de memoria en el nuevo PCB
		§ PC tiene el mismo valor que el del padre
		§ Retorno:
			§ El padre recibe el pid del proceso hijo
			§ El hijo recibe 0
			§ El hijo hereda los descriptores de ficheros del padre
	*/

	pid = fork();

	// DEBEMOS CONTROLAR SI EL PROCESO HIJO SE HA CREADO DE FORMA CORRECTA 
   if (pid < 0) {
		printf("Falló la creacion del proceso hijo con fork().\n");
		exit(1);
    } 
    // Si todo ha ido bien y estamos en el proceso HIJO
    else if (pid == 0) {

    	// El PROCESO HIJO tiene que leer la cadena en el pipe_1 y escribir la cadena convertida del pipe_2
    	// Cerramos los extremos que no usa el padre
    	close(pipe_1[1]); // Extremo escritura del pipe_1
    	close(pipe_2[0]);  // Extremo de lectura del pipe_2

    	// Abrimos los dos FILES de cada pipe. El pipe_1 para leer lo que tiene y el pipe_2 para escribir en él despues de convertir el texto en mayúsculas
    	fpipe_1 = fdopen(pipe_1[0], "r");  
    	fpipe_2 = fdopen(pipe_2[1], "w");


    	// Vamos ahora a leer el texto del pipe_1 y lo vamos a "guardar" en el FILE *
		fgets(texto, 1024, fpipe_1);

    	// Cambiamos el texto a mayusculas
		int len = strlen(texto);
		int i;
		for(i = 0; i < len; i++) {
			texto[i] = toupper(texto[i]);
		}

		// Escribimos el texto pasado a mayúsculas en el pipe_2, actualizamos y cerramos el extremo del pipe
		fputs(texto, fpipe_2);
		fflush(fpipe_2);
		close(pipe_2[1]);

    } 
    // Si todo ha ido bien y estamos en el proceso PADRE
    else {

    	// El PROCESO PADRE tiene que escribir la cadena en el pipe_1 y leer la cadena convertida del pipe_2
    	// Cerramos los extremos que no usa el padre
    	close(pipe_1[0]); // Extremo lectura del pipe_1
    	close(pipe_2[1]);  // Extremo de escritura del pipe_2

    	// Vamos ahora a escribir en el pipe_1
    	// Primero se convierte el descriptor en FILE * mediante fdopen(3)
    	// y luego se escribe con fputs y se actualiza con fflush
    	fpipe_1 = fdopen(pipe_1[1], "w");
    	/*
    	int fputs(const char *restrict s, FILE *restrict stream);
    	The function fputs() writes the string pointed to by s to the stream
     	pointed to by stream.
     	*/
     	// Leemos de entrada estandar y guardamos en texto
     	fgets(texto, 1024, stdin);
     	// Metemos lo que hemos guardado en texto en el stream del pipe con fputs
    	fputs(texto, fpipe_1);
    	/*
    	int fflush(FILE *stream);
    	The function fflush() synchronizes the state of the given stream in light of
         buffered I/O.
        */
    	fflush(fpipe_1);

    	// Cerramos el extremo de escritura y esperamos a que el hijo termine
    	close(pipe_1[1]);
		wait(NULL);
		//printf("PADRE: El hijo terminó\n"); 

		// CUANDO EL HIJO TERMINA:
		// Cogemos lo que hay en el FILE * del pipe_2
		// y lo sacamos por la salida estandar fputs in stdout

		// Abrimos el FILE * del segundo pipe para leer lo que haya
		fpipe_2 = fdopen(pipe_2[0], "r");

    	fgets(texto, 1024, fpipe_2);
    	fputs(texto, stdout); 
		close(pipe_2[0]);

    }

}

/*
SYNOPSIS         
	#include <unistd.h>

	ssize_t write(int fd, const void *buf, size_t count);

*/
