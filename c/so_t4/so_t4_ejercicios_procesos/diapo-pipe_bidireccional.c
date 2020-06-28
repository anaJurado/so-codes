/*
https://www.geeksforgeeks.org/c-program-demonstrate-fork-and-pipe/
C program to demonstrate fork() and pipe()
Write Linux C program to create two processes P1 and P2. 
P1 takes a string and passes it to P2. 
P2 concatenates the received string with another string without using string function  
and sends it back to P1 for printing.
*/

// C program to demonstrate use of fork() and pipe() 
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main() 
{ 
	// We use two pipes 
	// First pipe to send input string from parent 
	// Second pipe to send concatenated string from child 

	// Un pipe tiene dos descriptores de fichero: uno para el extremo de escritura y otro para el extremo de lectura. 
	// Como los descriptores de fichero de UNIX son simplemente enteros, un pipe no es más que un array de dos enteros
	
	// We are managing two pipes
	int fd1[2]; // Used to store two ends of first pipe. ARRAY de dos integers
	int fd2[2]; // Used to store two ends of second pipe. ARRAY de dos integers

	char fixed_str[] = "forgeeks.org";  // string that is going to be concatenated to the input
	char input_str[100];  // input string
	pid_t p;  // p es la variable donde guardamos el identificador de proceso 

	// Each process is named by a process ID number, a value of type pid_t
	// For example pid_t getpid() function returns the process ID of the current process. 
	// Returns a Data Type: pid_t 

	printf("FD1: fd1[1] READING = %d , fd1[0] WRITING = %d\n", fd1[0], fd1[1]);
	printf("FD2: fd1[1] WRITING = %d , fd2[0] READING = %d\n", fd2[0], fd2[1]);

	// Con la función pipe() creamos la conexión entre los extremos
	// es decir, entre dos descriptores de ficheros fd1[0] y fd1[1]
	// pipe() nos devuelve: 0 si todo va bien y -1 si hay algún error

	// Cremos los dos pipelines y comprobamos si ha habido error en la creación (= -1)
	if (pipe(fd1)==-1) 
	{ 
		fprintf(stderr, "Pipe Failed" ); 
		return 1; // Si hay error, salimos del main
	} 
	if (pipe(fd2)==-1) 
	{ 
		fprintf(stderr, "Pipe Failed" ); 
		return 1; // Si hay error, salimos del main
	} 

	// En este punto tenemos los dos pipelines creados

	scanf("%s", input_str); // leemos de teclado la primer parte del string que vamos a construir
	
	// Usamos FORK() para crear un nuevo proceso, el proceso hijo que se ejecuta concurrentemente con el proceso padre 
	// a partir de la siguiente instrucción al fork().
	// El proceso hijo usa el mismo contador de programa, los mismos registros CPU y los mismos ficheros que el proceso padre
	
	p = fork(); // p es el resultado de la creación del proceso hijo. 
				// < 0 creación errónea
				// p = 0, es el proceso hijo
				// p > 0, es el proceso padre


	// Chequeamos que la creación del proceso ha sido correcta
	if (p < 0) 
	{ 
		fprintf(stderr, "fork Failed" ); 
		return 1; // Si hay error, salimos del main
	} 

	// Si estamos en el proceso padre:
	// Parent process 

	/* Comportamiento del padre:
		El proceso padre tiene que escribir en el primer pipeline (fd1) y leer del segundo pipeline(fd2)
	*/
	else if (p > 0) 
	{ 
		// Variable donde vamos a guardar el string completo (el input strin +  fixed string)
		char concat_str[100]; 

		// Close reading end of first pipe. Parent doesn't need to read from pipeline fd1
		close(fd1[0]);  

		// Write input string and close writing end of first pipe. 
		write(fd1[1], input_str, strlen(input_str)+1); 
		close(fd1[1]); 

		// Wait for child to send a string 
		wait(NULL); // Con wait(NULL) esperamos a que un hijo termine (en este ejemplo sólo tenemos uno)

		close(fd2[1]); // Close writing end of second pipe 

		// Read string from child (already concatenated) and prints it
		read(fd2[0], concat_str, 100); 
		printf("Concatenated string %s\n", concat_str); 

		// Close reading end on pipeline 2
		close(fd2[0]); 
	} 

	// Si estamos en el proceso hijo:
	// child process 
	/* Comportamiento del hijo:
		El proceso hijo tiene que leer del primer pipeline (fd1) y escribir en el segundo pipeline(fd2)
	*/
	else
	{ 	
		// Close writing end of first pipe. Child doesn't need to write in pipeline fd1
		close(fd1[1]); 

		// Read a string using first pipe 
		char concat_str[100]; 
		read(fd1[0], concat_str, 100); 

		// Concatenate a fixed string with it 
		int k = strlen(concat_str); 
		int i; 
		for (i=0; i<strlen(fixed_str); i++) 
			concat_str[k++] = fixed_str[i]; 

		concat_str[k] = '\0'; // string ends with '\0' 

		// Close reading end on pipeline 1 (already used, nothing else to do)
		close(fd1[0]); 


		// Vamos a escribir en el segundo pipeline, a si que cerramos primero el extremo de lectura
		close(fd2[0]); 

		// Write concatenated string and close writing end 
		write(fd2[1], concat_str, strlen(concat_str)+1); 
		close(fd2[1]); 

		exit(0); // El proceso hijo ha finalizado
	} 
} 

/* PROGRAM OUTPUT
	MacBook-Pro:ejemplos_diapositivas ana$ ./pipe_bidireccional
	FD1: fd1[1] READING = -465466720 , fd1[0] WRITING = 32766
	FD2: fd1[1] WRITING = 0 , fd2[0] READING = 0
	hello
	Concatenated string helloforgeeks.org
	
	MacBook-Pro:ejemplos_diapositivas ana$ ./pipe_bidireccional
	FD1: fd1[1] READING = -447493472 , fd1[0] WRITING = 32766
	FD2: fd1[1] WRITING = 0 , fd2[0] READING = 0
	holacarcola
	Concatenated string holacarcolaforgeeks.org
*/
