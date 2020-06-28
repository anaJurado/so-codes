#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void *th_func1(void *arg)
{
	printf("Hola, soy el thread 1\n");
	sem_wait(&sem);
	printf("Y esto se tiene que imprimir después\n");	

	pthread_exit(0);
}

void *th_func2(void *arg)
{	
	printf("Hola, soy el thread 2\n");	
	printf("Esto se tiene que imprimir primero\n");
	sem_post(&sem);
	
	pthread_exit(0);
}

int main()
{
	pthread_t th1, th2;
	
	sem_init(&sem, 0, 0);
		
	pthread_create(&th1, NULL, th_func1, NULL);
	pthread_create(&th2, NULL, th_func2, NULL);
		
	
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	
	return 0;
}