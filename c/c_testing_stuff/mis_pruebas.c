#include <stdio.h>
#include <stdlib.h>

int main()
{

	char* buffer;
	size_t buf_size=10;

	buffer = (char *)malloc(buf_size * sizeof(char)); // reservi espacio en memoria para buf_size(10) chars 

	printf("Donde apunta buffer (DIRECCIÓN MEMORIA): %p\n", &buffer);
	printf("Donde apunta buffer (VALOR): %p\n", buffer);
	printf("Donde apunta buffer: %c\n", *buffer);
	printf("___________________________\n");
	printf("___________________________\n");

	buffer = "A";

	printf("Donde apunta buffer (DIRECCIÓN MEMORIA): %p\n", &buffer);
	printf("Donde apunta buffer (VALOR): %p\n", buffer);
	printf("Qué tiene buffer: %c\n", *buffer);
	printf("___________________________\n");

	buffer = buffer + 1 ;
	buffer =  "B";

	printf("Donde apunta buffer (DIRECCIÓN MEMORIA): %p\n", &buffer);
	printf("Donde apunta buffer (VALOR): %p\n", buffer);
	printf("Qué tiene buffer: %c\n", *buffer);
	printf("___________________________\n");

	buffer = buffer + 1 ;
	buffer =  "C";

	printf("Donde apunta buffer (DIRECCIÓN MEMORIA): %p\n", &buffer);
	printf("Donde apunta buffer (VALOR): %p\n", buffer);
	printf("Qué tiene buffer: %c\n", *buffer);
	printf("___________________________\n");
	printf("___________________________\n");

	printf("TENEMOS METIDOS TRES VALORES\n");
	printf("Donde apunta buffer (VALOR): %p\n", buffer);
	printf("Donde apunta buffer-1 (VALOR): %p\n", buffer-(sizeof(char)));
	printf("Donde apunta buffer-2 (VALOR): %p\n", buffer-2);

	//printf("Qué tiene buffer: %c\n", *buffer);


	//printf("Donde apunta buffer -1 : %p\n", &(buf_1);
	//printf("Qué tiene buffer: %c\n", *(buffer-1));
  
  	return 0;
}



