// SO - PRÁCTICA 2 - myshell.c
/********************************************************
 * NOMBRE DEL FICHERO: myshell.c 					   	
 * 													   	
 * PROPÓSITO: Implementar la funcionalidad de una shell 
 * 														
 * AUTOR: Ana Jurado Crespo								
 * CREADO: Dec.2019							  			
 ********************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "parser.h"
#include <string.h>

// FUNCIONES
int exec_one_command(tline *line, char *buffer);
int input_output(tline *line, int changeInpunt, int changeOutput, int changeOutputError);
int exec_commands(tline *line, char *buffer);
int signal_control(int process);
int command_cd(int argc, char *argv[]);

// MAIN
int main(void) {

	char buf[1024]; 	// Buffer chars de lectura del input por teclado
	tline * line;  		// Puntero a variable tipo tline

	printf("msh> ");  	// Simbolo prompt

	signal_control(0);  // Desactivamos el control de señales por defecto en el programa principal myshell

	// Mientras tengamos un input...
	while (fgets(buf, 1024, stdin)) { 

		line = tokenize(buf);	// linea introducida en el "shell"
		
		if (line==NULL) {
			continue;
		}

		// Debemos comprobar el número de comandos ya que en caso de ser un único comando
		// es imprescindible diferenciar los comandos exit y cd del resto
		// Linea introducida en shell tiene un comando
		if(line->ncommands == 1){		// Linea introducida en shell tiene un comando
			if(strcmp(line->commands[0].argv[0], "exit") == 0){		// Comando exit
				return 0;
			} else if(strcmp(line->commands[0].argv[0], "cd") == 0){	// Comando cd
				command_cd(line->commands[0].argc, line->commands[0].argv);
			} else {
				exec_one_command(line, buf);		// Ejecutar un único comando
			}
		} else { 	// Linea introducida en shell tiene varios comandos
			exec_commands(line, buf); 	//Ejecutar varios comandos
		}

		printf("msh> "); 	// Al acabar de ejecutar un mandato debemos imprimir de nuevo el simbolo del prompt
	}

	return 0;

} // end of main


/*
 * Funcion: exec_one_command
 * --------------------
 * Ejecuta un único comando
 *      line:	 puntero a línea de char introducidos en shell
 *		buffer:  
 *
 * Devuelve: 
 * 		output != 0:	Error en la ejecución
 * 		output =  0:	Ejecución correcta
 */
int exec_one_command(tline *line, char *buffer){ // Ejecucion de un solo comando 
	int status;
	int child = fork(); 	// Creamos child 

	if(child < 0){ 		// Error creación proceso child 
		fprintf(stderr, "Error en el proceso hijo \n");
		return -1;
	}

	if(child == 0){		 // Si es el proceso child
		// Activamos las señales por defecto
		signal_control(1);

		// Debemos comprobar si hay redireccion e/s
		input_output(line, 1, 1, 1);
		// Ejecutamos el comando 
		execvp(line->commands[0].argv[0], line->commands[0].argv); 
		// Si execvp da error se procede a ejecutar la siguiente línea
		fprintf(stderr, "%s: No se encuentra el mandato \n", line->commands[0].argv[0]);
		exit(1);
	} else {
		wait(&status); 	// Comando en primer plano
	}

	return 0;
}


/*
 * Funcion: input_output
 * --------------------
 * Redirige la entrada desde fichero y la salida hacia fichero
 *      file:	 puntero a fichero de redirección 
 *
 * Devuelve: 
 * 		output != 0:	Error en la ejecución
 * 		output =  0:	Ejecución correcta
 */
int input_output(tline *line, int changeInpunt, int changeOutput, int changeOutputError){

	FILE* file; 

	// Si hay redirección de entrada
	if (line->redirect_input != NULL && changeInpunt) {
		// Abrimos un fichero o si no existe lo creamos en modo lectura
		file = fopen(line->redirect_input, "r");	// Fichero entrada

		// Comprobamos si existe el fichero
		if(file == NULL){
			fprintf(stderr, "%s: Error. No se encuentra el fichero \n", line->redirect_input);
		}

		// Hacemos una copia de file en stdin y cerramos el fichero de entrada
		dup2(fileno(file), fileno(stdin));		// Entrada se pasa por fichero
		fclose(file);
	}

	// Si hay redirección de salida
	if (line->redirect_output != NULL && changeOutput) {
		// Abrimos un fichero o si no existe lo creamos en modo escritura
		file = fopen(line->redirect_output, "w");	// Fichero de salida

		// Comprobamos si existe el fichero
		if(file == NULL){
			fprintf(stderr, "%s: Error. No se pudo escribir en el fichero \n", line->redirect_output);
		}

		// Hacemos una copia de file en stdout y cerramos el fichero de salida
		dup2(fileno(file), fileno(stdout)); 	// Salida se pasa al fichero
		fclose(file);
	}

	// Si hay redirección de salida error
	if (line->redirect_error != NULL && changeOutputError) {
		// Abrimos un fichero o si no existe lo creamos en modo escritura
		file = fopen(line->redirect_error, "w");    // Fichero salida error

		// Comprobamos si existe el fichero
		if(file == NULL){
			fprintf(stderr, "%s: Error. No se pudo escribir en el fichero \n", line->redirect_error);
		}

		// Hacemos una copia de file en stdout y cerramos el fichero de salida de errores
		dup2(fileno(file), fileno(stderr)); // Salida de erros se pasa al fichero
		fclose(file);
	}

	return 0;
}


