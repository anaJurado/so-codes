// SO - PRÁCTICA 1 - test.c
/********************************************************
 * NOMBRE DEL FICHERO: test.c 					   		*
 * 													   	*
 * PROPÓSITO: Testar las funciones implementadas en     *
 * 			  en la libreria                            *
 * 														*
 * AUTOR: Ana Jurado 								   	*
 * CREADO: Nov.2019							  			*
 *******************************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "libreria.h"

#define MENSAJEERROR (fputs("La sintaxis correcta es (head | tail | longlines) [-N]\n",stderr))

int return_value=0;
int n_lineas=10;

int is_number(char *c);

int main(int argc,char** argv){

	/* 
	 * Si tenemos un tercer argumento, este debe ser un entero positivo.
	 * Si es un entero positivo, será el numero de líneas que se muestren por pantalla 
	*/
	char *param;
	if (argc==3){
		if(argv[2][0]=='-'){
			param=argv[2] + 1;
			if(strlen(argv[2])>1){
				n_lineas=atoi(param); /* Se convierte a numero */
			} else {
				fputs("El tercer argumento ha de ser un número entero positivo.\n",stderr);
				return_value=1;
				MENSAJEERROR;
			}
		}
		else {
			fputs("El tercer argumento no es correcto\n",stderr);
			return_value=1;
			MENSAJEERROR;
		}
	}
	
	/* Se entra en este if si:
	 * return_value == 0 . Hasta este punto los argumentos son válidos
	 * argc == 2 ó argc == 3 . Dos o tres es el número de argumentos válidos
	*/

	if (return_value==0 && (argc==2 || argc==3)){
		// Comprobamos si el segundo commando es "head", "tail" o "longlines"
		if(strcmp(argv[1],"head")==0){
			return_value=head(n_lineas);
		} 
			else if (strcmp(argv[1],"tail")==0){
				return_value=tail(n_lineas);
			}
				else if (strcmp(argv[1],"longlines")==0) {
					return_value=longlines(n_lineas);
				}
					else {
						return_value=1;
						fputs("El argumento o argumentos no son válidos\n",stderr);
						MENSAJEERROR;
					}

	}
	return return_value;
} /* End of main function */


int is_number(char *c){
	int l=strlen(c);
	for(int cont=0;cont<l;cont++){
		if (!isdigit(c[cont]))
			return 0;
	}
	return 1;

}

// gcc test.c libreria.c lista_doble_enlazada.c -o test
