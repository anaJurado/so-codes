// LEER PRIMOS
// Programa que abre un fichero y muestra su contenido por pantalla

#include <stdio.h>

#define input_file "primos_10.txt"

int main(void){
	FILE * fp;  // file pointer
	int i; 		// representa el argumento que vamos a leer (Necesitamos tener un puntero a ese argumento en fscanf)

	// Abrimos el fichero en modo lectura
	fp = fopen(input_file, "r");
	
	// Ahora "escaneamos" el contenido
		// &: devuelve la dirección de memoria donde se encuentra una variable. (Puntero a la variable)
		// Con (f)scanf, a diferencia de printf, hay que pasar punteros a los argumentos para que scanf
		// pueda modificar sus valores. (es decir usar el &)

	while (!feof(fp)){      // mientras no sea final de fichero...
		fscanf(fp, "%d", &i); 	
		printf("%d\n", i); 	// printf: imprime por pantalla
	}

	fclose(fp);

	return 0;
}

//SCANF:  int scanf(const char *format, ...) reads formatted input from stdin

// SCANF PELIGROS
/*
Al igual que pasaba con gets, es muy peligroso usar scanf para leer cadenas, pues scanf no tiene en cuenta la longitud de lo leído y 
admitirá que el usuario escriba más caracteres que lo que el array definido en el programa pueda admitir. 
Como resultado, scanf escribirá los caracteres que ya no quepan en el array definido en otras porciones de memoria 
que pueden contener otros datos que está usando nuestro programa. Esto desembocará en comportamientos anómalos, 
en fugas de memoria, etc. Más tarde veremos cómo poder leer cadenas de caracteres de manera más segura.
*/