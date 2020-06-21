#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int lineas;
	char buf[1024];
  	int cuenta = 0;
	
	if(argc == 1)
	{
		lineas = 10;
	}
	else if (argc == 2)
	{
		char *num = argv[1] + 1;
		lineas = atoi(num);		
	}
	else
	{
		printf("Uso: \"%s -N\" para ver las N primeras líneas, o \"%s\" para las 10 primeras líneas\n", argv[0], argv[0]);
		return 1;
	}
	
  	
	while((cuenta < lineas) && (fgets(buf, 1024, stdin) != NULL))
	{
		printf("%s", buf);
		cuenta++;
	}
	
	return 0;	
}
