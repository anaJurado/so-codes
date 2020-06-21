/* TEMA 3 - EJERCICIOS PROPUESTOS - MY SEQ
* Escriba un programa en C que haga lo mismo que el comando seq(1) sin opciones.
* Sólo tiene que entender:
*		myseq LAST
*		myseq FIRST LAST
*		myseq FIRST INCREMENT LAST
* Utilice atoi(3) para convertir un strun que representa un número entero a su valor entero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{	
	printf("NUMERO DE ARGUMENTOS RECIBIDOS: %d \n" ,argc ); // El propio myseq cuenta cómo 1
	int i;

	int inicio = 1;
	int incremento = 1;
	int fin;
	
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

// Ejecución: ./myseq 1 3 9