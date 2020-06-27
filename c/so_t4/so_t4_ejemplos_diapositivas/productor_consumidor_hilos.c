#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFF_SIZE 1024
#define TOTAL_DATOS 100000

// VARIABLES GLOBALES
int n_datos; 				/* Datos en el buffer */
int buffer[BUFF_SIZE]; 		/* buffer circular compartido */
pthread_mutex_t mutex; 		/* Acceso a sección crítica */
pthread_cond_t hay_hueco, hay_dato; 	/* Condiciones de espera */

// CABECERAS MÉTODOS
void productor(void);
void consumidor(void);


void main(void) {

	// Variables del main
	// Tengo dos variables de tipo hilo
	pthread_t th1; 
	pthread_t th2;

	/* Situación inicial */

	/* 1) Inicializamos el mutex.
		int pthread_mutex_init (pthread_mutex_t *mutex, pthread_mutexattr_t *attr)
		*mutex: puntero a una variable de tipo mutex
		*attr: atributos del mutex
	*/
	pthread_mutex_init(&mutex, NULL); 

	/* 2) Inicilizamos las condiciones del mutex 
		int pthread_cond_init (pthread_cond_t *cond, pthread_condattr_t *attr)
		*cond: puntero a una variable de tipo condición
		*attr: atributos de la condición
	*/
	pthread_cond_init(&hay_hueco, NULL);
	pthread_cond_init(&hay_dato, NULL);

	// De momento lo que hemos hecho ha sido inicilizar el mutex, que es básicamente decirle la dirección de la variable mutex
	// y hemos inicializado las condiciones de hay_hueco y hay_dato pasandole también la dirección de las variables


	/* Arranque */
	// Creamos los hilos que van a ejecutar las dos funciones: productor y consumidor
	/*
	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
	// pthread_t *thread: &th1 (address of th1)
	// const pthread_attr_t *attr: NULL (Si es NULL se aplican los de por defecto)
	// void *(*start_routine)(void *): productor/consumidor. El hilo se crea ejecutando la función con los argumentos 
	// void *arg: NULL (no le pasamos argumentos)
	*/
	// No sabemos que hilo se va a ejecutar antes ni en que orden
	pthread_create(&th1, NULL, productor, NULL); 
	pthread_create(&th2, NULL, consumidor, NULL);

	/* Esperar terminación */
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	pthread_mutex_destroy(&mutex); /* Destruir */
	pthread_cond_destroy(&hay_hueco);
	pthread_cond_destroy(&hay_dato);
	exit(0);
}


void productor(void) {

	// El th1 va a ejecutar esta función. 
	// El productor está produciendo datos hasta que el buffer esté lleno. 
	// Si el buffer está lleno ha de parar de producir. 
	// Por tanto la CONDICIÓN por la que se rige el PRODUCTOR es:
	// Mientras que el numero

	int i, dato;

	// Vamos a estar produciendo datos hasta que hayamos producido TOTAL_DATOS=100000
	// Pero con la condición de producir siempre que haya sitio para guardar el dato producido
	for(i=0; i < TOTAL_DATOS; i++) {
		
		//Producir el dato

		// Echamos el cerrojo para ejecutar la sección crítica
		pthread_mutex_lock(&mutex);

			// Usamos la condición. Mientras que el numero de datos en el buffer (n_datos) 
			// sea igual que el tamaño del buffer (BUFF_SIZE), significa que está lleno 
			// y no queremos que productor produzca, a si que hacemos un:
			// pthread_cond_wait(&hay_hueco, &mutex)
			/*
			int pthread_cond_wait (pthread_cond_t *cond, pthread_mutex_t *mutex): 
			Sin salir de la sección crítica, libera temporalmente el mutex
			que la protege, para esperar a que se cumpla la condición
			*/

			while(n_datos == BUFF_SIZE){
				// Vamos a esperar (pausar el &mutex) hasta que se de la condición &hay_hueco
				pthread_cond_wait(&hay_hueco, &mutex);
			}

			// Con i%BUFF_SIZE accedo a la posición del array. Al hacer el módulo (resto de la división) conseguimos todas las posiciones del array
			// dato está inicializado por defecto a 0. Metemos ceros en el buffer.
			buffer[i % BUFF_SIZE] = dato;
			// Incrementamos la varialbe n_datos para indicar que hemos metido dato 
			// y mandamos señal al consumidor para despertarle y decirle que hay dato para consumir
			n_datos++;
			// Como hemos producido el dato, mandamos la señal de que hay datos en el buffer para poder ser consumidos
			pthread_cond_signal(&hay_dato);

		// Levantamos el cerrojo
		pthread_mutex_unlock(&mutex);
	}

	// Siempre hemos de terminar un hilo con pthread_exit(res). res si queremos devolver algo.
	pthread_exit(NULL);
}


void consumidor(void) {

	int i, dato;

	// Vamos a estar consumiendo datos hasta que hayamos consumido TOTAL_DATOS=100000
	// pero con la condición de que haya dato que consumir del buffer
	for(i=0; i < TOTAL_DATOS; i++) {

		pthread_mutex_lock(&mutex);

		while(n_datos == 0){
			pthread_cond_wait(&hay_dato, &mutex);
		}

		dato = buffer[i % BUFF_SIZE];
		n_datos--;

		pthread_cond_signal(&hay_hueco);
		pthread_mutex_unlock(&mutex);
		//Consumir el dato
	}

	pthread_exit(NULL);
}