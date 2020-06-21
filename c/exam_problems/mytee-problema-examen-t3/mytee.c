/*
Escriba un programa en C llamado mytee que se comoporte como tee. Se realizarán dos versiones del mismo
a) la primera versión estará formada por un único proceos que hará todo el trabajo
b) la segunda versión estará formada por un proceso que creará dos hijos, con lo que se comunicará a través de sentas tuberías.
El proceso padre se encargará de leer de la entrada estándar, y a través de la tubería 1 enviará las líneas que lea al hijo 1, 
que las escribirá por pantalla. El proceso padre también enviará a través de la tubería 2 las líneas de entrada al hijo 2, 
que las escribirá en el fichero.
*/

#include <stdio.h>
#include <string.h>

// VERSIÓN A
int main(int argc, char *argv[]) {

	// VARIABLES
	char buf[1024];  	// variable tipo array de chars con 1024 posiciones llamado buf
	FILE * fs; 			// Variable de tipo puntero a fichero 	
	char *salida;

	// CONTROLAR NUMERO DE PARAMETROS
	if (argc < 2 || argc > 2){
		printf("ERROR. El script %s necesita un único parametro (nombre fichero salida)\n", argv[0]);
		return 1;
	}

	else {

		char *salida = argv[1]; 
		// El parametro introducido lo tenemos controlado ahora con el puntero a char salida

		// CONTROLAR EL TIPO DE PARAMETRO QUE LE PASAS
		// En este caso vale cualquier cosa que pongas detrás. Será el nombre del archivo.

		// NOTA:
		// Cada vez que se ejecuta el comando tee se crea el fichero y si ya existía se trunca.
		// Vamos a abrir el fichero con fopen

		if ((fs = fopen(salida,"w")) == NULL){
			fprintf(stderr,"ERROR. Error al abrir el archivo %s.", salida);
			fclose(fs);
			return 1;
		} else {  // Hemos abierto el fichero y todo ha ido bien

			// Ahora leemos de teclado con la función fgets
			// Mientras que no tecleemos CTRL+D estaremos leyendo de teclado (stdin)
			// while (fgets(buffer,LONBUFFER,fe) != NULL) /* Lee una línea */
			// char* fgets(char* cad, int n, FILE *pf );
			while (fgets(buf, 1024, stdin) != NULL) {  // Lee una línea de teclado (stdin)

				// Tenemos que hacer dos cosas con la línea que hemos leído
				//1.-imprimirla por pantalla
				printf("%s", buf);
				//2.-escribirla en el fichero que hemos creado antes
				// int fputs (const char *cad, FILE *pf);
				fputs(buf,fs);
			}
			fclose(fs);
			return 0;
		}
	}
}


/*
fopen()
SYNOPSIS
     #include <stdio.h>

     FILE *
     fopen(const char * restrict path, const char * restrict mode);
DESCRIPTION
     The fopen() function opens the file whose name is the string pointed to by path and associates a stream with it.

     The argument mode points to a string beginning with one of the following letters:

     ``r''   Open for reading.  The stream is positioned at the beginning of the file.  Fail if the file does not exist.

     ``w''   Open for writing.  The stream is positioned at the beginning of the file.  Create the file if it does not exist.

     ``a''   Open for writing.  The stream is positioned at the end of the file.  Subsequent writes to the file will always end up at the then current
             end of file, irrespective of any intervening fseek(3) or similar.  Create the file if it does not exist.
RETURN VALUES
     Upon successful completion fopen(), fdopen(), freopen() and fmemopen() return a FILE pointer.  Otherwise, NULL is returned and the global vari-
     able errno is set to indicate the error.
*/

/*
fgets()
SYNOPSIS
     #include <stdio.h>

     char *
     fgets(char * restrict str, int size, FILE * restrict stream);

DESCRIPTION
     The fgets() function reads at most one less than the number of characters specified
     by size from the given stream and stores them in the string str.  Reading stops when
     a newline character is found, at end-of-file or error.  The newline, if any, is
     retained.  If any characters are read and there is no error, a `\0' character is
     appended to end the string.

RETURN VALUES
     Upon successful completion, fgets() and gets() return a pointer to the string.  If
     end-of-file occurs before any characters are read, they return NULL and the buffer
     contents remain unchanged.  If an error occurs, they return NULL and the buffer con-
     tents are indeterminate.  The fgets() and gets() functions do not distinguish
     between end-of-file and error, and callers must use feof(3) and ferror(3) to deter-
     mine which occurred.
*/

/*
fputs()
SYNOPSIS
     #include <stdio.h>

     int
     fputs(const char *restrict s, FILE *restrict stream);

DESCRIPTION
     The function fputs() writes the string pointed to by s to the stream pointed to by stream.

RETURN VALUES
     The functions fputs() and puts() return a nonnegative integer on success and EOF on error.
*/