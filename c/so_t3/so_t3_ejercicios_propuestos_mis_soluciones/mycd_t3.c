// EJERCICIOS PROPUESTOS - TEMA 3 - MYCD
/*
Escriba un programa en C llamado “mycd” que cambie el directorio actual. Dicho programa debe permitir tanto el acceso mediante 
rutas absolutas como relativas, además de la posibilidad de acceder al directorio especificado en la variable HOME 
si no recibe ningún argumento, escribiendo la ruta absoluta del nuevo directorio actual de trabajo. 

Ejemplo: 
	$ ./mycd /home/user/directorio 
		/home/user/directorio 
	$ ./mycd 
		/home/user/ 
Algunas llamadas al sistema y funciones necesarias: chdir(2), getenv(3), getcwd(3) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int main(int argc, char *argv[]){

	char *dir; 			//Directorio al que vamos a ir
	int change_dir; 	// Variable donde guardamos el resultado de cambiar de dir con chdir
	char buffer[1024]; 	//Necesitamos un buffer de tamaño x (1024) para usar la función getcwd

	printf("NUMERO DE ARGUMENTOS RECIBIDOS: %d \n" ,argc ); // El propio nombre del archivo cuenta cómo uno
	printf( "ESTOY EN: %s\n", getcwd(buffer,-1));

	// Controlar el número de argumentos que nos pasan:
	// Si tenemos más de dos argumentos, no es correcto. Mensaje de error y retorno 1
	if (argc > 2){
		fprintf(stderr,"Uso: %s directorio\n", argv[0]);
	  	return 1;
	}

	// Si tenemos sólo un argumento significa que no tenemos path al que ir. Debemos ir a HOME. Por lo tanto el dir = HOME
	if (argc == 1) 
	{ 
		//printf("HOME : %s\n", getenv("HOME"));
		dir = getenv("HOME"); 
		if(dir == NULL) { //Si no existe la variable de entorno, devuelve un puntero a NULL
			fprintf(stderr,"No existe la variable $HOME\n");	
		}
	}
	// Si tenemos dos argumentos, tenemos path. Por lo tanto, dir = argumento 1
	else
	{
		dir = argv[1];
	}

	// Ya tenemos dir con el path.
	// Tenemos que comprobar que lo que hemos guardado en dir sea un directorio
	// Con chdir cambiamos al directorio que le pasamos, si no puede, devuelve -1 y lo cazamos como error
	change_dir = chdir(dir);
	if (change_dir != 0) {
			fprintf(stderr, "Error al cambiar de directorio: %s\n", strerror(errno)); 
			return 1; 
	}

	// Una vez cambiado al directorio que es, lo mostramos
	printf( "El directorio actual es: %s\n", getcwd(buffer,-1));
	
	return 0;
}

// ./t3_mycd ../../../../test/sandbox
// ./t3_mycd /Users/ana_urjc/Desktop 

/*
char * strerror (int errnum) [Function]
	The strerror function maps the error code (see Section 2.1 [Checking for Errors],
	page 13) specified by the errnum argument to a descriptive error message string. The
	return value is a pointer to this string.
	The value errnum normally comes from the variable errno.
	You should not modify the string returned by strerror. Also, if you make subsequent
	calls to strerror, the string might be overwritten. (But it’s guaranteed that no
	library function ever calls strerror behind your back.)
	The function strerror is declared in string.h.
*/

// FUNCIONES ESPECIALES UTILIZADAS EN ESTA FUNCIÓN
/*
int chdir (const char *filename) [Function]
	This function is used to set the process’s working directory to filename.
	The normal, successful return value from chdir is 0. A value of -1 is returned to
	indicate an error. The errno error conditions defined for this function are the usual
	file name syntax errors (see Section 11.2.3 [File Name Errors], page 225), plus ENOTDIR
	if the file filename is not a directory.

int chdir (const char *filename)
unistd.h (POSIX.1): Section 14.1 [Working Directory], page 343.

*/

/*
char * getenv (const char *name) [Function]
	This function returns a string that is the value of the environment variable name.
	You must not modify this string. In some non-Unix systems not using the GNU C
	Library, it might be overwritten by subsequent calls to getenv (but not by any other
	library function). If the environment variable name is not defined, the value is a null
	pointer.
*/

/*
char * getcwd (char *buffer, size t size) [Function]
	The getcwd function returns an absolute file name representing the current working
	directory, storing it in the character array buffer that you provide. The size argument
	is how you tell the system the allocation size of buffer.
	The GNU C Library version of this function also permits you to specify a null pointer
	for the buffer argument. Then getcwd allocates a buffer automatically, as with malloc
	(see Section 3.2.2 [Unconstrained Allocation], page 33). If the size is greater than zero,
	then the buffer is that large; otherwise, the buffer is as large as necessary to hold the
	result.

	The return value is buffer on success and a null pointer on failure. The following
	errno error conditions are defined for this function:
	EINVAL The size argument is zero and buffer is not a null pointer.
	ERANGE The size argument is less than the length of the working directory name.
	You need to allocate a bigger array and try again.
	EACCES Permission to read or search a component of the file name was denied.
*/