// Control de errores. Ejemplo

#include <stdio.h>
#include <errno.h> //Para errno
#include <string.h> //Para strerror


int main()
{
	FILE * f1;
	f1 = fopen(”file.txt", "r+");
	if(f1 == NULL)
		fprintf(stderr, "Error al abrir el fichero. %s\n“ ,strerror(errno));
	else
		fprintf(f1,”Hola mundo\n");
}