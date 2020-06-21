/*
Escriba un programa en C llamado CORREGIR que procesará las prácticas de todos los alumnos 
y generará para cada uno de ellos un archivo de salida con los resultados de su práctica, 
más un archivo con la salida del error.


*/


int main(int argc, char *argv[]){

	// VARIABLES
	char * dirname;
	char * filename;
	DIR * pDir;
	FILE * PFil;


	// CONTOLAMOS EL NUMERO DE ARGUMENTOS

	if (argc != 3){
		printf("ERROR. Numero de argumentos requerido: 2. Numero de argumentos recibidos %d\n", (argc-1));
		return 1;
	}

	// CONTROLAMOS EL TIPO DE LOS ARGUMENTOS

	//¿Cómo saber si el primer argumento es un directorio o si existe?
	// Lo intento abrir con DIR* opendir (char* dirname) y si da error, pues supongo que se puede decir que no es un dir válido
	
	dirname = argv[1];
	pDir = opendir(dirname);

	if (pDir == NULL){
		printf("ERROR. %s no es un DIRECTORIO válido\n", dirname);
		return 1;
	}

	//¿Cómo saber si el segundo argumento es un fichero "normal" o si existe?
	// Lo intent abrir con FILE* fopen(const char* nombreArchivo, const char* modo)
	// Si da error, pues suponemos que no es válido o no existe
	filename = argv[2];
	pFil = fopen(filename,"r");

	if (pFil == NULL){
		printf("ERROR. %s no es un FICHERO válido\n", filename);
		return 1;
	}

	// LO QUE SIGUE ES DEL TEMA 4




}