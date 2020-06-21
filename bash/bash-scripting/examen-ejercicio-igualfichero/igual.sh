#!/bin/bash
echo "################"
echo "##  IGUAL.SH  ##"
echo "################"
echo ""

#Numero argumentos es 2 o 3
if [ $# -lt 2 ] || [ $# -gt 3 ] 
then
	echo "ERROR. Number of arguments invalid."
	exit 1
fi

# Comprobamos si el tercer argumento es un directorio
# Si sólo dos argumentos, el dir es el actual
if [ $# -eq 3 ] 
then
	if [ -d $3 ]
	then
		DIR=$3
	else
		echo "ERROR. Third argument is not a valid directory"
		exit 2
	fi
else
	DIR="./"
fi

# Recorro recursivamente todo los ficheros y directorios a partir de $DIR
for FD in ` find $DIR `
do 	
	# Si FD es in fichero entonces calculo la diferencia con el que me ha pasado
	if [ -f $FD ] 
	then
		DIFFERENT=` diff $1 $FD `
		# Si no existe diferencia significa que son iguales
		if [ ! $DIFFERENT ]
		then
			# Guardamos el fichero con el que no hemos encontrado diferencias
			# Importante hacerlo con >> porque como es un FOR 
			# cada vez que lo abras para escribir no quiere machacarlo!!!
			echo $FD >> $2
		fi
	fi
done


# EJECUCIONES
# CON DOS ARGUMENTOS:
# ana@MacBook-Pro Ejercicio-igualfichero % bash igual.sh text.txt salida.txt
# igual.sh: line 37: [: too many arguments
# igual.sh: line 37: [: too many arguments
# igual.sh: line 37: [: too many arguments
# igual.sh: line 37: [: too many arguments
# igual.sh: line 37: [: too many arguments
# igual.sh: line 37: [: too many arguments
# igual.sh: line 37: [: too many arguments
# igual.sh: line 37: [: too many arguments
# igual.sh: line 37: [: too many arguments
# igual.sh: line 37: [: too many arguments
# igual.sh: line 37: [: too many arguments
# ana@MacBook-Pro Ejercicio-igualfichero % cat salida.txt
# .//text.txt
# .//dir1/dir2/dir2_text_copy.txt
# .//dir1/dir1_text_copy.txt
# .//textos/text_copy.txt
# .//textos/mastextos/mas_text_copy.txt
# .//textos/text_copy_copy.txt

# CON TRES ARGUMENTOS:
# ana@MacBook-Pro Ejercicio-igualfichero % bash igual.sh text.txt salida_2.txt textos
# igual.sh: line 37: [: too many arguments
# igual.sh: line 37: [: too many arguments
# igual.sh: line 37: [: too many arguments
# igual.sh: line 37: [: too many arguments
# igual.sh: line 37: [: too many arguments
# ana@MacBook-Pro Ejercicio-igualfichero % cat salida_2.txt
# textos/text_copy.txt
# textos/mastextos/mas_text_copy.txt
# textos/text_copy_copy.txt












