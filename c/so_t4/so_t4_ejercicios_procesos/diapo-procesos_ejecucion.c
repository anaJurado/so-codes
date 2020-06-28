#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


/*int main() {

	pid_t pid;
	pid = fork();

	if (pid < 0) { 			// Error 
		fprintf(stderr, "Falló el fork()");
		exit(-1);
	}
	else if (pid == 0) { 	// Proceso Hijo 
		printf("Hola, soy el hijo.\n");
		sleep(10);
		exit(0);
	}
	else { 					// Proceso Padre 
		waitpid (pid, NULL, 0);
		printf ("El hijo terminó.\n");
		exit(0);
	}
}*/



int main() {

	pid_t pid;
	pid = fork();
	int status;
	printf("0.STATUS: %d\n", status);

	if (pid < 0) { 					// Error 
		fprintf(stderr, "Falló el fork()");
		exit(-1);
	}
	else if (pid == 0) { 			// Proceso Hijo 
		printf("Hola, soy el hijo.\n");
		printf("1.STATUS: %d\n", status);
		execlp("FD", "ls", "-la", NULL);
		// Si execlp funciona, estas lineas que hay por debajo no se ejecutarán jamás
		//execlp("echo", "echo", "Hola Don Pepito", NULL);
		fprintf(stderr,"Se ha producido un error.\n"); 
		exit(1);
	}
	else { 		
		printf("Hola, soy el padre.\n");
		printf("2.STATUS: %d\n", status);	
		printf("&STATUS: %p\n", &status);				// Proceso Padre 
		wait (&status);
		printf ("El hijo terminó.\n");
		exit(0);
	}
}

//https://stackoverflow.com/questions/24130990/i-used-waitstatus-and-the-value-of-status-is-256-why

/*
CÓMO FUNCIONA EXECLP()

int execlp(const char *file, const char *arg, ...);

Says that execlp ìs a variable argument function. It takes 2 const char *. The rest of the arguments, if any, are the additional arguments to hand over to program we want to run - also char * - all these are C strings (and the last argument must be a NULL pointer)

So, the file argument is the path name of an executable file to be executed. arg is the string we want to appear as argv[0] in the executable. By convention, argv[0] is just the file name of the executable, normally it's set to the same as file.

The ... are now the additional arguments to give to the executable.

Say you run this from a commandline/shell:

$ ls
That'd be execlp("ls", "ls", (char *)NULL); Or if you run

$ ls -l /
That'd be execlp("ls", "ls", "-l", "/", (char *)NULL);

*/