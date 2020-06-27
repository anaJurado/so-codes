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
sem_t sem_1; 	//El semaforo 1 se va a encargar de los dos primeros mensajes (1,2)
sem_t sem_2;	//El semaforo 2 se va a encargar del mensaje (3)
sem_t sem_3;	//El semaforo 3 se va a encargar del mensaje (4)


// FUNCION que va a ser ejecutada con por el hilo 1
void *th_func1(void *arg) {

	printf("Soy el hilo 1\n");

	printf("1.- Esto se tiene que imprimir primero \n");
	// Una veza que ya he hecho lo que quería aquí, mando la señal de post al semaforo
	sem_post(&sem_1);

	sem_wait(&sem_2);
	printf("3.- Y esto se tiene que imprimir después DEL DESPUÉS\n");
	sem_post(&sem_3);

	pthread_exit(0);


}

// FUNCION que va a ser ejecutada con por el hilo 2
void *th_func2(void *arg) {

	printf("Soy el hilo 2\n");

	// Como queremos que este se ejecute después, a si que lo primero que hacemos es un WAIT.
	// Hasta que alguien no le despierte, este no se va a ejecutar
	// down
	sem_wait(&sem_1);
	// Cuando llegue la señal de POST al semáforo esto se levantará y se imprimirá el mensaje
	printf("2.- Y esto se tiene que imprimir después\n");

	// Lanzo la señal a sem 2 de que puede ir
	sem_post(&sem_2);	

	sem_wait(&sem_3);
	printf("4.- Y por último se imprime esto\n");

	pthread_exit(0);

}


int main(){

	pthread_t th1, th2;

	// CUANDO QUEREMOS USAR SEMAFOROS PARA SINCRONIZAR, SIEMPRE SE INICIALIZAN A CERO
	// ¿A qué inicializamos el semáforo? 
	// Le pasamos la direccion (&) de la variable sem, 
	// el valor al que lo inicializamos (0) 
	// y que no se puede heredar en fork (0)
	sem_init(&sem_1, 0, 0);
	sem_init(&sem_2, 0, 0);
	sem_init(&sem_3, 0, 0);

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

/*

Ejemplo de ejecución: 

parallels@parallels-Parallels-Virtual-Platform:/media/psf/Home/SO/so-codes/c/so_t4/so_t4_ejercicios_propuestos_threads$ ./2h3s
Soy el hilo 2
Soy el hilo 1
1.- Esto se tiene que imprimir primero 
2.- Y esto se tiene que imprimir después
3.- Y esto se tiene que imprimir después DEL DESPUÉS
4.- Y por último se imprime esto

parallels@parallels-Parallels-Virtual-Platform:/media/psf/Home/SO/so-codes/c/so_t4/so_t4_ejercicios_propuestos_threads$ ./2h3s
Soy el hilo 2
Soy el hilo 1
1.- Esto se tiene que imprimir primero 
2.- Y esto se tiene que imprimir después
3.- Y esto se tiene que imprimir después DEL DESPUÉS
4.- Y por último se imprime esto

*/


