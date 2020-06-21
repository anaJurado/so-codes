// EJERCICIOS PROPUESTOS - TEMA 3 - MYHEAD
/*
Escriba un programa en C llamado “myhead” que se comporte como head(1) leyendo de la entrada estándar, 
es decir, que muestra las 10 primeras líneas recibidas por la entrada estándar, 
o las N primeras si se llama al programa con “myhead N”. 
Se debe usar la función fgets(3) pasándole como tercer argumento la constante stdin, de una forma similar a: 
char buf[1024]; 
fgets(buf, 1024, stdin);
*/

// VERSIÓN PROFE
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{	
	// VARIABLES


	int lineas;			// variable tipo entero llamado lineas. Número de líneas que hay que mostrar
	char buf[1024];		// variable tipo array de chars con 1024 posiciones llamado buf
  	int cuenta = 0;		// variable tipo entero llamado cuenta inicializado a 0
	
	// CONTROLAMOS EL NUMERO DE ARGUMENTOS QUE LLEGAN 

	// Si no so se especifica en la llamada el numero de líneas, por defecto vamos a mostrar 10
	if(argc == 1)
	{
		lineas = 10;
	}
	// Si se especifica el numero de líneas que hay que mostrar
	else if (argc == 2)
	{	
		lineas = atoi(argv[1]); 	// Convertimos el character que nos ha llegado por parametro en integer 
									//y lo usamos como limite superior
	}
	// El numero de argumentos es incorrecto
	else
	{
		printf("Uso: \"%s -N\" para ver las N primeras líneas, o \"%s\" para las 10 primeras líneas\n", argv[0], argv[0]);
		return 1;
	}
	
  	// Mientras que cuenta no llegue a ser igual que el limite superior 
  	// y fgets coja lineas de la entrada estándar...
	while((cuenta < lineas) && (fgets(buf, 1024, stdin) != NULL))
	{
		printf("%s", buf); // Imprimimos lo que se guarda en buf
		cuenta++;
	}
	
	return 0;	
}


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
