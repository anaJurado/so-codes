# SISTEMAS OPERATIVOS TEMA 1 - EJERCICIOS 
# INTÉRPRETE DE MANDATOS

# EJERCICIO 9
Actividad 9 (básica): sistemas de ficheros (stat, mount, df, du, tree)
1. Ejecutar stat fichero para ver un resumen de los datos del i-nodo correspondiente a un fichero.
	ana:URJC-SO-FILES/ $ stat texto1.txt                                                                                                                                                                                             [19:45:29]
		16777220 17071363 -rw-r--r-- 1 ana staff 0 3934 "Sep 29 10:25:25 2019" "Sep 29 10:25:25 2019" "Sep 29 10:25:25 2019" "Sep 29 10:25:25 2019" 4096 8 0 texto1.txt

2. Usar mount para mostrar los sistemas de ficheros montados.
	ana:URJC-SO-FILES/ $ mount                                                                                                                                                                                                       [19:46:09]
		/dev/disk1s1 on / (apfs, local, journaled)
		devfs on /dev (devfs, local, nobrowse)
		/dev/disk1s4 on /private/var/vm (apfs, local, noexec, journaled, noatime, nobrowse)
		map -hosts on /net (autofs, nosuid, automounted, nobrowse)
		map auto_home on /home (autofs, automounted, nobrowse)
		/Users/ana/Downloads/MacDown.app on /private/var/folders/b_/4588svj56j994759k5rmhqlc0000gn/T/AppTranslocation/B10CBFB1-C719-4278-8D81-4C99941804F8 (nullfs, local, nodev, nosuid, read-only, nobrowse, mounted by ana)

3. Escribir df para mostrar el espacio libre y utilizado en los sistemas de ficheros existentes.
	ana:URJC-SO-FILES/ $ df                                                                                                                                                                                                          [19:46:12]
		Filesystem                       512-blocks      Used Available Capacity iused               ifree %iused  Mounted on
		/dev/disk1s1                      236568496 202879416  19778816    92% 1062229 9223372036853713578    0%   /
		devfs                                   381       381         0   100%     660                   0  100%   /dev
		/dev/disk1s4                      236568496  10486056  19778816    35%       5 9223372036854775802    0%   /private/var/vm
		map -hosts                                0         0         0   100%       0                   0  100%   /net
		map auto_home                             0         0         0   100%       0                   0  100%   /home
		/Users/ana/Downloads/MacDown.app  236568496 205255664  19499760    92% 1067583 9223372036853708224    0%   /private/var/folders/b_/4588svj56j994759k5rmhqlc0000gn/T/AppTranslocation/B10CBFB1-C719-4278-8D81-4C99941804F8

4. Escribir df -h para mostrar el espacio libre y utilizado en los sistemas de ficheros existentes, pero mostrando la información en un modo más amigable (-h: human readable).
	ana:URJC-SO-FILES/ $ df -h                                                                                                                                                                                                       [19:46:44]
		Filesystem                         Size   Used  Avail Capacity iused               ifree %iused  Mounted on
		/dev/disk1s1                      113Gi   97Gi  9.4Gi    92% 1062230 9223372036853713577    0%   /
		devfs                             191Ki  191Ki    0Bi   100%     660                   0  100%   /dev
		/dev/disk1s4                      113Gi  5.0Gi  9.4Gi    35%       5 9223372036854775802    0%   /private/var/vm
		map -hosts                          0Bi    0Bi    0Bi   100%       0                   0  100%   /net
		map auto_home                       0Bi    0Bi    0Bi   100%       0                   0  100%   /home
		/Users/ana/Downloads/MacDown.app  113Gi   98Gi  9.3Gi    92% 1067583 9223372036853708224    0%   /private/var/folders/b_/4588svj56j994759k5rmhqlc0000gn/T/AppTranslocation/B10CBFB1-C719-4278-8D81-4C99941804F8

5. Mostrar el espacio libre del sistema de ficheros /.
	ana:URJC-SO-FILES/ $ df /                                                                                                                                                                                                        [19:47:35]
		Filesystem   512-blocks      Used Available Capacity iused               ifree %iused  Mounted on
		/dev/disk1s1  236568496 202881216  19777016    92% 1062232 9223372036853713575    0%   /


6. Escribir du para conocer el espacio ocupado por los directorios del usuario. Repetir el mandato, pero mostrando el resultado en formato human readable.
	ana:URJC-SO-FILES/ $ du                                                                                                                                                                                                          [19:49:10]
		88	./scripts
		160	.
	
	ana:URJC-SO-FILES/ $ du -h                                                                                                                                                                                                       [19:49:28]
		 44K	./scripts
		 80K	.

