#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{	
	int i;
	int inicio = 1;
	int fin;
	int incremento = 1;
	
	switch(argc)
	{
		case 2:	fin = atoi(argv[1]);
				break;
		case 3: inicio = atoi(argv[1]);
				fin = atoi(argv[2]);
				break;
		case 4: inicio = atoi(argv[1]);
				incremento = atoi(argv[2]);
				fin = atoi(argv[3]);
				break;
		default:
				printf("Uso:\n%s FIN\n%s INICIO FIN\n%s INICIO INCREMENTO FIN\n", argv[0], argv[0], argv[0]);
				return 1;
	}
	
	for( i = inicio; i <= fin; i = i + incremento)
	  printf("%d\n", i);

	return 0;     
}
