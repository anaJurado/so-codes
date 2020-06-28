/*
TEMA 4  - EJERCICIOS PROPUESTOS - THREADS (2)

	Escriba un programa en C llamado mut que cree dos threads que accedan simultáneamente a un buffer de 10000 enteros. 
	Uno de ello lee en el buffer y el otro escribe en el mismo. 
	El thread escritor, debe escribir el mismo valor en todos los elementos del buffer incrementando en uno el valor en cada pasada. 
	El thread lector debe ir comprobando que todos los números del buffer son iguales, 
	mostrando un mensaje de error en caso contrario o un mensaje de correcto si la condición se cumple. 
	El código a realizar utilizará un mutex para acceder al buffer si se indica un parámetro al ejecutar el programa. 
	En caso contrario, los threads accederán al buffer de cualquier manera. 
*/

// VERSION QUE SÓLO CONTEMPLA EL MUTEX

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFF_SIZE 100   	// tamaño del buffer


// VARIABLES GLOBALES
int n_datos; 							// numero de datos en el buffer 
int buffer[BUFF_SIZE]; 					// buffer circular compartido de 100 enteros 
pthread_mutex_t mutex; 					// mutex para acceder a la sección crítica 


void *escritor(void *arg){
	printf("ESCRITOR: ");
	printf("%i\n",*((int *)arg));

	int a; // Variable para recorre el buffer
	int contador; // El dato/numero que hay que meter en el buffer es el numero de veces que se ha pasado por aquí

	while(1){
		// HECHAMOS EL CERROJO
		/* Se espera y se bloquea el mutex */
		pthread_mutex_lock (&mutex);

			/* Se cambian todos los valores que hay en el buffer por dato */
			for (a=0; a<BUFF_SIZE; a++)
				buffer[a] = contador;

		// LEVANTAMOS EL CERROJO
		/* Se desbloquea el mutex */
		pthread_mutex_unlock (&mutex);

		contador++;
	}
}

void *lector(void *arg){
	printf("LECTOR: ");
	printf("%i\n",*((int *)arg));


	int b; // Variable para recorre el buffer
	int flag_different_value = 0; // variable que vamos a utilizar como flag en

	while(1){
		// HECHAMOS EL CERROJO
		/* Se espera y se bloquea el mutex */
		pthread_mutex_lock (&mutex);

			// Hay que comprobar que todos los valores del buffer son iguales
			// Comprobamos que todos son iguales al primero
			for (b=1; b<BUFF_SIZE; b++) {
				if (buffer[0] != buffer[b]) {
					flag_different_value = 1;
					break;
				}
			}

			/* Se escribe si se ha encontrado algún elemento distinto */
			if (flag_different_value) {
				printf ("Hijo  : Error. Elementos de buffer distintos\n");
			}
			else {
				printf ("Hijo  : Correcto\n");
			}

			/* Se deja la variable de elementoDistinto a 0 */
			flag_different_value = 0;

		// LEVANTAMOS EL CERROJO
		/* Se desbloquea el mutex */
		pthread_mutex_unlock (&mutex);

	}

}


int main(){

	int dato = 7; 		// El dato que va a ser escrito en el buffer

	int creacion_hilo_1, creacion_hilo_2; 	// Variable para guardar el resultado de la creacion de los hilos

	// Variables del main
	// Tengo dos variables de tipo hilo
	pthread_t th1; 
	pthread_t th2;

	// INICIALIZAMOS MUTEX
	pthread_mutex_init(&mutex, NULL);


	// INICIALIZAMOS HILOS
	creacion_hilo_1 = pthread_create(&th1, NULL, escritor, (void *)&dato); 
	creacion_hilo_2 = pthread_create(&th2, NULL, lector, (void *)&dato);

	printf("MAIN!\n");

	// Controlamos si la creacion de los hilos ha sido correcta
	if (creacion_hilo_1 != 0){
		perror("Error creacion hilo 1\n");
		return 1;
	} else if (creacion_hilo_2 != 0){
		perror("Error creacion hilo 2\n");
		return 1;
	} else { // LOS HILOS SE HAN CREADO BIEN

		while(1){
			// SE EJECUTAN COSAS EN LOS HILOS
		}
		
	}

}
