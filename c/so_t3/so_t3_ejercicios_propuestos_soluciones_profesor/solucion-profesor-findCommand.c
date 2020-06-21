#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char * cmd2path(char * cmd);

int main(int argc, char *argv[])
{

	char *ruta;

	if(argc != 2)
	{
	  fprintf(stderr,"Uso: %s COMANDO\n", argv[0]);
	  return 1;
	}
	else
	{
	  ruta = cmd2path(argv[1]);
	  if (ruta == NULL) {
		fprintf(stdout,"%s no se encuentra en ningún directorio del PATH\n",argv[1]);
	  } else {
		fprintf(stdout,"%s esta en %s\n",argv[1],ruta);
	  }
	  return 0;
	} 
}

char * cmd2path(char * cmd) {
	char buf[1024];
	char * str;
	char * tokens;

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
