/*
TEMA 4  - EJERCICIOS PROPUESTOS - PROCESOS (3)
Escriba un programa en C llamado “aleatorios” que haga lo siguiente: 
- Cree un proceso hijo que será el encargado de generar números aleatorios. 
Este proceso hijo escribirá en un pipe un número aleatorio del 0 al 10 
cada vez que reciba una señal por parte del padre. 

- El proceso padre lee líneas de la entrada estándar y por cada línea que lea solicitará al 
hijo que le envíe un número aleatorio, lo leerá y lo imprimirá en pantalla. 

- Cuando el proceso padre termine de leer líneas de la entrada estándar, enviará una señal 
al hijo para que este termine, y después terminará el padre. 


Ejemplo de ejecución: $ ./aleatorios 
(enter) 
7 
abcdef 
(enter) 
1 
pepe 
6 
(Ctrl+D) (Fin de archivo) 
$ 

Algunas llamadas al sistema y funciones necesarias: 
fork, signal, kill, rand, srand, read, write, close, wait 

*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>


//VARIABLES

int p_pipe[2];  //Para almacenar los descriptores de la tubería

//Manejador de señales del hijo
//SIGUSR1 => generar un numero aleatorio y ponerlo en la tubería
//SIGUSR2 => terminar el proceso hijo
void manejador_hijo(int sig) {

	int num;
	
	// Dependiendo de la señal que nos haya llevado hasta aquí vamos a hacer cosas distintas
	// Si la señal que nos ha traído hasta aquí es (ctrl+c), salimos del programa
	if(sig == SIGUSR2){
		exit(0);
	}
	// Si la señal que nos ha traído hasta aquí ha sido un ENTER, creamos un número random y lo escribimos en el pipe
	else if(sig == SIGUSR1)
	{		
	  //num = rand() % 10;
		num = 1+(int) (10.0*rand()/(RAND_MAX+1.0));
		write(p_pipe[1], &num, sizeof(int));
	}
}

int main() {

	// pid del proceso
 	pid_t pid;
	
	// Lo que leamos por teclado se guardará aquí
	char buf[1024];
	int num;
	
	
	//Activo el manejador del hijo para SIGUSR1 y SIGUSR2
	// Cuando el programa reciba una de estas señales, se ejecutará la función manejador_hijo
	signal(SIGUSR1, manejador_hijo);
	signal(SIGUSR2, manejador_hijo);
	
	// Creamos el pipe
		/*
		int pipe(int filedes[2]): crea una tubería y asigna el
		descriptor de fichero de la entrada a filedes[1] y el
		descriptor de la salida a filedes[0]. 
	*/
	pipe(p_pipe);

	// ESTO NO SÉ PARA QUÉ ES
	srand(time(NULL));  //Inciar el generador de numeros aleatorios con una nueva semilla

	// Creamos un proceso clonando al padre
	pid = fork();
	
	if (pid < 0){
		printf("Falló la creacion del proceso hijo con fork().\n");
		exit(1);
	} else if(pid == 0){  	//Proceso hijo

		close(p_pipe[0]); //Cierro el extremo de lectura de la tubería
		while(1);  //Bucle infinito. El hijo solo hará algo cuando le llegue una señal
	}
	else {  				//Proceso padre

	    close(p_pipe[1]); // cierro el extremo de escritura en el pipe
	    // Este while es para estar leyendo de teclado (stdin) todo el rato hasta que se cumpla que fgets == NULL
	    // La forma de que fgets sea NULL es: end-of-file or error
	    /*
	    RETURN VALUES: Upon successful completion, fgets() and gets() return a pointer to the
     	string.  If end-of-file occurs before any characters are read, they
     	return NULL and the buffer contents remain unchanged.  If an error
     	occurs, they return NULL and the buffer contents are indeterminate.
     	*/

		while(fgets(buf,1024,stdin) != NULL) {			
			//Cada vez que se lee una linea por el teclado se envia una señal al hijo. 
			// Con fgets estás leyendo de teclado hasta que le llega una señal end-of-line (es decir, presionar enter) 
			// Lo que escribamos ahí nos da exactamente lo mismo, usamos fgets para que nos llegue una señal de teclado
			// Con kill mandamos la señal SIGUSR1 al proceso pid (es decir, le decimos al proceso padre que ha llegado una señal)
			// Al comienzo del main indicamos que si llegaba la señal SIGUSR1 ejecutara la función manejador_hilo
			// Por tando hacemos el KILL y de aquí pasamos a manejador hilo
			kill(pid, SIGUSR1);		

			// Leemos del pipe lo que nos llega (el número random creado en el manejador)
			read(p_pipe[0], &num, sizeof(int));
			// Y lo sacamos por pantalla
			printf("%d\n", num);
		}
		
		//Cuando se recibe un EOF (Ctrl+C por el teclado), se sale del bucle y se indica al hijo que termine
		kill(pid, SIGUSR2);
		
		wait(NULL);

		exit(0);
	}
}
