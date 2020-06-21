# SISTEMAS OPERATIVOS TEMA 1 - EJERCICIOS 
# INTÉRPRETE DE MANDATOS


Actividad 16 (intermedia): redirección de entrada y salida
Las actividades 12 y 13 comprenden mandatos de tipo filtro que pueden tomar sus datos de entrada desde la entrada estándar. La mayoría de esos mandatos también aceptan entrada procedente de
un fichero, como así se solicita en muchos de ellos. En esta actividad se pide repetir los ejercicios de las actividades 12 y 13, pero:
	• En todos los casos, la entrada procederá de la entrada estándar redirigida desde un fichero (<).
	• En todos los casos, la salida estándar se redirigirá a un fichero de texto (>). Como propuesta, en algunos casos la salida se redirigirá hacia un fichero existente mediante concatenación (>>).

		ana:URJC/ $ cat mand.txt | grep uno # pipe: la salida estándar del cat va a la entrada estándar del grep
		ana:URJC/ $ grep "uno"  < mand.txt # metes el contenido del fichero directamente en la entrada estándar del grep (no hace falta el cat)
		ana:URJC/ $ grep uno mand.txt # pasas el nombre del fichero como parámetro al grep y es ese programa el que abre el fichero, lo lee... etc



	ana:URJC/ $ wc -l < mand.txt                                                                                                                                                 [9:30:35]
       5
	ana:URJC/ $ wc -l mand.txt                                                                                                                                                   [9:32:17]
       5 mand.txt
	ana:URJC/ $ ls > sal.txt                                                                                                                                                     [9:32:25]
	ana:URJC/ $ ls >> sal.txt                                                                                                                                                    [9:32:42]
	ana:URJC/ $ cat sal.txt                                                                                                                                                      [9:32:50]
		SISTEMAS OPERATIVOS
		jugando_mandatos.txt
		mand.txt
		sal.txt
		test.txt
		whoson
		SISTEMAS OPERATIVOS
		jugando_mandatos.txt
		mand.txt
		sal.txt
		test.txt
		whoson


Actividad 17 (intermedia-avanzada): tuberías


ana:URJC/ $ ls -la                                                                                                                                                           [9:33:53]
	total 56
	drwxr-xr-x   9 ana  staff   288 Oct  3 09:32 .
	drwxr-xr-x+ 81 ana  staff  2592 Oct  3 09:34 ..
	-rw-r--r--@  1 ana  staff  6148 Oct  2 20:26 .DS_Store
	drwxr-xr-x  14 ana  staff   448 Oct  2 22:01 SISTEMAS OPERATIVOS
	-rw-r--r--   1 ana  staff   187 Oct  3 08:52 jugando_mandatos.txt
	-rw-r--r--   1 ana  staff    35 Oct  3 09:13 mand.txt
	-rw-r--r--   1 ana  staff   148 Oct  3 09:32 sal.txt
	-rw-r--r--   1 ana  staff     4 Oct  2 23:52 test.txt
	-rw-r--r--   1 ana  staff   158 Oct  3 08:56 whoson
ana:URJC/ $ ls -la | wc                                                                                                                                                      [9:34:02]
      10      84     503
ana:URJC/ $ ls -la | wc -l                                                                                                                                                   [9:34:11]
      10

