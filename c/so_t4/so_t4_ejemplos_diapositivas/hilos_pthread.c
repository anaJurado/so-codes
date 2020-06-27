/*
EJEMPLO DIAPOSITIVAS CREACION HILOS CON PTHREAD
Suma de los N primeros números
*/


#include <pthread.h>
#include <stdio.h>

// Variable compartida (global)
int sum = 0;


// FUNCIÓN SUMA
void *suma(void *num) { // hebra

	int limite = *(int *) num;

	for(int i = 0; i <= limite; i++)

	sum += i;
	
	//  Los threads siempre finalizan su ejecución con pthread_exit(void *res)
	// 	Como no necesitamos devolver ningun valor de retorno ponemos NULL
	pthread_exit(NULL);
}

// FUNCIÓN MAIN
int main() {

	pthread_t tid;	// Variable de tipo pthread. Tipo de datos con identificador TID (pthread_t)
	int N = 10;		// Entero N incializado a 10

	// Creamos el hilo
	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
	// pthread_t *thread: &tid (address of tid)
	// const pthread_attr_t *attr: NULL (Si es NULL se aplican los de por defecto)
	// void *(*start_routine)(void *): suma. El hilo se crea ejecutando la función suma con los argumentos 
	// void *arg: &N (address of N)

	pthread_create(&tid, NULL, suma, (void *) &N);

	// JOIN se utiliza para la sincronización
	/*
		Para la sincronización de threads se utiliza
		pthread_join(pthread_t tid,int **res). El thread que la
		llama espera a que finalice la hebra llamada antes de continuar.
		res devuelve el valor de retorno.
	*/
	pthread_join(tid, NULL);

	printf("SUMA = %d\n", sum); //SUMA = suma de los N primeros numeros

	return 0;
}