#!/bin/bash
##########################
# EJERCICIOS EXAMEN - T1 #
##########################
# COPIA_MP3


# Asegurar numero argumentos es 1 o 2
if test $# -lt 1 || test $# -gt 2
then
	echo "ERROR.Please provide a directory where to search for mp3 (OBLIGATORIO)"
	echo "and a directory where to copy them (OPTIONAL) "
    exit 1
fi

# Asegurar argumentos son directorios
for i in $*
do  
	if [ ! -d $i ]
	then
		"ERROR. Arg $i is not a directory"
		exit 2
	fi
done

# Si sólo hay un argumento, el PATH donde copiamos debe ser 
# el directorio actual
if test $# -eq 1
then
	DIR="."
else
	DIR=$2
fi

# Se puede hacer de las dos formas!

# FILES=` find $1 -name "*.mp3" `
# for FILE in $FILES
# do
# 	cp $FILE $DIR
# done


for FIL in ` find $1 -name "*.mp3" `
do
	cp $FIL $DIR
done
