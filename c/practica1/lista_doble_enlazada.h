// SO - PRÁCTICA 1 - lista_doble_enlazada.h
// LISTA DOBLEMENTE ENLAZADA - ARCHIVO DE CABECERA .h
/********************************************************
 * NOMBRE DEL FICHERO: 									*
 * 			   lista_doble_enlazada.h 					*
 * 													   	*
 * PROPÓSITO: Implementar las funciones de la librería 	*
 *			  descrita en lista_doble_enlazada.h.       *
 * 			  y sus funciones auxiliares.               *
 * 														*
 * AUTOR: Ana Jurado 								   	*
 * CREADO: Nov.2019							  			*
 *******************************************************/
#ifndef _LISTA_DOBLE_ENLAZADA_H
#define _LISTA_DOBLE_ENLAZADA_H

struct node{
	//char* line;
	char* line;
	struct node* next_node;
	struct node* prev_node;
};
typedef struct node s_node;  // s_node es el alias de struct node (para no tener que poner struct node en todos sitios)


// Es un puntero a una función (la función para ordenar en nuestro caso) que devuelve un int y tiene como entrada dos char
typedef int (*d_output_order_function)(char*,char*);   

// Lista doblemente enlazada (dllist) con función de ordenación y cabecera (start) y cola (end)
typedef struct doubly_linked_list_start_end_ordered{
	// Creamos un puntero a una funcion que devuelve un entero y recibe dos cadenas de caracteres
	d_output_order_function order_function; 
	s_node* start;
	s_node* end;
} s_dllist_start_end;

// FUNCIONES
s_dllist_start_end* init_list(d_output_order_function);

void add_node_ordered(s_dllist_start_end* lista,char* new_line);
void add_node_end(s_dllist_start_end* lista,char* new_line);
s_node* add_node_after(s_node* previous_node,s_node* new_node);

void delete_node_start(s_dllist_start_end* lista);
void delete_node_end(s_dllist_start_end* lista);
void delete_list(s_dllist_start_end* lista);

#endif
