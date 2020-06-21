// EJERCICIOS PROPUESTOS - TEMA 3 - FIND COMMAND
/*
Escriba un programa en C llamado “findCommand” que busque en todos los directorios contenidos 
en la variable de entorno $PATH el nombre de un mandato que se le pasa como parámetro 
comprobando que es ejecutable. 

Algunas llamadas al sistema y funciones necesarias: access(2), getenv(3), strcat(3) 
*/

// VERSION PROFE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// DECLARACIÓN DE LA FUNCIÓN QUE SE IMPLEMENTA MÁS ABAJO
char * cmd2path(char * cmd);


// FUNCION MAIN
int main(int argc, char *argv[])
{

	char *ruta; // variable puntero a char que se llama ruta

	// CONTROLAMOS EL NUMERO DE ARGUMENTOS. QUEREMOS RECIBIR 2. La llamada a la funcion cuenta como uno!!!
	if(argc != 2)
	{	
	  fprintf(stderr,"Uso: %s COMANDO\n", argv[0]);
	  return 1;
	}
	else
	{
	  // En la variable ruta (puntero a char) guardamos lo que nos devuelve la función cmd2path
	  // Le pasamos como argumento a la funcion el primer parámetro que nos ha llegado
	  ruta = cmd2path(argv[1]);  
	  if (ruta == NULL) {
		fprintf(stdout,"%s no se encuentra en ningún directorio del PATH\n",argv[1]);
	  } else {
		fprintf(stdout,"%s esta en %s\n",argv[1],ruta);
	  }
	  return 0;
	} 
}

// FUNCION cmd2path
// ¿QUÉ HACE LA FUNCION?
// La función necesita que le pasen un puntero a char, 
// que dentro de la funcion tendrá el nombre de cmd
// En principio lo que le hemos pasado cuando hemos llamado a la funcion es el nombre de un mandato
char * cmd2path(char * cmd) {

	// Variables necesarias
	char buf[1024];		//Array de char llamado buff de 1024 posiciones 
	char * str;			// Puntero a char llamado str
	char * tokens;		// Puntero a char llamado tokens

	// strchr(cmd, '/') encuentra la primera ocurrencia de '/' en la cadena cmd
	if (strchr(cmd, '/')) {
		if (!access(cmd, X_OK))
			return strdup(cmd);
		else
			return NULL;
	}
	str = getenv("PATH");
	if (!str) {
		str = "/bin:/usr/bin";
	}

	tokens = strtok(str,":");
	while (tokens) {
		printf("%s %s\n",tokens,str); 
		tokens=strtok(NULL,":");
		if (tokens != NULL) {
			strcpy(buf,tokens);
			strcat(buf, "/");
			strcat(buf, cmd);

			if (!access(buf, X_OK)) {
				return strdup(buf);
			}
		}	
	}
	return NULL;
}



// FUNCIONES USADAS EN EL PROGRAMA:

/*
getenv()

DEFINICION
     char *
     getenv(const char *name);

DESCRIPCION
     The getenv() function obtains the current value of the environment variable, name.
     The application should not modify the string pointed to by the getenv() function.

RETURN VALUES
     The getenv() function returns the value of the environment variable as a
     NUL-terminated string.  If the variable name is not in the current environment, NULL
     is returned.
*/



/*
strchr
     #include <string.h>

     char *
     strchr(const char *s, int c);

DESCRIPTION
     The strchr() function locates the first occurrence of c (converted to a char) in the
     string pointed to by s.  The terminating null character is considered to be part of
     the string; therefore if c is `\0', the functions locate the terminating `\0'.

     The strrchr() function is identical to strchr(), except it locates the last occur-
     rence of c.

RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located character, or
     NULL if the character does not appear in the string.

*/

/*
access()
SYNOPSIS
     #include <unistd.h>

     int
     access(const char *path, int mode);
DESCRIPTION
     The access() system call checks the accessibility of the file named by the path
     argument for the access permissions indicated by the mode argument.  The value of
     mode is either the bitwise-inclusive OR of the access permissions to be checked
     (R_OK for read permission, W_OK for write permission, and X_OK for execute/search
     permission), or the existence test (F_OK).
RETURN VALUES
     Upon successful completion, the value 0 is returned; otherwise the value -1 is
     returned and the global variable errno is set to indicate the error.

*/
