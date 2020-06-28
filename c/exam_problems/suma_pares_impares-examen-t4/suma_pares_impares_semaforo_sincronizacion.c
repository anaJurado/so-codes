/* Ejercicio EE20 */

// VERSION SEMAFORO SEÑALES (QUE SE HACE ANTES Y QUÉ DESPUÉS)

/*
parallels@parallels-Parallels-Virtual-Platform:/media/psf/Home/SO/so-codes/c/so_t4/so_t4_ejercicios_examen$ ./pi 23
BUFFER: 1 / 3 / 2 / 6 / -1 / 10 / 7 / 8 / 2 / 7 / 
Msuma_pares = 8
suma_impares = 4

parallels@parallels-Parallels-Virtual-Platform:/media/psf/Home/SO/so-codes/c/so_t4/so_t4_ejercicios_examen$ ./pi 14
BUFFER: 5 / 7 / 4 / 6 / 10 / -1 / 4 / 8 / 3 / 6 / 
Msuma_pares = 20
suma_impares = 12
*/

#include <stdio.h>	//printf
#include <stdlib.h> //atoi , rand
#include <errno.h> 	//Para errno
#include <string.h> //Para strerror
#include <ctype.h>  //isDigit
#include <pthread.h>
#include <semaphore.h>


#define BUFFER_SIZE 10

// VARIABLES GLOBALES
int N;
int buffer[BUFFER_SIZE];  // Las variables globales se inicializan por defecto a cero
sem_t sem;

int resultado[2]; // En este array de enteros voy a guardar suma_pares y suma_impares

// Función axuliar para comprobar si un argumento es entero positivo > 1
int isPositiveNumber(char number[]);
void *suma(void *arg);


int main(int argc, char *argv[]){

	pthread_t th1;
	int i; // Variable para bucle de los random

	// Controlamos el numero de parámetros que nos llegan y el tipo de parámetro
	if (argc != 2){
		fprintf(stderr, "Error %s. Numero de parámetros erróneo. Recibidos: %i. Requeridos: 1\n", strerror(errno), (argc-1));
	  	return 1;
	} else if (isPositiveNumber(argv[1]) != 0) {
		fprintf(stderr, "Error %s. El argumento %s no es válido. Introduzca un número entero positivo\n" , strerror(errno), argv[1]);
		return 2;
  	} else {
  		N = atoi(argv[1]);
  	}

  	// En este punto sabemos que tenemos N como tipo entero y es > 0

  	// Inicializamos el semáforo
  	sem_init(&sem, 0, 0);

  	// Creamos el hilo y le indicamos la función a ejecutar
	pthread_create(&th1, NULL, suma, NULL);
	

	// CREAMOS LOS N NUMEROS ALEATORIOS Y LOS INTRODUCIMOS EN EL BUFFER
	for (i=0;i<N;i++){
		buffer[i%BUFFER_SIZE]= 1+(int) (10.0*rand()/(RAND_MAX+1.0));
	}
	buffer[(i+1)%BUFFER_SIZE] = -1;

		//PINTAR BUFFER
		int j;
		printf("BUFFER: ");
		for (j=0;j<BUFFER_SIZE;j++){
			printf("%i / ",buffer[j]);
		}
		printf("\n");

	sem_post(&sem);

	// El thread que la llama espera a que finalice la hebra llamada antes de continuar.
	// res devuelve el valor de retorno.

	pthread_join(th1, NULL);
	sem_destroy(&sem);

	printf("suma_pares = %i\n", resultado[0]);
	printf("suma_impares = %i\n", resultado[1]);

	
	return 0;

}

void *suma(void *arg) {

	int suma_pares = 0;
	int suma_impares = 0;
	int k;

	// Como queremos que este se ejecute después de tener los numeros aleatorios en el buffer, lo primero que hacemos es un WAIT.
	// Hasta que alguien no le despierte, este no se va a ejecutar.
	sem_wait(&sem);

	for (k=0;k<BUFFER_SIZE;k++){

		// Necesitamos saber si el numero es -1par o impar
		if (buffer[k] < 0){
			// terminamos la ejecucion del thread
			resultado[0] = suma_pares;
			resultado[1] = suma_impares;

			pthread_exit(0);

		} else if ((buffer[k] % 2)==0){ // Es par
			suma_pares = suma_pares + buffer[k];
		} else {
			suma_impares = suma_impares + buffer[k];
		}
	}
}


int isPositiveNumber(char number[]) {
    int i = 0;
    int result;
    //checking for negative numbers
    if (number[0] == '-') {
        return 1;
    } else if (number[0] == '0') {
    	return 1;
    } else {
	    for (i=0; number[i] != 0; i++) {
	    	if (isdigit(number[i]) == 0) {
	    		return 1;
	    	}
	    }
	}
    return 0;
}
