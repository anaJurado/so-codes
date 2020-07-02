#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>


/*int main(int argc, char *argv[]) {
	
	// pid del proceso
 	pid_t pid;
 	pid_t ppid;

 	printf ( "MAIN Process PID: %d\n", getpid());

 	for (int i=0;i<3;i++){
 		printf ( "i: %d\n", i);
 		printf ( "Process’s PID: %d\n", getpid());
 		printf ( "Parent’s PID: %d\n", getppid());
 		printf ( "FORK\n");
 		pid = fork();
 		printf ( "Parent’s PID: %d\n", getppid());
 		printf ( "Child PID: %d\n", pid);
 		if (pid == 0){
 			printf ( "Child. Exit\n");
 			exit(0);
 		}
 	}

 	printf ( "OUT OF FOR\n");

}*/


/*int main(){
	//execlp("ls", "ls", "-la", NULL);
	execlp("ls", "-la", NULL);
	exit(1);
}*/

int main(){
	int a;
	int * p;
	int v[10];
	
/*	
	v[2] = 0;
	p=&v[2];
	printf("p: %p\n", p);
	*p = 5;
	printf("v[2] = %i\n", v[2]);

*/

/*
	a = 7;
	p = &a;
	printf("p: %p\n", p);

*/

/*
	//a = *p + 1;
	a = *(p + 1);
	printf("a : %i\n", a);
*/

	v[0] = 7;
	p = v;
	printf("p: %p\n", p);
	printf("*p %i\n", *p);

/*
	
*/






}