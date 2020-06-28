/*
TEMA 4  - EJERCICIOS PROPUESTOS - PROCESOS
	Escriba un programa en C llamado “ejecuta” que reciba como argumentos el comando y las opciones del comando que se quiere ejecutar. 
	El programa debe crear un proceso hijo que ejecute el comando con las opciones correspondientes 
	mostrando un mensaje de error en el caso de que no se realizase correctamente la ejecución. 
	El padre debe esperar a que el hijo termine e informar si se produjo alguna anomalía en la ejecución del hijo. 
	
	Ejemplo de ejecución: 
	$ ./ejecuta echo $HOME 
	/home/user 

	$ ./ejecuta ls –l 
	-rw-r--r-- 1 user users 0 2011-02-17 09:05 a.txt 
	-rw-r--r-- 1 user users 0 2011-02-17 09:05 b.txt 
	-rw-r--r-- 1 user users 0 2011-02-17 09:05 c.txt 

	$ ./ejecuta lss –l 
	Error al ejecutar el comando. No such file or directory 
	El comando no se ejecutó correctamente. 

	Algunas llamadas al sistema y funciones necesarias: fork, execvp, exit, wait, WIFEXITED, WEXITSTATUS 
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv) {
	pid_t  pid;
	int status;		

	// CONTROLAMOS EL NUMERO DE ARGUMENTOS QUE LLEGAN. NECESITAMOS EL COMANDO Y SUS OPCIONES
	if(argc < 2)
	{
		printf("Uso: %s programa argumentos\n", argv[0]);
		return 1;
	}	
	
	// Necesitamos crear un proceso hijo que va a ser el encargado de ejecutar el comando con las opciones	
	pid = fork();

	// CONTROLAMOS SI LA CREACIÓN DEL PROCESO HIJO HA IDO BIEN
	if (pid < 0) { /* Error */
		fprintf(stderr, "Falló el fork().\n%s\n", strerror(errno));
		exit(1);
	}

	// En este punto el proceso hijo se ha creado OK
	// Si pid del proceso es 0, es el proceso hijo
	// HIJO
	else if (pid == 0) { 
		//Ejecuta el programa indicado
		printf ("execvp(argv[1], argv + 1) --> argv[1] = %s y argv + 1 = %s", argv[1], argv + 1 );
		execvp(argv[1], argv + 1);
		//Si llega aquí es que se ha producido un error en el execvp
		printf("Error al ejecutar el comando: %s\n", strerror(errno));
		exit(1);
		
	}
	// Si pid del proceso es distinto de 0, es proceos padre
	else {
		// PADRE
		// Espero a que el proceso hijo termine y guardo en la variable status el resultado de la "terminación" del proceso hijo
		wait (&status);

	 	/* 
    	WIFEXITED(estadoHijo) es 0 si el hijo ha terminado de una manera anormal (caida, matado con un kill, etc). 
		Distinto de 0 si ha terminado porque ha hecho una llamada a la función exit()
    	
    	WEXITSTATUS(estadoHijo) devuelve el valor que ha pasado el hijo a la función exit(), siempre y cuando la 
		macro anterior indique que la salida ha sido por una llamada a exit(). 
		*/
		
		if (WIFEXITED(status) != 0)
			if (WEXITSTATUS(status) != 0)
				printf("El comando no se ejecutó correctamente\n");
		exit(0);
	}
}


/*
EJEMPLO EJECUCIÓN
-- CON EJECUTA.C
MacBook-Pro:so_t4_ejercicios_propuestos_procesos ana$ ./ejecuta ls -l
total 40
-rwxr-xr-x  1 ana  staff  12920 Jun 26 09:18 ejecuta
-rw-r--r--  1 ana  staff   3972 Jun 26 09:18 ejecuta.c

-- MISMO COMANDO EN CONSOLA
MacBook-Pro:so_t4_ejercicios_propuestos_procesos ana$ ls -l
total 40
-rwxr-xr-x  1 ana  staff  12920 Jun 26 09:18 ejecuta
-rw-r--r--  1 ana  staff   3972 Jun 26 09:18 ejecuta.c

*/

/*
COMANDO EXECVP:      
int execvp(const char *file, char *const argv[]);

The initial argument for these functions is the pathname of a file which is to be
executed.

The execv(), execvp(), and execvP() functions provide an array of pointers to null-
terminated strings that represent the argument list available to the new program.
The first argument, by convention, should point to the file name associated with the
file being executed.  The array of pointers must be terminated by a NULL pointer.


exec:
	§ Ejecuta el programa indicado
	§ Asigna un nuevo espacio de memoria al proceso
	§ Se conserva el entorno del proceso y pid, ppid, uid, fd
	§ Los descriptores se ficheros se mantienen
	§ Carga datos iniciales en los segmentos
			§ Rellena el PCB con valores iniciales de los registros y descripción de los
			segmentos
	§ No regresa en caso de éxito
	§ Formas de llamada:
			§ int execv(const char *path, char *const argv[]);

			§ int execvp(const char *file, char *const argv[]): hace funciones de
			busqueda en el path de la shell para encontrar el mandato

			§ int execlp(const char *file, const char *arg, ...): se puede pasar como arg
			una lista de elementos "arg0", ..., "argn" acabados en NULL

*/

