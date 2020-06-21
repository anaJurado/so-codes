#include <stdio.h>
#define LONBUFFER 2561024

int main (void) {
	int fde, fds, nr;
	char *entrada = "entrada";
	char *salida = "salida";
	char buffer[LONBUFFER];

	// Quiero saber qué contiene buffer: the content of buffer is: 0x7ffee8479540
	printf("--------------------------\n");
	printf("the content of buffer is: %p \n", buffer);
	printf("--------------------------\n");

	// APERTTURA DE FICHERO:
	// int open (char* name, int flags [, mode_t mode]);
	// Valor devuelto: Descriptor de fichero ó -1 en caso de error
	/*
		flags:
		§ O_RDONLY: El fichero se abre de sólo lectura
		§ O_WRONLY: El fichero se abre de sólo escritura
		§ O_RDWR: El fichero se abre de lectura y escritura
		§ O_APPEND: Se escribe a partir del final del fichero
		§ O_CREAT: Si no existe el fichero, se crea y no da error
		§ O_TRUNC: Se trunca el fichero
	*/


	// Coprobamos que se puede abrir "entrada"
	if ((fde=open(entrada,O_RDONLY)) < 0) {
		printf("Error al abrir el fichero %s.\n%s.\n", entrada,strerror(errno));
		return 1;
	}

	// Coprobamos que se puede abrir "salida"
	else if ((fds=open(salida,O_WRONLY|O_TRUNC|O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP,S_IROTH)) < 0) {
		printf("Error al abrir el fichero %s.\n%s.\n", salida,strerror(errno));
		close(fde);
		return 1;
	}

	// Leemos de "entrada" (fde) y "escribimos" en salida (fds)

	// LECTURA DE FICHEROS:
	// size_t read (int fd, void* buf, size_t n_bytes);
	/*
	Argumentos:
		§ fd: descriptor de fichero del fichero que se va a leer
		§ buf: buffer donde se van a almacenar los Bytes leídos
		§ n_bytes: número de Bytes que se quiere leer
	Valor devuelto:
		§ Número de Bytes leídos ó -1 en caso de error
	Funcionamiento:
		§ Lee n_bytes como máximo (menos si el fichero es menor)
		§ Se incrementa el puntero del fichero por cada Byte leído
	*/

	// ESCRITURA FICHERO BINARIO:
	// size_t write (int fd, void* buf, size_t n_bytes);
	/*
	Argumentos:
		§ fd: descriptor de fichero del fichero que se va a leer
		§ buf: buffer que contiene los Bytes a escribir en el fichero
		§ n_bytes: número de Bytes que se quiere escribir
	Valor devuelto:
		§ Número de Bytes escritos ó -1 en caso de error
	Funcionamiento:
		§ Escribe n_bytes (si no se interrumpe por una señal)
		§ Podría escribir menos. Es necesario comprobar el número de bytes escritos
		§ Se incrementa el puntero del fichero por cada byte escrito
	*/

	while ((nr = read(fde,buffer,LONBUFFER)) > 0)
		write(fds,buffer,nr);
	
	// Cerramos los fichero y devolvemos un 0 en señal de que todo ha ido bien
	close(fde);
	close(fds);
	return 0;
	
}