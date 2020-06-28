#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 


int main(int argc, char **argv) {
	
	int pipe_des[2];
	int pid;
	char buf[1024];
	
	FILE *fd; // FILE POINTER 
	
	// Creamos el pipeline
	// pipe() nos devuelve: 0 si todo va bien y -1 si hay algún error
	// En este caso no utilizamos ese output para comprobar si la creación del pipeline ha ido bien o no
	pipe(pipe_des);
	
	// Creamos un nuevo proceso. 
	// pid es el resultado de la creación del proceso hijo. 
				// pid < 0 creación errónea
				// pid = 0, es el proceso hijo
				// pid > 0, es el proceso padre
	pid = fork();

	// Hijo
	if(pid == 0) { 
		//El hijo solo recibe, cierro el pipe[1]
		close(pipe_des[1]); 

		// Tenemos el FILE * con el descriptor del pipe
		fd = fdopen(pipe_des[0], "r"); 
		fgets(buf, 1024, fd);
		fclose(fd);
		printf("Hijo: Recibido el siguiente mensaje: \"%s\"\n ", buf);
	}

	// Padre
	else { 
		//El padre solo envía, cierro el pipe[0]
		close(pipe_des[0]); 

		// Tenemos el FILE * con el descriptor del pipe
		fd = fdopen(pipe_des[1], "w"); 

		// Añadimos al fichero el string 
		fprintf(fd,"Hola hijo");
		
		// Actualiza el estado del stream (en nuestro caso el fichero) con lo que haya cambiado en entrada/salida
		fflush(fd);
		
		fclose(fd);
		
		wait(NULL);
		
		puts("Padre: El hijo terminó");
	}

	exit(0);
}


/* PROGRAM OUTPUT

*/

/* FILE POINTER

File descriptor is an int whereas a FILE * is a file pointer. The main difference is that the latter is buffered while the former is not.

A file pointer (FILE*) typically contains more information about the stream such as current location, end of file marker, errors on the stream etc. 
But a file descriptor is simply a positve integer representing a "file" (which could a pipe, socket or any other stream).

You can get file descriptor from file pointer using fileno():   int fd = fileno(fp);
*/



/*
	 char *
	 fgets(char * restrict str, int size, FILE * restrict stream);

	 DESCRIPTION
	 The fgets() function reads at most one less than the number of characters specified by size
	 from the given stream and stores them in the string str.  Reading stops when a newline char-
	 acter is found, at end-of-file or error.  The newline, if any, is retained.  If any charac-
	 ters are read and there is no error, a `\0' character is appended to end the string.
*/

/*
SYNOPSIS
     #include <stdio.h>

     FILE *
     fopen(const char * restrict path, const char * restrict mode);

 DESCRIPTION
 The fopen() function opens the file whose name is the string pointed to by path and asso-
 ciates a stream with it.

 The argument mode points to a string beginning with one of the following letters:

 ``r''   Open for reading.  The stream is positioned at the beginning of the file.  Fail if
         the file does not exist.

 ``w''   Open for writing.  The stream is positioned at the beginning of the file.  Create the
         file if it does not exist.

 ``a''   Open for writing.  The stream is positioned at the end of the file.  Subsequent
         writes to the file will always end up at the then current end of file, irrespective
         of any intervening fseek(3) or similar.  Create the file if it does not exist.

 An optional ``+'' following ``r'', ``w'', or ``a'' opens the file for both reading and writ-
 ing.  An optional ``x'' following ``w'' or ``w+'' causes the fopen() call to fail if the file
 already exists.  An optional ``e'' following the above causes the fopen() call to set the
 FD_CLOEXEC flag on the underlying file descriptor.
 */


/*
SYNOPSIS
     #include <stdio.h>

     int
     fflush(FILE *stream);

DESCRIPTION
     The function fflush() synchronizes the state of the given stream in light of buffered I/O.
     For output or update streams it writes all buffered data via the stream's underlying write
     function.  For input streams it seeks to the current file position indicator via the stream's
     underlying seek function.  The open status of the stream is unaffected.
*/