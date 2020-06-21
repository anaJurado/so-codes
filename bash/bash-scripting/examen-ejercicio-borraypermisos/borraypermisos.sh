#!/bin/bash
echo "########################"
echo "##  BORRAYPERMISOS.SH  ##"
echo "########################"
echo ""

# CONTROLAR NUMERO DE PARÁMETROS
if ! test $# -eq 2 
then
	echo "ERROR. Wrong number of parameters. Two params are needed."
	exit 1
fi

# CONTROLAR TIPO DE PARAMETROS
# Si el segundo parámetro no es un fichero que existe, exit
if [ ! -e $2 ]
then
	echo "ERROR. File $2 doesn't exists"
	exit 2
fi

# LAS FUNCIONES DEBEN APARECER ANTES DE LLAMARLAS
# Los parámetros que se pasan a las funciones van por POSICIÓN y no por NOMBRE!!!
function borrar() {
	rm $1
	RESULTADO=` echo $? `
	if test $RESULTADO == "0"
	then
		echo "EXITO AL BORRAR $1"
	else
		echo "ERROR AL BORRAR EL FICHERO"
	fi
} 

function permiso() {
	chmod u+w,g+w $1
	RESULTADO=` echo $? `
	if test $RESULTADO == "0"
	then
		echo "PERMISOS DE ESCRITURA OTORGADOS A $1"
	else
		echo "ERROR AL DAR PERMISOS"
	fi
}

# MAIN
# Si el primero parámetro es BORRAR
if test "$1" == "borrar"
then
	echo "BORRAR $2"
	borrar "$2"
# Si el segundo parametro es PERMISOW
elif [[ "$1" == "PermisoW" ]]
	then
	#statements
	echo "PERMISO $2"
	permiso "$2"
else
	echo "ERROR. First parameter should be \"borrar\" or \"PermisoW\"."
	exit 3
fi

