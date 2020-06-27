/*
TEMA 4  - EJERCICIOS PROPUESTOS - THREADS (1)

Escriba un programa en C llamado que cree dos threads y mediante el uso de un 
semáforo se fuerce que siempre uno de ellos escriba por pantalla antes que el otro.
*/

// PROBLEMA DE SINCRONIZACION DE HILOS CON SEMÁFORO

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

//Variable de tipo semáforo
sem_t sem;


// FUNCION que va a ser ejecutada con por el hilo 1
void *th_func1(void *arg) {

	printf("Soy el hilo 1\n");

	printf("Esto se tiene que imprimir primero\n");

	// Una veza que ya he hecho lo que quería aquí, mando la señal de post al semaforo
	sem_post(&sem);

	pthread_exit(0);


}

// FUNCION que va a ser ejecutada con por el hilo 2
void *th_func2(void *arg) {

	printf("Soy el hilo 2\n");

	// Como queremos que este se ejecute después, a si que lo primero que hacemos es un WAIT.
	// Hasta que alguien no le despierte, este no se va a ejecutar
	// down
	sem_wait(&sem);

	// Cuando llegue la señal de POST al semáforo esto se levantará y se imprimirá el mensaje
	printf("Y esto se tiene que imprimir después\n");	

	pthread_exit(0);

}


int main(){

	pthread_t th1, th2;

	// CUANDO QUEREMOS USAR SEMAFOROS PARA SINCRONIZAR, SIEMPRE SE INICIALIZAN A CERO
	// ¿A qué inicializamos el semáforo? 
	// Le pasamos la direccion (&) de la variable sem, 
	// el valor al que lo inicializamos (0) 
	// y que no se puede heredar en fork (0)
	sem_init(&sem, 0, 0);

	// Creamos los hilos y les indicamos a cada uno que función deben ejecutar
	// NO SABEMOS EN QUE ORDEN VAN A CREARSE Y A EMPEZAR A FUNCIONAR
	pthread_create(&th1, NULL, th_func1, NULL);
	pthread_create(&th2, NULL, th_func2, NULL);

	// JOIN se utiliza para la sincronización
	/*
		Para la sincronización de threads se utiliza
		pthread_join(pthread_t tid,int **res). El thread que la
		llama espera a que finalice la hebra llamada antes de continuar.
		res devuelve el valor de retorno.
	*/
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	
	return 0;
}