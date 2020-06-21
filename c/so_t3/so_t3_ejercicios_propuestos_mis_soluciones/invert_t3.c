// EJERCICIOS PROPUESTOS - TEMA 3 - INVERT
/*
Programa que muestre todos los argumentos que se le pasan al revés:
	$ ./t3_invert es cara la cacatua
	autacac al arac se
*/
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
	printf("NUMERO DE ARGUMENTOS RECIBIDOS: %d \n" ,argc ); // El propio nombre del archivo cuenta cómo 1
	int i;
	int j;
	char *palabra;

	// Chequeamos que tengamos al menos un argumento al que darle la vuelta
	if (argc > 1) {
		for (i = argc - 1; i > 0; i--){
			//Cogemos los argumentos desde el ultimo al primero y se lo asignamos a palabra
			//printf("%s\n", argv[i]);
			palabra = argv[i];

			// Ya tenemos la palabra a la que hay que dar la vuelta
			
			//printf("PALABRA: %s\n", palabra);
			//printf("Longitud de PALABRA = %ld \n",strlen(palabra));
			for (j=strlen(palabra)-1; j >= 0; j--){  // usamos el int j como indice decremento
				//printf("j: %d\n", j)
				// palabra ha sido declarado como un puntero a un char, pero sabemos que se puede usar como array palabra[j]
				printf("%c", palabra[j]);
			}
			printf(" "); // separamos las palabras con un espacio
		}
		printf("\n"); // Al final de la frase añadimos un salto de linea
	} 
	else {
		printf("Numero de argumentos insuficiente.\n");
				return 1;
	} 

	return 0; 
}