7. Mediante el mandato du, mostrar el espacio ocupado por los directorios del usuario con dos niveles de profundidad.
8. Mediante el mandato du, mostrar el espacio ocupado por los directorios y los ficheros del usuario con dos niveles de profundidad, en formato human readable.


9. Usar tree para mostrar el árbol completo de directorios y ficheros a partir del directorio raíz del usuario (que es /home/alumno).
10. Usar tree para mostrar el árbol de directorios y ficheros a partir del directorio /usr, con dos niveles de profundidad.

Nota
• El mandato tree no suele venir instalado por defecto. En distribuciones Linux derivadas de Debian (como lo es Ubuntu), se puede instalar mediante la orden sudo apt-get install tree. 
La shell pedirá la palabra clave del usuario antes de proceder a la instalación.



# EJERCICIO 10
Actividad 10 (básica): manejo de directorios (cd, mkdir, rmdir, ls, tree, pwd)

1. Se pretende crear la siguiente estructura de directorios a partir del directorio home del usuario:
	 Datos
	  Inversiones
	  Nominas
	 └── Stocks
	 Textos
	  Cartas
	   Avisos
	  └── Circulares
	 └── Informes

	a. Posicionarse en el directorio home del usuario.
	b. Crear el directorio Datos.
	c. Entrar dentro del directorio Datos.
	d. Comprobar que estamos en el directorio Datos.
	e. Listar todos los ficheros del directorio Datos, incluyendo los ocultos.
	f. Dentro del directorio Datos, crear los directorios Inversiones, Nominas y Stocks.
	g. Listar de nuevo todos los ficheros del directorio Datos, incluyendo los ocultos y mostrando la información en formato largo.
	h. Volver al directorio home del usuario. Comprobar que estamos en él.
	i. Crear el directorio Textos.
	j. Entrar en el directorio Textos.
	k. Dentro del directorio Textos, crear los directorios Cartas e Informes.
	l. Entrar en el directorio Cartas.
	m. Dentro del mismo, crear los directorios Avisos y Circulares.
	n. Volver al directorio home del usuario.
	o. Usar el mandato tree para comprobar que la estructura de directorios creada es correcta.


2. Cambiar el directorio de trabajo actual a los siguientes directorios, comprobando con pwd que todos los cambios se hacen correctamente:

	§ path absoluto: ruta completa. Ejemplo: /usr/local/bin/bash
	§ path relativo: ruta a partir de un punto concreto.
	Ejemplo: bin/bash ../lib/modules


	a. Cambiar a /usr/bin.
	b. Cambiar a /home.
	c. Cambiar al directorio home del usuario utilizando $HOME.
	d. Cambiar a Nominas utilizando una ruta relativa.
	e. Cambiar a Inversiones utilizando una ruta relativa.
	f. Cambiar a Avisos utilizando una ruta relativa.
	g. Cambiar al directorio home del usuario utilizando el comando cd sin argumentos.
	h. Cambiar a Circulares utilizando una ruta absoluta.
	i. Cambiar a la raíz o home del usuario.


3. Siendo el directorio de trabajo actual el directorio raíz del usuario, y sin moverse de él:
	a. Mostrar la lista de ficheros del directorio raíz del usuario recursivamente, con todos los ficheros de sus subdirectorios.
	b. Mostrar la lista de ficheros del directorio /usr/bin (colgando de la raíz del sistema).
	c. Mostrar la lista de ficheros (incluidos los ocultos) del directorio Cartas.
	d. Mostrar la lista de ficheros (con todos sus detalles) del directorio tmp que cuelga de la raíz del sistema.


4. Cambiar el directorio de trabajo actual al directorio Informes, y sin moverse de él:
	a. Mostrar la lista de ficheros del directorio Cartas.
	b. Mostrar la lista de ficheros del directorio padre de Informes.
	c. Mostrar la lista de ficheros del directorio Nominas, con todos sus detalles e incluyendo los ocultos.


5. Borrar los directorios Nominas y Cartas (recordar que para borrar un directorio antes hay que vaciarlo).


# EJERCICIO 11
Actividad 11 (intermedia): manipulación de ficheros (touch, nano, cp, ln, mv, rm)
Al ejecutar cada acción indicada en esta actividad, se comprobará con los mandatos ls, cat o less quela acción se ha realizado correctamente antes de pasar a la siguiente.
1. Mediante el mandato touch, crear en Stocks un fichero denominado Trimestre.17.1.txt vacío.
2. Editar el fichero recién creado para que contenga lo siguiente:

	2017 - Primer trimestre 
	---------------------
	Enero 1500
	Febrero 3350
	Marzo 4520

