/* Ejercicio EE20 */

// VERSION PRODUCTOR / CONSUMIDOR

#include <stdio.h>		//printf
#include <stdlib.h> 	//atoi , rand
#include <errno.h> 		//Para errno
#include <string.h> 	//Para strerror
#include <ctype.h>  	//isDigit
#include <pthread.h>
#include <semaphore.h>

#define BUFF_SIZE 10

int N;							// PARÁMETRO QUE INTRODUCE POR ARG 
int n_datos; 					// Datos en el buffer 
int buffer[BUFF_SIZE]; 			// buffer circular compartido *
int suma_pares, suma_impares; 	// Guardaremos aquí los resultados de la suma

pthread_mutex_t mutex; 			// Acceso a sección crítica 
pthread_cond_t hay_hueco, hay_dato, dato_negativo; 	// Condiciones de espera 


void *suma(void *arg);
int isPositiveNumber(char number[]);


int main(int argc, char *argv[]){

	pthread_t th1;		// hilo
	int i; 				// Variable para bucle crear numeros  random
	int aleatorio;


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

  	

  	// INICIALIZAMOS EL MUTEX
  	/* 1) Inicializamos el mutex.
		int pthread_mutex_init (pthread_mutex_t *mutex, pthread_mutexattr_t *attr)
		*mutex: puntero a una variable de tipo mutex
		*attr: atributos del mutex
	*/
	pthread_mutex_init(&mutex, NULL);

	// INICIALIZAMOS LAS CONDICIONES
	/* 2) Inicilizamos las condiciones del mutex 
		int pthread_cond_init (pthread_cond_t *cond, pthread_condattr_t *attr)
		*cond: puntero a una variable de tipo condición
		*attr: atributos de la condición
	*/
	pthread_cond_init(&hay_hueco, NULL);
	pthread_cond_init(&hay_dato, NULL);


	// CREAMOS HILO
	// Creamos el hilo y le indicamos la función a ejecutar
	pthread_create(&th1, NULL, suma, NULL);


	// PRODUCIMOS NUMEROS RANDOM
	// Vamos a estar produciendo datos hasta que hayamos producido N datos
	// Pero con la condición de producir siempre que haya sitio para guardar el dato producido
	printf("BUFFER: ");
	for(i=0; i < N+1; i++) {

		// Echamos el cerrojo para ejecutar la sección crítica
		pthread_mutex_lock(&mutex);

			// Usamos la condición. Mientras que el numero de datos en el buffer (n_datos) 
			// sea igual que el tamaño del buffer (BUFF_SIZE), significa que está lleno 
			// y no queremos que productor produzca, a si que hacemos un:
			// pthread_cond_wait(&hay_hueco, &mutex)

			while(n_datos == BUFF_SIZE){
				// Vamos a esperar (pausar el &mutex) hasta que se de la condición &hay_hueco
				pthread_cond_wait(&hay_hueco, &mutex);
			}

			// Con i%BUFF_SIZE accedo a la posición del array. Al hacer el módulo (resto de la división) conseguimos todas las posiciones del array
			// dato está inicializado por defecto a 0. Metemos ceros en el buffer.
	
			aleatorio = 1+(int) (10.0*rand()/(RAND_MAX+1.0));
			printf("%i - ", aleatorio);
			buffer[i%BUFF_SIZE] = aleatorio;
			

			// Incrementamos la variable n_datos para indicar que hemos metido dato 
			// y mandamos señal al consumidor para despertarle y decirle que hay dato para consumir
			n_datos++;

			// Como hemos producido el dato, mandamos la señal de que hay datos en el buffer para poder ser consumidos
			pthread_cond_signal(&hay_dato);

		// Levantamos el cerrojo
		pthread_mutex_unlock(&mutex);
	}

	printf("\n");

	// Cuando ya hemos producido N datos random, incluimos el entero negativo en la siguiente posición
	buffer[(i+1)%BUFF_SIZE] = -1;


	pthread_join(th1, NULL);

	pthread_mutex_destroy(&mutex); /* Destruir */
	pthread_cond_destroy(&hay_hueco);
	pthread_cond_destroy(&hay_dato);

	printf("suma_pares = %i\n", suma_pares);
	printf("suma_impares = %i\n", suma_impares);

	return 0;
}

void *suma(void *arg) {


	int k = 0;

	// Vamos a estar consumiendo datos hasta que nos encontremos con un numero negativo
	// pero con la condición de que haya dato que consumir del buffer 

	for (k=0;k<N;k++){
	//while(1){

		//Hechamos el cerrojo para consumir el dato
		pthread_mutex_lock(&mutex);

			// Nos paramos mientras no haya dato que consumir
			while(n_datos == 0){
				pthread_cond_wait(&hay_dato, &mutex);
			}

			//printf("\nNumero aleatorio: %i y k: %i suma_pares: %i , suma_impares: %i\n", buffer[k % BUFF_SIZE], k, suma_pares, suma_impares);


			// CONSUMO EL DATO
			// Necesitamos saber si el numero es negativo
			if (buffer[k % BUFF_SIZE] < 0){
				//printf("dato: %i  y k: %i \n", buffer[k % BUFF_SIZE], k);

				// terminamos la ejecucion del thread
				pthread_exit(NULL);


			} else {

				// Es par
				if ((buffer[k % BUFF_SIZE] % 2)==0){ 
					suma_pares = suma_pares + buffer[k % BUFF_SIZE];
				} else {
					suma_impares = suma_impares + buffer[k % BUFF_SIZE];
				}

				//printf("\nNumero aleatorio: %i y k: %i suma_pares: %i , suma_impares: %i\n", buffer[k % BUFF_SIZE], k, suma_pares, suma_impares);
			}

			// Decremento la variable para indicar que ya he consumido el dato
			n_datos--;

			// Mando la señal de que el dato ha sido consumido y por tanto hay hueco
			pthread_cond_signal(&hay_hueco);

		// Levantamos el cerrojo
		pthread_mutex_unlock(&mutex);

		//k++;
	}
}



int isPositiveNumber(char number[]) {
    int j = 0;
    int result;
    //checking for negative numbers
    if (number[0] == '-') {
        return 1;
    } else if (number[0] == '0') {
    	return 1;
    } else {
	    for (j=0; number[j] != 0; j++) {
	    	if (isdigit(number[j]) == 0) {
	    		return 1;
	    	}
	    }
	}
    return 0;
}
