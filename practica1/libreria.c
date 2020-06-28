// SO - PRÁCTICA 1 - libreria.c
/********************************************************
 * NOMBRE DEL FICHERO: libreria.c 					   	*
 * 													   	*
 * PROPÓSITO: Implementar las funciones de la librería 	*
 *			  deescrita en libreria.h y sus funciones  	*
 *			  auxiliares.                              	*
 * 														*
 * AUTOR: Ana Jurado 								   	*
 * CREADO: Nov.2019							  			*
 *******************************************************/

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#include "libreria.h"
#include "lista_doble_enlazada.h"

char* buffer;
int n_errno;
int n_saved_lines = 0;
int output = 0;
size_t buf_size=512;
size_t charact;


int compare_length_lines_func(char* c1,char* c2);
void show_std_output(s_dllist_start_end* dllist);

s_dllist_start_end* dllist;

/*
 * Function: head 
 * --------------------
 * Reads from standar input the first N lines, save them in a list and show them on the standar output
 *  
 *  N: number of lines to show on standar output
 *
 *  returns: Show the N first lines on the standar input. Error code:
 * 			output =0:	Execution OK
 * 			output!=0:	Execution FAIL
 */
int head(int N){
	if (N>0) {
		buffer = (char *)malloc(buf_size * sizeof(char)); 	/* Instanciamos el buffer */
		do{
			charact=getline( &buffer ,&buf_size, stdin);
			if (charact==-1) 		/* -1 si EOF o error */
			{
				n_errno=errno;
				if (n_errno!=0){ 	/* charact = -1 debido a un error (no por EOF) */
					fputs(strerror(n_errno), stderr);
					output=2;
				}
			}
			else
			{
				/* Si no ha habido error se lee la linea */
				printf("%s",buffer);	
				N--; /* Decremento numero de lineas que quedan*/
			}

		} while(charact!=-1 && N>0); 
		/* Mostrará lineas hasta leer las nLineas primeras o llegue al final del fichero */
	}
	return output;
}

/*
 * Function: tail
 * --------------------
 * Reads from standar input the last N lines, save them in a list and show them on the standar output
 *  
 *  N: number of lines to show on standar output
 *
 *  returns: Show the N last lines on the standar input. Error code:
 * 			output =0:	Execution OK
 * 			output!=0:	Execution FAIL
 */
int tail(int N){
	if (N>0) {
		dllist=init_list(NULL); 		/* dll es un puntero al primer nodo de la lista */
		buffer = (char *)malloc(buf_size * sizeof(char));

		do{
			charact=getline( &buffer ,&buf_size, stdin);
			if (charact==-1) 			/* -1 si EOF o error */
			{
				n_errno=errno;
				if (n_errno!=0){ 		/* charact = -1 debido a un error (no por EOF) */
					fputs(strerror(n_errno), stderr);
					output=2;
				}
			}
			else
			{
				if (n_saved_lines==N) 	/* Cuando Nº de lineas sea el especificado, se eliminara la primera linea de la lista */
				{
					delete_node_start(dllist);
				}
				else{
					n_saved_lines++;
				}
				add_node_end(dllist, buffer); 	/* Introduce al final de la lista la nueva linea */
			}

		} while(charact!=-1); 	/* Sigue leyendo lineas hasta que alcanza EOF o CTRL+D */
		if (output==0)  /* Solo mostrara el resultado si no ha habido errores */
		{
			show_std_output(dllist); /* Mostrara por pantalla las lineas almacenadas */

			delete_list(dllist);
			free(dllist);
		}
	}
	return output;
}

/*
 * Function: longlines
 * --------------------
 * Reads from standar input lines.
 * Save them in a list ordered by lenght from longest to shortest and show them on the standar output.
 * When we reach N lines, the function deletes the last line on the list (shortest) if needed 
 * and include the new line in its corresponding place.
 *  
 *  N: number of lines to show on standar output
 *
 *  returns: Show the N last lines on the standar input. Error code:
 * 			output =0:	Execution OK
 * 			output!=0:	Execution FAIL
 */
int longlines(int N){
	if (N>0)
	{
		dllist=init_list(compare_length_lines_func);
		buffer = (char *)malloc(buf_size * sizeof(char));
		do{
			charact=getline( &buffer ,&buf_size,stdin);
			if (charact==-1) /* Si el -1 es por error se podra comprobar viendo el valor de n_errno */
			{
				n_errno=errno;
				if (n_errno!=0){ /* Este será el caso en el que charact valga -1 debido a un error y no por EOF */
					fputs(strerror(n_errno), stderr);
					output=2;
				}
			}
			else
			{
				add_node_ordered(dllist,buffer); /* Introduce al final de la lista la nueva linea */
				if (n_saved_lines==N) /* Cuando Nº de lineas sea el especificado, eliminará el último nodo de la lista */
				{
					delete_node_end(dllist);
				}
				else{
					n_saved_lines++;
				}
			}

		}while(charact!=-1); /* Permanece leyendo lineas hasta que alcanza EOF */
		
		if (output==0) /* Solo mostrara el resultado si no ha habido errores */
		{
			show_std_output(dllist); // Mostrara por pantalla las lineas almacenadas
			delete_list(dllist);
			free(dllist);
		}
	}
	return output;
}

// FUNCIONES AUXILIARES

/*
 * Function: compare_length_lines_func
 * --------------------
 * Compares the lenght between two lines
 *  
 *  char* c1,char* c2: pointer to lines (char) to be compared
 *
 *  returns: integer
 *			0 if equal lenght
 *			< 0 if c2 is greater than c1
 *			> 0 if c2 is lower thatn c1
 */
int compare_length_lines_func(char* c1,char* c2){
	return strlen(c1)-strlen(c2);
}

/*
 * Function: show_std_output
 * --------------------
 * Show on stdr output (screen) the content of the list in FIFO order
 * 	
 *  s_dllist_start_end* lista: list from where the lines are readed
 *
 * 	returns: Nothing
 *
 */
void show_std_output(s_dllist_start_end* lista){
	
	s_node* temp_linea;
	
	if(lista!=NULL && lista->start!=NULL){
		temp_linea=lista->start;
		do {
			if (temp_linea->line!=NULL)
				printf("%s",temp_linea->line);
			temp_linea=temp_linea->next_node;
		} while(temp_linea!=lista->start);
	}
}