3. Copiar el fichero anterior, en la misma carpeta con el nombre Trimestre.17.todos.txt.
4. Copiar el fichero anterior, en la misma carpeta con el nombre Trimestre.17.antiguos.txt.
5. Copiar el fichero anterior, en la misma carpeta con el nombre Trimestre.18.1.txt.
6. Editar este fichero y cambiar el año por 2018.
7. Copiar el fichero anterior, en la misma carpeta con el nombre Trimestre.18.2.txt.
8. Editar este fichero y cambiar la palabra Primer por Segundo, y los meses por Abril, Mayo y Junio.
9. Volver a copiar el fichero anterior, en la misma carpeta con el nombre Trimestre.18.3.txt.
10. Editar este fichero y cambiar la palabra Segundo por Tercero, y los meses por Julio, Agosto y Septiembre.
11. Volver a copiar el fichero anterior, en la misma carpeta con el nombre Trimestre.18.4.txt.
12. Editar este fichero y cambiar la palabra Tercero por Cuarto, y los meses por Octubre, Noviembre y Diciembre.
13. Volver a copiar el fichero anterior, en la misma carpeta con el nombre borrador.txt.
14. Cambiar el nombre de este último fichero para quitar la extensión, de manera que se llame borrador.
15. Mover el fichero borrador a la carpeta padre de Stocks.
16. Listar los ficheros del directorio padre de Stocks con información extendida. Anotar el número de enlaces a borrador.
17. Dentro de la carpeta Stocks, crear un enlace físico (hard link) llamado enlacefisico que apunte a borrador.
18. Listar de nuevo los ficheros del directorio padre de Stocks con información extendida. Comparar el número de enlaces que tiene ahora borrador.
19. Listar los ficheros del directorio Stocks con información extendida. Anotar el número de enlaces que tiene enlacefisico.
20. Crear un enlace simbólico (symbolic link) al fichero borrador llamado enlacesimbolico dentro de la carpeta Stocks.
21. Listar de nuevo los ficheros del directorio padre de Stocks con información extendida. Comparar el número de enlaces que tiene ahora el fichero borrador.
22. Listar los ficheros del directorio Stocks con información extendida. Anotar el número de enlaces que tienen enlacefisico y enlacesimbolico.
23. Mostrar el contenido de borrador, enlacefisico y enlacesimbolico.
24. Borrar el fichero borrador.
25. Listar los ficheros del directorio Stocks con información extendida. ¿Qué se muestra ahora? (fijarse en el número de enlaces y en el enlace simbólico).
26. Mostrar el contenido de enlacefisico y enlacesimbolico.
27. Borrar enlacefisico y enlacesimbolico.
28. Ir al directorio /home/alumno, y utilizar el mandato tar para crear un archivo comprimido llamado archivo.tgz que contenga todo lo que se encuentra bajo los directorios Datos y Textos.
29. Crear un directorio llamado pruebatar.
30. Copiar archivo.tgz en pruebatar con su mismo nombre.
31. Entrar en pruebatar, y descomprimir archivo.tgz.
32. Usar tree, ls y cat para comprobar que lo que se ha descomprimido coincide con los contenidos originales bajo Datos y Textos.
33. Volver al directorio /home/alumno y, ejecutando un solo mandato, borrar recursivamente el directorio pruebatar.
34. Copiar todos los ficheros acabados en .txt en Inversiones.
35. Borrar los ficheros que tienen por nombre Trimestre.17 seguido de cualquier cosa.
36. Borrar los ficheros que tienen por nombre Trimestre.18, seguido de un uno o un dos y acabados en .txt.

Nota
• Para realizar los pasos 34, 35 y 36 es preciso estudiar cómo se realizan las sustituciones de nombre de fichero.






#############
# SO TEMA 2 #  Ejercicios de comandos básicos de Linux
#############
------------------------------------------
 1. Manipulando directorios
------------------------------------------

	Crear a partir del directorio home del usuario la siguiente estructura de directorios:
		• Textos
			• Informes
			• Cartas
				• Avisos
				• Circulares
		• Datos
			• Nominas
			• Stocks
			• Inversiones

	CÓDIGO

	ana@ana-VirtualBox:~$ cd Desktop/
	ana@ana-VirtualBox:~/Desktop$ mkdir SO-T2-EJERCICIOS-E1
	ana@ana-VirtualBox:~/Desktop$ cd SO-T2-EJERCICIOS-E1/
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1$ mkdir textos; mkdir datos
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1$ cd textos/
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos$ mkdir informes; mkdir cartas
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos$ cd cartas/
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos/cartas$ mkdir avisos; mkdir circulares
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos/cartas$ cd ..
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos$ cd ..
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1$ ls
	datos  textos
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1$ cd datos
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/datos$ mkdir nominas; mkdir stocks; mkdir inversiones
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/datos$ ls
	inversiones  nominas  stocks
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/datos$
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/datos$ cd ..
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1$ ls
	datos  textos
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1$ cd datos
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/datos$ ls
	inversiones  nominas  stocks
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/datos$ cd ..
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1$ cd textos/
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos$ ls
	cartas  informes
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos$ cd cartas/
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos/cartas$ ls
	avisos  circulares
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos/cartas$

