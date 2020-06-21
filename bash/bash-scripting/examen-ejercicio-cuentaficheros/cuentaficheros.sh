#!/bin/bash
echo "#######################"
echo "##  CUENTAFICHERO.SH  ##"
echo "#######################"
echo ""
 
# A partir de un directorio que se le pasa como parámetro cuent el numero de ficheros (que no de directorios)
# los ficheros han de tener permiso de ejcucion para el propio usuario

# CONTROLAR NUMERO DE PARÁMETROS
if test $# -gt 1 
then
	echo "ERROR. Wrong number of parameters"
	exit 1
fi

# CONTROLAR TIPO DE PARAMETROS
if test $# -eq 1 
then
	if test -d $1
	then
		DIR=$1
	else 
		echo "ERROR.The first parameter is not a directory"
		exit 2
	fi
else
	DIR="./"
fi

# CONTAR CUANTOS FICHEROS TIENEN PERMISO DE EJECUCION PARA EL USUARIO 
# EN EL SUBARBOL DE DIRECTORIOS A PARTIR DEL QUE NOS PASAN O EN EL QUE ESTAMOS

FILEDIR=` find $DIR `
CONTADOR=0
for FD in $FILEDIR
do
	FILE=` ls -l $FD `
	PERM=` echo $FILE | head -c 10 `
	if [[ $PERM =~ [-]{1}[rw]{2}[x] ]]
	then
		CONTADOR=` echo $(($CONTADOR + 1)) `
		echo $FILE
	fi
done

echo "NUMBER OF FILES WITH X USER PERMISION: " $CONTADOR


# EJEMPLO EJECUCIÓN
# ana@MacBook-Pro ejercicio-cuentaficheros %  bash cuentaficheros.sh
# -rwxr--r-- 1 ana staff 0 Jun 18 20:48 .//testDir/ejecutable.txt
# -rwxr--r-- 1 ana staff 1009 Jun 18 21:39 .//cuentaficheros.sh
# NUMBER OF FILES WITH X USER PERMISION:  2
# ana@MacBook-Pro ejercicio-cuentaficheros %
# ana@MacBook-Pro ejercicio-cuentaficheros %  bash cuentaficheros.sh testDir
# -rwxr--r-- 1 ana staff 0 Jun 18 20:48 testDir/ejecutable.txt
# NUMBER OF FILES WITH X USER PERMISION:  1
# ana@MacBook-Pro ejercicio-cuentaficheros %

