// ENTRADA/SALIDA - Llamadas al sistema - Ficheros

#include ...
#define LONBUFFER 1024


int main (void) {
	FILE *fe, *fs;
	int nr;
	char *entrada = "entrada";
	char *salida = "salida";
	char buffer[LONBUFFER];

if ((fe=fopen(entrada,"r")) == NULL) {
	fprintf(stderr,"Error al abrir el fichero %s.\n%s.\n",entrada,strerror(errno));
	return 1;
}
else if ((fs=fopen(salida,"w")) == NULL) {
	fprintf(stderr,"Error al abrir el fichero %s.\n%s.\n",salida,strerror(errno));
	fclose(fe);
	return 1;
}

while (fgets(buffer,LONBUFFER,fe) != NULL) /* Lee una línea */
	fputs(buffer,fs);

fclose(fe);
fclose(fs);
return 0;

}