----------------------------------------------------------------------------------------------


Cambiar el directorio de trabajo actual a los siguiente directorios, comprobando con pwd que todos los
cambios se hacen correctamente:

	1. Cambiar a /usr/bin

	# Llego al directorio raíz
		ana@ana-VirtualBox:~$ pwd
		/home/ana
		ana@ana-VirtualBox:~$ cd ..
		ana@ana-VirtualBox:/home$ pwd
		/home
		ana@ana-VirtualBox:/home$ cd ..
		ana@ana-VirtualBox:/$ pwd
		/									

	# Cambio a USR/BIN
		ana@ana-VirtualBox:/$ cd usr/bin
		ana@ana-VirtualBox:/usr/bin$


	2. Cambiar a /home

	cd home

	3. Cambiar al directorio home del usuario utilizando $HOME 

	cd $HOME

	4. Cambiar a Nominas utilizando una ruta relativa

	ana@ana-VirtualBox:~$ pwd
	/home/ana
	ana@ana-VirtualBox:~$ cd Desktop/SO-T2-EJERCICIOS-E1/
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1$ ls
	datos  textos
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1$ cd datos
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/datos$ ls
	inversiones  nominas  stocks
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/datos$ cd nominas


	5. Cambiar a Inversiones utilizando una ruta relativa

	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/datos/nominas$ pwd
	/home/ana/Desktop/SO-T2-EJERCICIOS-E1/datos/nominas
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/datos/nominas$ cd ..
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/datos$ ls
	inversiones  nominas  stocks
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/datos$ cd inversiones


	6. Cambiar a Avisos utilizando una ruta relativa

	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/datos/inversiones$ pwd
	/home/ana/Desktop/SO-T2-EJERCICIOS-E1/datos/inversiones
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/datos/inversiones$ cd ..
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/datos$ cd ..
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1$ ls
	datos  textos
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1$ cd textos/
	cartas/   informes/
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1$ cd textos/cartas/avisos
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos/cartas/avisos$ pwd
	/home/ana/Desktop/SO-T2-EJERCICIOS-E1/textos/cartas/avisos


	7. Cambiar al directorio home del usuario utilizando el comando cd sin argumentos

	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos/cartas/avisos$ pwd
	/home/ana/Desktop/SO-T2-EJERCICIOS-E1/textos/cartas/avisos
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos/cartas/avisos$ cd
	ana@ana-VirtualBox:~$ pwd
	/home/ana


	8. Cambiar a Circulares utilizando una ruta absoluta

	ana@ana-VirtualBox:~$ pwd
	/home/ana
	ana@ana-VirtualBox:~$ cd Desktop/SO-T2-EJERCICIOS-E1/
	datos/  textos/
	ana@ana-VirtualBox:~$ cd Desktop/SO-T2-EJERCICIOS-E1/
	datos/  textos/
	ana@ana-VirtualBox:~$ cd Desktop/SO-T2-EJERCICIOS-E1/datos/
	inversiones/ nominas/     stocks/      
	ana@ana-VirtualBox:~$ cd Desktop/SO-T2-EJERCICIOS-E1/textos/
	cartas/   informes/
	ana@ana-VirtualBox:~$ cd Desktop/SO-T2-EJERCICIOS-E1/textos/cartas/
	avisos/     circulares/
	ana@ana-VirtualBox:~$ cd Desktop/SO-T2-EJERCICIOS-E1/textos/cartas/circulares/
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos/cartas/circulares$ pwd
	/home/ana/Desktop/SO-T2-EJERCICIOS-E1/textos/cartas/circulares
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos/cartas/circulares$


	9. Cambiar a la raíz o home del usuario
	ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos/cartas/circulares$ cd
	ana@ana-VirtualBox:~$ pwd
	/home/ana
	ana@ana-VirtualBox:~$

-------------------------------------------------------------------------------------------------------------------------