/*
 * Funcion: exec_commands
 * --------------------
 * Ejecuta un varios comandos
 *		status: 
 *      **p:
 *		i,j: 
 *
 * Devuelve: 
 * 		output != 0:	Error en la ejecución
 * 		output =  0:	Ejecución correcta
 */
int exec_commands(tline *line, char *buffer){ 
	
	int status;
	int **p; 
	int i, j;

	// Reservamos un bloque de espacio de memoria para los pipes
	p = (int**) malloc((line->ncommands-1)*sizeof(int*)); 

	// Reservamos memoria por cada pipe de la linea
	for(i=0; i<line->ncommands - 1; i++){
		p[i]= (int*) malloc (2*sizeof(int)); 
		pipe(p[i]);
	}

	// Recorremos todos los comandos.
	for (i=0; i<line->ncommands; i++) {	
		int child = fork();  	// Para cada comando creamos un proceso hijo

		if(child < 0){ 			// Error creación proceso hijo
			fprintf(stderr, "Error en el proceso hijo \n");
			return -1;
		}

		// Si estamos en un proceso hijo
		if(child == 0){
			signal_control(1);

			// Movemos los descriptores de entrada y salida para concatenar comandos
			// Los comando están representados por la variable i procedente del for
			if (i==0) {
				input_output(line, 1, 0, 0);
				dup2(p[i][1], STDOUT_FILENO);
			} else if (i==line->ncommands-1) {
				input_output(line, 0, 1, 1);
				dup2(p[i-1][0], STDIN_FILENO);
			} else {
				dup2(p[i-1][0], STDIN_FILENO);
				dup2(p[i][1], STDOUT_FILENO);
			}

			// Cerramos tuberías
			for (j = 0; j < line->ncommands-1; j++) { 
				close(p[j][0]);
				close(p[j][1]);
			}

			execvp(line->commands[i].argv[0], line->commands[i].argv); 
			// Si execvp da error se procede a ejecutar la siguiente línea
			fprintf(stderr, "%s: No se encuentra el mandato \n", line->commands[i].argv[0]);
			exit(1);
		}
	}

	// Es necesario ir cerrando todas las tuberías
	for (i = 0; i < line->ncommands - 1; i++) { 
		close(p[i][0]);
		close(p[i][1]);
		free(p[i]); 	// Liberamos cada pipe
	}

	free(p); // Liberamos el bloque de espacio de memoria reservado para los pipes


	for (i = 0; i < line->ncommands; i++) {
		wait(&status); 		// Esperar comando 
	}

	return 0;
}


/*
 * Funcion: signal_control
 * --------------------
 * Controla las señales SIGINT y SIGQUIT por defecto
 *		process: Proceso a controlar
 */
int signal_control(int process){
	//Desabilitar señales control c y control q al proceso
	if(process == 0){ 	
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	} 
	//Habilitar señales control c y control q al proceso 
	else { 			
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}


/*
 * Funcion: command_cd
 * --------------------
 * Ejecuta el comando cd
 *		argc: numero de argumentos
 *		*argv []: puntero a array de argumentos
 */
int command_cd(int argc, char *argv[]){ 

	char *dir; 			//Directorio al que vamos a ir
	int change_dir; 	// Variable donde guardamos el resultado de cambiar de dir con chdir

	// Contemplamos los distintos casos en función del número de argumentos 
	// y si es HOME o no.
	// Controlar el número de argumentos que nos pasan:
	// Si tenemos más de dos argumentos, no es correcto. Mensaje de error y retorno 1
	if (argc > 2){
		fprintf(stderr,"Uso: %s directorio\n", argv[0]);
	  	return 1;
	}

	// Si tenemos sólo un argumento significa que no tenemos path al que ir. Debemos ir a HOME. Por lo tanto el dir = HOME
	if (argc == 1) 
	{ 
		dir = getenv("HOME"); 
		if(dir == NULL) { //Si no existe la variable de entorno, devuelve un puntero a NULL
			fprintf(stderr,"No existe la variable $HOME\n");	
		}
	}

	// Si tenemos dos argumentos, tenemos path. Por lo tanto, dir = argumento
	else
	{
		dir = argv[1];
	}

	// Ya tenemos dir con el path.
	// Tenemos que comprobar que lo que hemos guardado en dir sea un directorio
	// Con chdir cambiamos al directorio que le pasamos, si no puede, devuelve -1 y lo cazamos como error
	change_dir = chdir(dir);
	if (change_dir != 0) {
			return 1; 
	}
}
