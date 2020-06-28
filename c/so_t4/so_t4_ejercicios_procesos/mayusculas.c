/*
TEMA 4  - EJERCICIOS PROPUESTOS - PROCESOS (2)
Escriba un programa en C llamado “mayusculas” que haga lo siguiente: 
-Cree un proceso hijo. 
-El proceso padre y el proceso hijo se comunicarán de forma bidireccional utilizando tuberías. 
-El proceso padre leerá líneas de la entrada estándar y las enviará por una tubería al proceso hijo. 
-El proceso hijo leerá por una tubería el texto que le envía el padre, 
 lo transformará todo a letras mayúsculas y se lo enviará al padre por otra tubería. 
-El padre imprimirá en pantalla lo que recibe del hijo. 

Ejemplo de ejecución: 

$ ./mayusculas hola 
(enter) HOLA mundo 
(enter) MUNDO 

*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    pid_t pid;
    int p_padre[2]; //Tubería en la que escribe el padre
    int p_hijo[2];  //Tubería en la que escribe el hijo
    char buf[1024];
    
    FILE *p_p, *p_h;  //variables para manejar las tuberías con fputs y fgets
    
    pipe(p_padre);
    pipe(p_hijo);
    
    pid = fork();
    if (pid < 0) { /* Error */
		printf("Falló el fork().%s\n");
		exit(1);
    } else if (pid == 0) { //Hijo 1
    	//Cierro los extremos de las tuberías que no usa el hijo
    	close(p_padre[1]);
    	close(p_hijo[0]);
    	p_p = fdopen(p_padre[0], "r");  
    	p_h = fdopen(p_hijo[1], "w");
    	
    	while( fgets(buf, 1024, p_p) != NULL )
    	{
    		int longitud = strlen(buf);
    		int i;
    		for(i = 0; i < longitud; i++) {
    			buf[i] = toupper(buf[i]);
		}
		fputs(buf, p_h);
		fflush(p_h);
	}
    }
    else
    {
	//Cierro los extremos de las tuberías que no usa el padre
    	close(p_padre[0]);
    	close(p_hijo[1]);
    	p_p = fdopen(p_padre[1], "w");
    	p_h = fdopen(p_hijo[0], "r");
    	
    	while( fgets(buf, 1024, stdin) != NULL )
    	{
    		fputs(buf, p_p);
    		fflush(p_p);
    		fgets(buf, 1024, p_h);
    		fputs(buf, stdout);    	
    	}
    
    }
    
    return 0;
    
}

/*
MacBook-Pro:so_t4_ejercicios_propuestos_procesos ana$ ./mayusculas
hola
HOLA
mundo
MUNDO
pepe
PEPE
^C
*/