Siendo el directorio de trabajo actual el directorio raíz del usuario, y sin moverse de él:
	
	¿?¿?¿?
	1. Mostrar la lista de ficheros del directorio raíz del usuario recursivamente, con todos los ficheros de sus subdirectorios.

		ana@ana-VirtualBox:~$ ls -R | grep ".*"
		ana@ana-VirtualBox:~$ ls -R 

	¿?¿?¿?
	2. Mostrar la lista de ficheros del directorio /usr/bin (colgando de la raíz del sistema).

		1º Voy a la raíz del sistema
			ana@ana-VirtualBox:~$ pwd
			/home/ana
			ana@ana-VirtualBox:~$ cd ..
			ana@ana-VirtualBox:/home$ cd ..
		2º Compruebo que estoy en la raíz del sistema
			ana@ana-VirtualBox:/$ pwd
			/
		3º Muestro la lista de ficheros del directorio
			ana@ana-VirtualBox:/$ ls ./usr/bin


		Con todos los ficheros de sus subdirectorios:

		ana@ana-VirtualBox:/$ ls -R | grep /usr/bin
		ls: cannot open directory './etc/cups/ssl': Permission denied
		ls: cannot open directory './etc/polkit-1/localauthority': Permission denied
		ls: cannot open directory './etc/ssl/private': Permission denied
		ls: cannot open directory './lost+found': Permission denied


	3. Mostrar la lista de ficheros (incluidos los ocultos) del directorio Cartas.

		ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1/textos$ ls -a ./cartas
		.  ..  avisos  circulares


	4. Mostrar la lista de ficheros (con todos sus detalles) del directorio tmp que cuelga de la raiz del sistema.

		# Llegar a la raíz del sistema
		ana@ana-VirtualBox:~/Desktop/SO-T2-EJERCICIOS-E1$ cd $HOME
		ana@ana-VirtualBox:~$ pwd
		/home/ana
		ana@ana-VirtualBox:~$ cd ..
		ana@ana-VirtualBox:/home$ cd ..
		ana@ana-VirtualBox:/$ pwd
		/
	
		# Comando ls -l 
		ana@ana-VirtualBox:/$ ls -l ./tmp
		total 36
		-rw------- 1 ana  ana     0 sep 23 20:07 config-err-OgDaIB
		drwx------ 2 ana  ana  4096 sep 23 21:21 lu3304f6xnxm.tmp
		srwxrwxr-x 1 ana  ana     0 sep 23 20:22 OSL_PIPE_1000_SingleOfficeIPC_833d3a5174f7c73b0b3dd261bef11
		drwx------ 2 ana  ana  4096 sep 23 20:07 ssh-AjjRq1MJOFnN
		drwx------ 3 root root 4096 sep 23 20:07 systemd-private-46191c2418ec4767bbb6d106a21ae1cd-bolt.service-h5SM8O
		drwx------ 3 root root 4096 sep 23 20:07 systemd-private-46191c2418ec4767bbb6d106a21ae1cd-colord.service-tB8Ghk
		drwx------ 3 root root 4096 sep 23 20:07 systemd-private-46191c2418ec4767bbb6d106a21ae1cd-fwupd.service-MRp2sq
		drwx------ 3 root root 4096 sep 23 20:07 systemd-private-46191c2418ec4767bbb6d106a21ae1cd-rtkit-daemon.service-8oUHL0
		drwx------ 3 root root 4096 sep 23 20:07 systemd-private-46191c2418ec4767bbb6d106a21ae1cd-systemd-resolved.service-hLqTsM
		drwx------ 3 root root 4096 sep 23 20:07 systemd-private-46191c2418ec4767bbb6d106a21ae1cd-systemd-timesyncd.service-Bi6IwS
		drwx------ 2 ana  ana  4096 sep 23 21:16 thunderbird_ana


-------------------------------------------------------------------------------------------------------------------------

Cambiar el directorio de trabajo actual al directorio Cartas y sin moverse de él:

	# ME PONGO EN EL DIRECTORIO CARTAS: ana@ana-VirtualBox:~/Desktop/textos/cartas$ 

	1. Mostrar la lista de ficheros del directorio Informes.

		ana@ana-VirtualBox:~/Desktop/textos/cartas$ ls ../informes   # Con ls .. puede mostrar la lista de ficheros del directorio padre


	2. Mostrar la lista de ficheros del directorio padre de Cartas.

		ana@ana-VirtualBox:~/Desktop/textos/cartas$ ls ..
		cartas  informes

	3. Mostrar la lista de ficheros del directorio Nominas.

		ana@ana-VirtualBox:~/Desktop/textos/cartas$ ls ../../datos
		inversiones  nominas  stocks
		ana@ana-VirtualBox:~/Desktop/textos/cartas$ ls ../../datos/nominas
		ana@ana-VirtualBox:~/Desktop/textos/cartas$ 


	Borrar los directorios Nominas y Cartas (Recordar que para borrar un directorio antes hay que
	vaciarlo).
	# Para borrar un directorio antes hay que vaciarlo... ¿?¿?¿?

	Borrar el directorio NOMINAS:
		ana@ana-VirtualBox:~/Desktop/textos/cartas$ rm -i ../../datos/nominas
		rm: cannot remove '../../datos/nominas': Is a directory						# Si no ponemos -r (Eliminar directorios y sus contenidos recursivamente)
																					# no nos deja borrar nada.
		ana@ana-VirtualBox:~/Desktop/textos/cartas$ rm -i -r  ../../datos/nominas
		rm: remove directory '../../datos/nominas'? y
		ana@ana-VirtualBox:~/Desktop/textos/cartas$ ls ../../datos/
		inversiones  stocks
		ana@ana-VirtualBox:~/Desktop/textos/cartas$ 


	Borrar el directorio CARTAS:
		ana@ana-VirtualBox:~/Desktop/textos/cartas$ rm ../cartas
		rm: cannot remove '../cartas': Is a directory
		ana@ana-VirtualBox:~/Desktop/textos/cartas$ rm -ri ../cartas
		rm: descend into directory '../cartas'? y
		rm: remove directory '../cartas/circulares'? y
		rm: remove directory '../cartas/avisos'? y
		rm: remove directory '../cartas'? y
		ana@ana-VirtualBox:~/Desktop/textos/cartas$ 


