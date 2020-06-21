#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{	
	int i;

	if (argc <= 1) {
	  fprintf(stderr,"Uso: %s frase\n", argv[0]);
	  return 1;
	}


	for(i = argc-1; i>0; i--)
	{
		int j;
		int longitud;
		longitud = strlen(argv[i]);		
		for(j = longitud-1; j >= 0; j--)
		{
			printf("%c", argv[i][j]);
		}
		printf(" ");
	}
	printf("\n");	

	return 0;
}