1. Utilizar una tubería para ver la lista de ficheros de /usr/bin página a página (ls, more).
2. Utilizar una tubería para filtrar la lista de nombres de ficheros del directorio /usr/bin página a página, para ver sólo los que contengan el carácter "m" sin tener que usar un fichero (ls, grep, more / ls, more).

	ana:URJC/ $ ls -la | grep ".txt$"                                                                                                                                            [9:36:19]
		-rw-r--r--   1 ana  staff   187 Oct  3 08:52 jugando_mandatos.txt
		-rw-r--r--   1 ana  staff    35 Oct  3 09:13 mand.txt
		-rw-r--r--   1 ana  staff   148 Oct  3 09:32 sal.txt
		-rw-r--r--   1 ana  staff     4 Oct  2 23:52 test.txt

	ana:URJC/ $ ls -la | grep ".txt"                                                                                                                                             [9:36:27]
		-rw-r--r--   1 ana  staff   187 Oct  3 08:52 jugando_mandatos.txt
		-rw-r--r--   1 ana  staff    35 Oct  3 09:13 mand.txt
		-rw-r--r--   1 ana  staff   148 Oct  3 09:32 sal.txt
		-rw-r--r--   1 ana  staff     4 Oct  2 23:52 test.txt

	ana:URJC/ $ ls -la | grep "t"                                                                                                                                                [9:36:51]
		total 56
		drwxr-xr-x   9 ana  staff   288 Oct  3 09:32 .
		drwxr-xr-x+ 81 ana  staff  2592 Oct  3 09:37 ..
		-rw-r--r--@  1 ana  staff  6148 Oct  2 20:26 .DS_Store
		drwxr-xr-x  14 ana  staff   448 Oct  2 22:01 SISTEMAS OPERATIVOS
		-rw-r--r--   1 ana  staff   187 Oct  3 08:52 jugando_mandatos.txt
		-rw-r--r--   1 ana  staff    35 Oct  3 09:13 mand.txt
		-rw-r--r--   1 ana  staff   148 Oct  3 09:32 sal.txt
		-rw-r--r--   1 ana  staff     4 Oct  2 23:52 test.txt
		-rw-r--r--   1 ana  staff   158 Oct  3 08:56 whoson

3. Escribir una línea de mandatos conectados entre sí para mostrar por pantalla cuántos usuarios se encuentran conectados al sistema (who, wc).

	ana:URJC/ $ who                                                                                                                                              
		ana      console  Sep 11 16:02
		ana      ttys000  Oct  2 23:37
		ana      ttys001  Oct  3 08:32
		ana      ttys003  Oct  2 23:12
	ana:URJC/ $ who | cut -f1 -d " "                                                                                                                                  
		ana
		ana
		ana
		ana
	ana:URJC/ $ who | cut -f1 -d " " | wc                                                                                                                                   
	       4       4      16
	ana:URJC/ $ who | cut -f1 -d " " | wc -l                                                                                                                                     [9:40:46]
       4

4. Escribir una línea de mandatos conectados entre sí para mostrar por pantalla en orden alfabético los nombres de los usuarios que permanecen conectados (who, sort).
5. Escribir una línea de mandatos conectados entre sí para mostrar por pantalla cuántos usuarios hay en el sistema (sin tener en cuenta si están conectados o no) (cat, wc).
6. Escribir una línea de mandatos conectados entre sí para mostrar por pantalla los login names de los usuarios del sistema. Realizar dos versiones:
	a. Mostrar todos los login names por orden alfabético (cut, sort).
	b. Mostrar sólo aquéllos cuyo login name comienza por la letra “r” (cut, grep).
7. Escribir una línea de mandatos conectados entre sí para mostrar por pantalla por orden alfabético los login names de los usuarios del sistema junto con su directorio home. 
El login name del usuario estará separado de su directorio home por un tabulador (cut, sort, tr).
8. Escribir una línea de mandatos conectados entre sí para mostrar por pantalla cuántos subdirectorios hay en el directorio actual (ls, grep, wc).

	ana:~/ $ ls | grep -v "\." | wc -l  # grep -v coje lo contrario / "\." es para que seleccione los que tiene un punto / wc -l contar el numero de lineas de lo anterior
      20

    ana:~/ $ ls -F | grep "/" | wc -

    ana:~/ $ ls -l | grep "^d" | wc -l

9. Escribir una línea de mandatos conectados entre sí para mostrar por pantalla cuántos ficheroshay en el directorio actual (ls, grep, wc).

	ana:~/ $ ls | grep "\." | wc -l 


10. Escribir una línea de mandatos conectados entre sí para mostrar por pantalla sobre cuántos ficheros y directorios tenemos permiso de escritura en el directorio actual (ls, cut, grep, wc).


11. Escribir una línea de mandatos conectados entre sí para mostrar por pantalla sobre cuántos ficheros tenemos permiso de escritura en el directorio actual (ls, cut, grep, wc / find, wc).
12. Escribir una línea de mandatos conectados entre sí para mostrar por pantalla sobre cuántos directorios tenemos permiso de escritura en el directorio actual (ls, cut, grep, wc / find, wc).