¿?¿?¿? ----------------------------------------------------------------------------------------------------

DUDAS EJERCICIO 1  (Buscar ¿?¿?¿? en el documento)

- ¿Hay una forma sencilla de llegar a root?

- ¿Mostrar la lista de ficheros del directorio raíz del usuario recursivamente: ls -R ?

- Rutas relativas y rutas absolutas:
	ABSOLUTO (ruta completa): 							/usr/local/bin/bash
	RELATIVO (ruta a partir de un punto concreto) : 	. "directorio actual" .. "directorio padre"

¿?¿?¿? ----------------------------------------------------------------------------------------------------


------------------------------------------
2. Manipulación de ficheros
------------------------------------------

Crear en Stocks un fichero denominado Trimestre.05.1.txt que contenga lo siguiente:

2005 Primer trimestre
--------------
Enero 1500
Febrero 3350
Marzo 4520
-------------

	1º Creamos el archivo vacío (touch)
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ pwd
		/home/ana/Desktop/datos/stocks
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ touch trimestre.05.1.txt
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls
		trimestre.05.1.txt

		Crear y editar el archivo (cat)
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ cat > trimestre.05.1.txt
		2005 Primer trimestre
		--------------
		Enero 1500
		Febrero 3350
		Marzo 4520
		-------------
		^Z
		[1]+  Stopped                 cat > gatitos.txt

		# Nueva línea ENTER - Guardar y cerrar ctr+z

		# Para asegurarte de que has creado el archivo
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls -l trimestre.05.1.txt
		-rw-r--r-- 1 ana ana 0 sep 24 21:17 trimestre.05.1.txt


	2º EScribimos dentro del archivo	
		GEDIT - Abre una especie de editor
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ gedit trimestre.05.1.txt

		NANO - Editas en la misma terminal. Para GUARDAR: ctr+o Para SALIR: ctr+x
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ nano trimestre.05.1.txt


