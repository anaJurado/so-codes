#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

//  Ejemplo: Pipes con descriptores de fichero
int main(int argc, char **argv) {
	
	int pipe_des[2]; // Descriptores de ficheros para los dos extremos del pipe
	pid_t pid; 		 // Identificador de proceso (aquí vamos a guardar lo que nos devuelve fork())
	char buf[1024];  // Buffer de characters de tamaño 1024 chars
	

	// Creamos el pipeline
	// pipe() nos devuelve: 0 si todo va bien y -1 si hay algún error
	// En este caso no utilizamos ese output para comprobar si la creación del pipeline ha ido bien o no
	pipe(pipe_des);		
	
	// Creamos un nuevo proceso. 
	// pid es el resultado de la creación del proceso hijo. 
				// pid < 0 creación errónea
				// pid = 0, es el proceso hijo
				// pid > 0, es el proceso padre
	pid = fork();
	// En el momento en el que hacemos fork(), el proceso padre y el proceso hijo se ejecutan concurrentement a partir de la instrucción siguiente

	// Hijo
	if(pid == 0) { 
		puts("Hijo: Hola, soy el hijo");
		//El hijo solo recibe, cierro el pipe[1] (el pipe[1] es el de escritura)
		close(pipe_des[1]); 
		// Leemos del pipe
		puts("Hijo: Leo del pipe y lo guardo en buf");
		read(pipe_des[0], buf, 1024);
		// Cerramos el extremo de lectura
		close(pipe_des[0]);
		// Printamos el mensaje leído en el pipe
		printf("Hijo: Recibido el siguiente mensaje: \"%s\"\n", buf);
	}

	// Padre
	else { 
		puts("Padre: Hola, soy el padre");
		//El padre solo envía, cierro el pipe[0] (el pipe[0] es el de lectura)
		close(pipe_des[0]); 
		// Escribimos en el pipe
		puts("Padre: Escribo en el pipe:  Hola hijo");
		write(pipe_des[1], "Hola hijo", 10);
		// Cierra el pipe de escritura
		close(pipe_des[1]);
		puts("Padre: Cierro extremo de escritura y me quedo a la espera de que hijo termine");
		// Esperamos a que el hijo termine
		wait(NULL);

		puts("Padre: El hijo terminó");
	}

	exit(0);
}

/*
PROGRAM OUTPUT
➜  T4 git:(studying_t4) ✗ ./pipes2                              
	Padre: Hola, soy el padre
	Hijo: Hola, soy el hijo
	Hijo: Recibido el siguiente mensaje: "Hola hijo"
	Padre: El hijo terminó
*/
