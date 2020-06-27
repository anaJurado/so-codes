#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

//VARIABLES GLOBALES

//La palabra clave volatile le dice al compilador que el valor de la variable 
//puede cambiar en cualquier momento como resultado de condiciones externas, 
//no solo como resultado del flujo de control del programa
volatile int j = 0;

//Variable de tipo semáforo
sem_t sem;

// FUNCION que va a ser ejecutada con hilos
void *th_func1(void *arg) {
	
	// Varible local a la función
	int i;

	printf("%s va a entrar al for y j vale: %i\n", arg, j);
	for(i = 0; i < 10000; i++) {
		// down
		sem_wait(&sem); //Entrada en la sección crítica

			j = j + 1;
		// up
		sem_post(&sem); //Salida de la sección crítica
	}
	printf("%s se va y j vale: %i\n", arg, j);

	// Los threads siempre finalizan su ejecución con pthread_exit(void *res)
	pthread_exit(NULL);

}



int main() {

	// VARIABLES DEL MAIN

	// Tengo dos hilos
	pthread_t th1;
	pthread_t th2;
	char hilo1[30] = "Soy hilo 1";
	char hilo2[30] = "Soy hilo 2";
	
	// Inicializo el semáforo.
	// Le pasamos la direccion (&) de la variable sem, 
	//el valor al que lo inicializamos (0) 
	//y que se puede heredar en fork (1)
	sem_init(&sem, 0, 1);

	// Creo los hilos:
	// pthread_t *thread: &th1 (address of th1)
	// const pthread_attr_t *attr: NULL (Si es NULL se aplican los atributos por defecto)
	// void *(*start_routine)(void *): th_func1. El hilo se crea ejecutando la función th_func1 con los argumentos 
	// void *arg: NULL (en este caso no le pasamos ningun argumento a la funcion th_func1)
	
	// Creo el hilo 1
	pthread_create(&th1, NULL, th_func1, &hilo1);

	// Creo el hilo 2
	pthread_create(&th2, NULL, th_func1, &hilo2);

	// SINCRONIZAMOS LOS HILOS
	/*
	Para la sincronización de threads se utiliza pthread_join(pthread_t tid,int **res). 
	El thread que la llama espera a que finalice la hebra llamada antes de continuar.
	res devuelve el valor de retorno.
	*/
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	sem_destroy(&sem);
	printf("j = %d\n", j); // j vale 20000
	return 0;
}