Ejecutar las siguientes acciones comprobando con los comandos ls o cat que cada una se va ejecutando correctamente antes de pasar a la siguiente:

	1. Copiar el fichero anterior, en la misma carpeta con el nombre Trimestre.04.todos.txt

		ana@ana-VirtualBox:~/Desktop/datos/stocks$ cp trimestre.05.1.txt trimestre.04.todos.txt
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls
		trimestre.04.todos.txt  trimestre.05.1.txt


	2. Copiar el fichero anterior, en la misma carpeta con el nombre Trimestre.04.antiguos.txt

		ana@ana-VirtualBox:~/Desktop/datos/stocks$ cp  trimestre.04.todos.txt trimestre.04.antiguos.txt
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls
		trimestre.04.antiguos.txt  trimestre.04.todos.txt  trimestre.05.1.txt


	3. Copiar el fichero anterior, en la misma carpeta con el nombre Trimestre.05.2.txt

		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls
		trimestre.04.antiguos.txt  trimestre.04.todos.txt  trimestre.05.1.txt  trimestre.05.2.txt


	4. Editar este fichero y cambiar la palabra "Primer" por "Segundo", y los meses por "Abril","Mayo", "Junio"

		ana@ana-VirtualBox:~/Desktop/datos/stocks$ nano trimestre.05.2.txt
		Edito
		Guardo: ctr+o
		Salgo: ctr+x


	5. Volver a copiar el fichero anterior, en la misma carpeta con el nombre Trimestre.05.3.txt

		ana@ana-VirtualBox:~/Desktop/datos/stocks$ cp trimestre.05.2.txt trimestre.05.3.txt
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls
		trimestre.04.antiguos.txt  trimestre.04.todos.txt  trimestre.05.1.txt  trimestre.05.2.txt  trimestre.05.3.txt


	6. Editar este fichero y cambiar la palabra "Segundo por "Tercero", y los meses por "Julio", "Agosto", "Septiembre"
		
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ nano trimestre.05.3.txt
		Edito
		Guardo: ctr+o
		Salgo: ctr+x


	7. Volver a copiar el fichero anterior, en la misma carpeta con el nombre Trimestre.05.4.txt

		ana@ana-VirtualBox:~/Desktop/datos/stocks$ cp  trimestre.05.3.txt trimestre.05.4.txt
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls
		trimestre.04.antiguos.txt  trimestre.05.1.txt  trimestre.05.3.txt
		trimestre.04.todos.txt     trimestre.05.2.txt  trimestre.05.4.txt



	8. Editar este fichero y cambiar la palabra "Tercero por "Cuarto", y los meses por "Octubre", "Noviembre", "Diciembre"

		ana@ana-VirtualBox:~/Desktop/datos/stocks$ nano trimestre.05.4.txt
		Edito
		Guardo: ctr+o
		Salgo: ctr+x

	9. Volver a copiar el fichero anterior, en la misma carpeta con el nombre borrador.txt

		ana@ana-VirtualBox:~/Desktop/datos/stocks$ cp trimestre.05.4.txt borrador.txt
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls
		borrador.txt               trimestre.04.todos.txt  trimestre.05.2.txt  trimestre.05.4.txt
		trimestre.04.antiguos.txt  trimestre.05.1.txt      trimestre.05.3.txt


	10.Cambiar el nombre de este último fichero para quitar la extensión, de manera que se llame borrador
		
		# Con NANO lo que hacemos es una copia con nombre distinto

		ana@ana-VirtualBox:~/Desktop/datos/stocks$ nano borrador.txt
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls
		borrador      trimestre.04.antiguos.txt  trimestre.05.1.txt  trimestre.05.3.txt
		borrador.txt  trimestre.04.todos.txt     trimestre.05.2.txt  trimestre.05.4.txt


		# EL comnado RENAME habría que instalarlo

		ana@ana-VirtualBox:~/Desktop/datos/stocks$ rename -v borrador.txt borrador

		Command 'rename' not found, but can be installed with:

		sudo apt install rename


		# Renombramos con el comando MV (MOVE)

		ana@ana-VirtualBox:~/Desktop/datos/stocks$ mv borrador.txt borrador
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls
		borrador                   trimestre.04.todos.txt  trimestre.05.2.txt  trimestre.05.4.txt
		trimestre.04.antiguos.txt  trimestre.05.1.txt      trimestre.05.3.txt


	11.Copiar todos los ficheros acabados en .txt en Inversiones.

		ana@ana-VirtualBox:~/Desktop/datos/stocks$ PWD="$(pwd)"
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ echo $PWD
		/home/ana/Desktop/datos/stocks
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ cp -r $PWD ../inversiones 		# Con esto COPIA el directorio entero en Inversiones
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls ../inversiones
		stocks

		¿?¿?¿?

		# Usando FIND los encuentro
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ find . -name "*.txt"
		./trimestre.05.4.txt
		./trimestre.05.3.txt
		./trimestre.04.antiguos.txt
		./trimestre.04.todos.txt
		./trimestre.05.2.txt
		./trimestre.05.1.txt

		# Usando conjuntamente el FIND y el CP

		ana@ana-VirtualBox:~/Desktop/datos/stocks$ find . -name "*.txt"
		./trimestre.05.4.txt
		./trimestre.05.3.txt
		./trimestre.04.antiguos.txt
		./trimestre.04.todos.txt
		./trimestre.05.2.txt
		./trimestre.05.1.txt
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ARCHIVOS="$(find . -name "*.txt")"
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ echo $ARCHIVOS
		./trimestre.05.4.txt ./trimestre.05.3.txt ./trimestre.04.antiguos.txt ./trimestre.04.todos.txt ./trimestre.05.2.txt ./trimestre.05.1.txt
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ cp $ARCHIVOS ../inversiones
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls ../inversiones
		trimestre.04.antiguos.txt  trimestre.05.1.txt  trimestre.05.3.txt
		trimestre.04.todos.txt     trimestre.05.2.txt  trimestre.05.4.txt


	12.Mover el fichero borrador a la carpeta padre de Stocks.

		# MOVER, que no copiar...
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ mv borrador ../
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls ..
		borrador  inversiones  stocks


	13.Borrar los ficheros que tienen por nombre Trimestre.04, seguido de cualquier cosa.

		1º Veo los que hay
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls
		trimestre.04.antiguos.txt  trimestre.05.1.txt  trimestre.05.3.txt
		trimestre.04.todos.txt     trimestre.05.2.txt  trimestre.05.4.txt

		2º Los encuentro con un FIND
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ find . -name "trimestre.04*"
		./trimestre.04.antiguos.txt
		./trimestre.04.todos.txt

		3º Guardo en una variable el FIND
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ARCHIVOS="$(find . -name "trimestre.04*")"
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ echo $ARCHIVOS
		./trimestre.04.antiguos.txt ./trimestre.04.todos.txt


		4º Borro usando la variable 
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ rm -i $ARCHIVOS
		rm: remove regular file './trimestre.04.antiguos.txt'? Y
		rm: remove regular file './trimestre.04.todos.txt'? Y
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls
		trimestre.05.1.txt  trimestre.05.2.txt  trimestre.05.3.txt  trimestre.05.4.txt


	14.Borrar los ficheros que tienen por nombre Trimestre.05, seguido de un uno o un dos y acabados en .txt.

		ana@ana-VirtualBox:~/Desktop/datos/stocks$ find . -name "trimestre.05.[ 1 | 2 ].txt" 
		./trimestre.05.2.txt
		./trimestre.05.1.txt
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ARCHIVOS="$(find . -name "trimestre.05.[ 1 | 2 ].txt")"
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ echo $ARCHIVOS
		./trimestre.05.2.txt ./trimestre.05.1.txt
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ rm -i $ARCHIVOS
		rm: remove regular file './trimestre.05.2.txt'? Y
		rm: remove regular file './trimestre.05.1.txt'? Y
		ana@ana-VirtualBox:~/Desktop/datos/stocks$ ls
		trimestre.05.3.txt  trimestre.05.4.txt


