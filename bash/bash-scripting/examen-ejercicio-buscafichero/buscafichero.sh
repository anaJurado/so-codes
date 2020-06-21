#!/bin/bash
echo "#######################"
echo "##  BUSCAFICHERO.SH  ##"
echo "#######################"
echo ""

# Controlar el numero de parametros introducidos
if test $# -lt 1 || test $# -gt 2 
then
	echo "ERROR. Wrong number of parameters"
	exit 1
fi

# Controlar el tipo de parametros que se le pasan
if test $# -eq 2 
then
	if test -d $2
	then
		DIR=$2
	else 
		echo "ERROR.The second parameter is not a directory"
		exit 2
	fi
else
	DIR="./"
fi


# BUSQUEDA RECURSIVA (find)
# Condiciones: Buscará cualquier fichero cuyo nombre coincida con el primer parámetro introducido
# seguido de cualquier numero del 0 al 9 y que tenga extension .txt

RESULT=` find $DIR -name "$1[0-9].txt" ` 

# DETALLE DE IMPRIMIRLO EN LINEAS SEPARADAS
for ST in $RESULT
do
	echo $ST
done

