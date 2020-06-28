// SO - PRÁCTICA 1 - lista_doble_enlazada.c
// LISTA DOBLEMENTE ENLAZADA - ARCHIVO FUENTE .c
/********************************************************
 * NOMBRE DEL FICHERO: lista_doble_enlazada.c 		    *
 * 													   	*
 * PROPÓSITO: Implementar las funciones de la librería 	*
 *			  descrita en lista_doble_enlazada.h       *
 * 			  y sus funciones auxiliares.               *
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

s_node* add_node_after(s_node* previous_node,s_node* new_node);


// FUNCIONES AUXILIARES

/*
 * Function: dummy_order_function
 * -------------------------------------
 * Dummy order function that indicates that the first element is always greater than the second element
 * 	c1: line 1
 * 	c2: line 2
 *
 * Return: 1 (always)
 */
int dummy_order_function(char* c1,char* c2){
	return 1;
}


// FUNCIONES MODULO
/*
 * Function: init_list
 * ---------------------------------
 * Create a new list with the order function that is pass as argument.
 * If NULL, it will use the dummy_order_function
 * Init the fields in node
 * 
 * 	ord_fun: Order function to be use in the init of the list. 
 *
 * 	returns: list ready to use
 */
s_dllist_start_end* init_list(d_output_order_function ord_fun){
	s_dllist_start_end* new_dllist=(s_dllist_start_end*)malloc(sizeof(s_dllist_start_end));
	
	new_dllist->start=NULL;
	new_dllist->end=NULL;
	new_dllist->order_function=(d_output_order_function)malloc(sizeof(d_output_order_function));
	
	if (ord_fun!=NULL) {
		new_dllist->order_function=ord_fun;
	}
	else {
		new_dllist->order_function=dummy_order_function;
	}

	return new_dllist;
}


/*
 * Function: add_node_ordered
 * ---------------------------------
 * Insert a node in the list in the right position base on de order function used
 * If list is full (N) and the lines are the same lenght that the previous ones, these lines are dropped
 *
 * 	lista: list to insert the node to
 * 	new_line: the new line to be inserted
 *
 */
void add_node_ordered(s_dllist_start_end* lista,char* new_line){
	
	s_node* temp_node_line=(s_node*)malloc(sizeof(s_node));
	s_node* dllist_iterator = NULL;
	int out_loop=0;

	temp_node_line->line=strdup(new_line);
	(*temp_node_line).prev_node=NULL;
	(*temp_node_line).next_node=NULL;

	if (lista->start==NULL)  	/* First element of the list */
	{	
		/* El nodo siguiente y el nodo previo será él mismo */
		(*temp_node_line).prev_node=temp_node_line;
		(*temp_node_line).next_node=temp_node_line;
		
		/* La cabecera (start) y la cola (end) será el mísmo nodo */
		lista->start=temp_node_line;
		lista->end=temp_node_line;
	}
	else /* Insertará el nuevo elemento de la lista segun el orden */
	{
		dllist_iterator=lista->start; /* El iterador comienza en la cabecera de la lista*/
		
		do{	
			/* Si la linea de la lista es mayor que la linea del nuevo nodo, este nuevo nodo se insertará después*/
			if (lista->order_function(temp_node_line->line,dllist_iterator->line)>0){ 
				add_node_after(dllist_iterator->prev_node,temp_node_line);

				if(dllist_iterator==lista->start)
					lista->start=temp_node_line;
				out_loop=1;
			}
			else {
				dllist_iterator=dllist_iterator->next_node;
			}

		} while((out_loop==0) && (dllist_iterator!=lista->start)); /* Controlamos que no nos "salgamos" de la lista */
		
		/* Si llegamos a este punt, significa que el elmento debe ir al final de la lista*/
		if (out_loop==0){ 	// Caso en el que el elemento debe ir al final de la lista (segun el criterio de orden)
			add_node_after(lista->end,temp_node_line);
			lista->end=temp_node_line;
		}
	}
}


void add_node_end(s_dllist_start_end* lista,char* new_line){
	s_node* temp_node_line=(s_node*)malloc(sizeof(s_node));
	s_node* temp_node_previous_line;
	temp_node_line->line=strdup(new_line);
	(*temp_node_line).prev_node=NULL;
	(*temp_node_line).next_node=NULL;
	if (lista->start==NULL) // Si no existe la cola previamente, creara una nueva
	{
		(*temp_node_line).prev_node=temp_node_line;
		(*temp_node_line).next_node=temp_node_line;
		lista->start=temp_node_line;
	}
	else // Si la cola existia, insertará el nuevo elemento de la cola al final
	{
		temp_node_previous_line=lista->end;
		temp_node_previous_line->next_node=temp_node_line;

		temp_node_line->prev_node=temp_node_previous_line;
		temp_node_line->next_node=lista->start;

		lista->start->prev_node=temp_node_line;
	}
	(*lista).end=temp_node_line;
}

/*
 * Function: add_node_after
 * ---------------------------------
 * Insert a new node after a given node
 * 
 * 	previous_node: previous node to the node that will be insertd
 * 	new_line: line to be inserted
 *
 * 	returns: line inserted
 */
s_node* add_node_after(s_node* previous_node,s_node* new_node){
	
	s_node* temp=previous_node->next_node;
	previous_node->next_node=new_node;
	temp->prev_node=new_node;
	new_node->next_node=temp;
	new_node->prev_node=previous_node;
	
	return new_node;
}


/*
 * Function: delete_first_node_dll
 * -------------------------------------
 * Deletes the first element of the list
 * 
 *  lista: list from where to delete the node
 * 
 * 	returns: Nothing
 */
void delete_node_start(s_dllist_start_end* lista){
	s_node* temp;
	if (lista != NULL && lista->start != NULL){
		temp=lista->start;
		if (lista->start == lista->end){
			lista->start = NULL;
			lista->end = NULL;
		}
		else{
			lista->start=lista->start->next_node;
			temp->prev_node->next_node=temp->next_node;
			temp->next_node->prev_node=temp->prev_node;
		}

		free(temp->line);
		free(temp);

	}
}


/*
 * Function: delete_node_end
 * -------------------------------------
 * Delete the last node of the list
 * 
 *  lista: list from where to delete the node
 * 
 * 	returns: Nothing
 */
void delete_node_end(s_dllist_start_end* lista){
	s_node* temp;
	if (lista!=NULL && lista->start != NULL){
		temp=lista->end;
		if(lista->end==lista->start)
		{
			lista->start=NULL;
			lista->end=NULL;
		}
		else{
			lista->end=lista->end->prev_node;
			temp->prev_node->next_node=temp->next_node;
			temp->next_node->prev_node=temp->prev_node;
		}

		free(temp->line);
		free(temp);

	}
}


/*
 * Function: delete_list
 * -------------------------------------
 * Delete all the nodes of the list
 * 
 *  lista: list from where to delete the nodes
 * 
 * 	returns: Nothing
 */
void delete_list(s_dllist_start_end* lista){
	while(lista!=NULL && lista->start!=NULL)
		delete_node_end(lista);
}



