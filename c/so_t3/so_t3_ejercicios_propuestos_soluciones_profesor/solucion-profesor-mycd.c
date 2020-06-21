#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	char *dir;
	char buffer[512];
	
	if(argc > 2)
	{
	  fprintf(stderr,"Uso: %s directorio\n", argv[0]);
	  return 1;
	}
	
	if (argc == 1)
	{
		dir = getenv("HOME");
		if(dir == NULL)
		{
		  fprintf(stderr,"No existe la variable $HOME\n");	
		}
	}
	else 
	{
		dir = argv[1];
	}
	
	// Comprobar si es un directorio
	if (chdir(dir) != 0) {
			fprintf(stderr,"Error al cambiar de directorio: %s\n", strerror(errno));  
	}
	printf( "El directorio actual es: %s\n", getcwd(buffer,-1));

	return 0;
}
