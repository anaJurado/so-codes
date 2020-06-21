// GENERA-PRIMOS
// Programa que busca los n_primeros_primos y los guarda en un fichero

#include <stdio.h>

#define n_primeros_primos 100
#define output_file "primos.txt"

// Funcion que nos dice si un número es primo o no.
// primo = 0 es FALSE
// primo = 1 es TRUE
int es_primo(int n){
	int i, j, primo;
	primo = 1; // Por defecto, primo = TRUE
	for (j=2; j<=n/2; j++)
		if (n % j == 0){ 	// si n es divisible entre alguno de sus candidatos j, 
							// entonces primo = FALSE y no hace falta seguir buscando 
			primo = 0; 
			break;
		}
	return primo;
}

int main(void){
	// Necesitamos un descriptor de fichero, que no es más que un puntero a FILE
	// ( FILE es tipo de dato que está incluído en la definición de stdio.h)
	FILE * fp;  // descriptor de fichero (es un entero no negativo)
	int i, n; 	// enteros i y n
	
	// APERTURA DE UN FICHERO:
	// int open (char* name, int flags [, mode_t mode]);
	fp = fopen(output_file, "w");

	// Inicializamos las variables:
	// i irá tomando los valores de todos los números (1,2,3,4,...)
	// n es el contador 
	i = 1;
	n = 0;
	while (n < n_primeros_primos){
		if (es_primo(i)){
			fprintf (fp, "%d\n", i);
			n++;
		}
		i++;
	}
	fclose(fp);

	return 0;
}