Cambiar los permisos del fichero borrador para que:

	1. El propio usuario no pueda leerlo. (Asegurarse de que no se puede ver su contenido con cat).
	2. Volver a darle permiso de lectura para el propio usuario.
	3. Darle permiso de modificación a los usuario del grupo.
	4. Quitarle permiso de lectura a otros usuarios.
	5. Comprobar con ls l  que los permisos son rwrw



------------------------------------------
3. Filtros, redirecciones y tuberías
------------------------------------------

	Utilizando la redirección ( > ):
		1. Volcar la lista de ficheros de /usr/bin en un fichero denominado listaEjecutables. 



	Utilizar el comando more para:
		1. Ver el contenido del fichero listaEjecutables.



	Utilizar una tubería ( | ) para:
		1. Ver la lista de ficheros de /usr/bin poco a poco, directamente, sin usar un fichero.


		2. Filtrar la lista de nombres de ficheros del directorio /usr/bin, para ver sólo los que contengan "m", sin tener que usar un fichero.

		


######################################################################
##																	##
##                        TEORÍA AÑADIDA                            ##
##																	##
######################################################################

COMANDO LS (Lista los archivos)

ls -a   # Nos muestra los archivos y directorios dentro del directorio actual, incluyendo los archivos y directorios ocultos.

ls -t   # Ordena los archivos por fecha de modificación.

ls -X   # Ordena los archivos por extensión.
 
ls -l   # Muestra toda la información: usuario, grupo, permisos, tamaño, fecha y hora de creación.

ls -lh  # Muestra la misma información que ls -l pero con las unidades de tamaño en KB, MB, etc.

ls -R   # Muestra el contenido de todos los subdirectorios de forma recursiva.

ls -S   # Ordena los resultados por tamaño de archivo.


COMANDO RM (Borrar archivos)

-f , –force: 	Ignora los archivos no inexistentes, y nunca los solicite antes de eliminarlos.

-i: 	Preguntar antes de cada eliminación.

-I: 	Indicar una vez antes de eliminar más de tres archivos, o cuando lo quite de forma recursiva. Esta opción es menos intrusiva que -i , pero aún brinda protección contra la mayoría de los errores.

–one-file-system: 	Al eliminar una jerarquía de forma recursiva, omita cualquier directorio que esté en un sistema de archivos 						diferente del correspondiente al argumento de la línea de comando.

–no-preserve-root: 	No trate ” / ” (el directorio raíz ) de ninguna manera especial.

–preserve-root: 	No elimine ” / ” (el directorio raíz), que es el comportamiento predeterminado.

-r ,-R ,–recursive: 	Eliminar directorios y sus contenidos recursivamente.

-d ,–dir: 	Eliminar directorios vacíos. Esta opción nos permite eliminar un directorio sin especificar -r / -R / –recursive , 		 			 ..siempre que el directorio esté vacío. En otras palabras, rm -d es equivalente a usar rmdir.

-v , –verbose: 		Modo detallado; explicar en todo momento las acciones que se van ejecutando.

–help: 			Muestra un mensaje de ayuda del comando.

–version: 		Muestra información de la versión correspondiente.

