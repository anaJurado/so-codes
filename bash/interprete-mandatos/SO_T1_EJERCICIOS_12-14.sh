# SISTEMAS OPERATIVOS TEMA 1 - EJERCICIOS 
# INTÉRPRETE DE MANDATOS

Actividad 12 (intermedia): filtros (wc, cut, head, tail, sort, tr, sed, cat, more, tee)
1. Mediante el mandato wc, contar las líneas, las palabras y los bytes del fichero /etc/passwd. Contar sólo las líneas del fichero. Contar sólo las palabras del fichero. Contar sólo sus bytes. Contar sus líneas y sus palabras.
	ana:// $ wc ../etc/passwd                                                                                                                                                                                                        [22:34:37]
     108     292    6804 ../etc/passwd

2. Mediante el mandato cut, mostrar el uid de todos los usuarios del sistema, junto con su directorio raíz y la shell que se arranca por defecto cuando abren un terminal.

ana:// $ cut -d : -f1 ../etc/passwd     # -d es el separador :  -f para el número de columna                                                                                                                                                                                         [22:35:22]
		##
		# User Database
		#
		# Note that this file is consulted directly only when the system is running
		# in single-user mode.  At other times this information is provided by
		# Open Directory.
		#
		# See the opendirectoryd(8) man page for additional information about
		# Open Directory.
		##
		nobody
		root
		daemon
		_uucp
		_taskgated
		_networkd

3. Mediante el mandato head, mostrar los datos de los cinco primeros usuarios del sistema que aparecen en /etc/passwd. Mostrar todos los usuarios menos los cinco últimos. Mostrar los 100 primeros bytes del fichero.
	ana:// $ head -n 5 ../etc/passwd    # -n es para el número de líneas                                                                                                                                                                     [22:38:16]
		##
		# User Database
		#
		# Note that this file is consulted directly only when the system is running
		# in single-user mode.  At other times this information is provided by
	ana:// $ head -c 100 ../etc/passwd    # -c es para el número de bytes                                                                                                                                                                                           [22:38:21]
		##
		# User Database
		#
		# Note that this file is consulted directly only when the system is running
		# %

4. Mediante el mandato tail, mostrar los datos de los cinco últimos usuarios del sistema que aparecen en /etc/passwd. Mostrar todos los usuarios menos los cinco primeros. Mostrar los 100 últimos bytes del fichero.
	ana:// $ tail -n 5 ../etc/passwd                                                                                                                                                                                                 [22:40:09]
		_cmiodalassistants:*:262:262:CoreMedia IO Assistants User:/var/db/cmiodalassistants:/usr/bin/false
		_analyticsd:*:263:263:Analytics Daemon:/var/db/analyticsd:/usr/bin/false
		_fpsd:*:265:265:FPS Daemon:/var/db/fpsd:/usr/bin/false
		_timed:*:266:266:Time Sync Daemon:/var/db/timed:/usr/bin/false
		_reportmemoryexception:*:269:269:ReportMemoryException:/var/db/reportmemoryexception:/usr/bin/false

5. Usar el mandato sort para mostrar todas las líneas del fichero /etc/passwd ordenadas por orden alfabético. Mostrarlas por orden alfabético inverso.
	ana:// $ sort ../etc/passwd
	ana:// $ sort -r ../etc/passwd

6. Mediante el mandato tr, reemplazar todas las letras ‘x’ introducidas a través de la entrada estándar por ‘X’, las ‘y’ por ‘Y’ y las ‘z’ por ‘Z’ (finalizar la introducción de líneas por la entrada estándar pulsando Ctrl D).
	ana:// $  tr "[x-z]" "[X-Z]"                                                                                                                                                                                                     [22:50:04]
		abcxyokz x y z dref abcXYokZ X Y Z dref

	ana:// $ echo  "asyfztrtodxyz" | tr "[x-z]" "[X-Z]"                                                                                                                                                                              [22:49:57]
		asYfZtrtodXYZ

7. Mediante el mandato tr, reemplazar todas las letras minúsculas introducidas a través de la entrada estándar por mayúsculas (finalizar la introducción de líneas de la entrada estándar pulsando Ctrl D).
	ana:// $ tr "[:lower:]" "[:upper:]"                                                                                                                                                                                              [22:52:21]
		abc ABC aEiOu ABC ABC AEIOU

	ana:// $ tr "[a-z]" "[A-Z]"                                                                                                                                                                                                      [22:53:12]
		hOLA CARAcOLA HOLA CARACOLA %
8. Mediante el mandato sed, mostrar el contenido del fichero /etc/passwd, pero reemplazando la letra ‘a’ por ‘AAA’. Repetir lo anterior, pero ahora reemplazando ‘sys’ por ‘SYSTEM’.
	ana:// $ sed s/a/AAA/g ../etc/passwd                                                                                                                                                                                             [22:53:56]
		##
		# User DAAAtAAAbAAAse
		#
		# Note thAAAt this file is consulted directly only when the system is running
		# in single-user mode.  At other times this informAAAtion is provided by
		# Open Directory.
		#
		# See the opendirectoryd(8) mAAAn pAAAge for AAAdditionAAAl informAAAtion AAAbout
		# Open Directory.
		##
		nobody:*:-2:-2:SUnprivileged User:/vAAAr/empty:/usr/bin/fAAAlse
		root:*:0:0:
9. Mostrar el contenido del fichero /etc/passwd. Volver a mostrar el contenido del mismo fichero, pero página a página.
	cat less more
10. Copiar la entrada estándar en la salida estándar, y al mismo tiempo guardarla en disco en el fichero /home/alumno/copia.
		ana:~/ $ echo "HOLA" | tee texto.txt                                                                                                                                                                                             [23:08:12]
			HOLA
		ana:~/ $ cat texto.txt                                                                                                                                                                                                           [23:08:22]
			HOLA

		# MACHACA LO ANTERIOR		
		ana:~/ $ wc result2  | tee texto.txt                                                                                                                                                                                             [23:08:57]
       		1       4      37 result2
		ana:~/ $ cat texto.txt                                                                                                                                                                                                           [23:09:21]
       		1       4      37 result2

       	# SI QUEREMOS AÑADIR A LO QUE YA HAY -a (append)
       	ana:~/ $ wc result  | tee -a texto.txt                                                                                                                                                                                           [23:10:32]
       		1       4      37 result                                                                                                                                                                                                             [23:10:46]
		ana:~/ $ cat texto.txt                                                                                                                                                                                                           [23:10:54]
       		1       4      37 result2
       		1       4      37 result



Actividad 13 (intermedia): búsquedas en ficheros (grep)
1. Mostrar las líneas del fichero /etc/passwd que contengan la tira de caracteres root.
	ana:// $ cat /etc/passwd | grep "root"                                                                                                                                            [23:20:57]
		root:*:0:0:System Administrator:/var/root:/bin/sh
		daemon:*:1:1:System Services:/var/root:/usr/bin/false
		_cvmsroot:*:212:212:CVMS Root:/var/empty:/usr/bin/false

2. Mostrar las líneas del fichero /etc/passwd que comiencen por r.
	ana:// $ cat /etc/passwd | grep "^r"                                                                                                                                              [23:21:40]
		root:*:0:0:System Administrator:/var/root:/bin/sh

3. Mostrar las líneas del fichero /etc/passwd que terminen por bash.

	ana:// $ cat /etc/passwd | grep "bash$"                                                                                                                                           [23:23:22]
		_mbsetupuser:*:248:248:Setup User:/var/setup:/bin/bash

4. Mostrar las líneas del fichero /usr/share/dict/words que contengan palabras de cuatro letras que comiencen por ‘c’ y terminen por ‘h’.

	ana:~/ $ cat grep_text.txt                                                                                                                                                        [23:29:41]
		coeh
		coeeh
		cetg
		frgh
		cggerf
		ergergh
		ceeeeeh
		crrh
		cfh
	ana:~/ $ cat grep_text.txt| grep "^c..h$"                                                                                                                                         [23:29:53]
		coeh
		crrh

5. Mostrar las líneas del f fichero /usr/share/dict/words que contengan la subcadena 'er'.
	ana:~/ $ cat grep_text.txt| grep "er"                                                                                                                                             [23:32:27]
		cggerf
		ergergh

6. Mostrar las líneas del f fichero /usr/share/dict/words que contengan subcadenas de tres letras que comiencen por ‘b’, terminen por ‘g’ y en medio tengan una ‘a’ o una ‘e’.
	ana:~/ $ cat grep_text.txt                                                                                                                                                        [23:34:30]
		coeh
		coeeh
		cetg
		frgh
		cggerf
		ergergh
		ceeeeeh
		crrh
		cfh
		big
		bog
		bag
		beg
		baeg
		baeioug
		bar
		bae
		bea
		eag
		ag
		eg
	ana:~/ $ cat grep_text.txt| grep "^b[ae]g$"                                                                                                                                       [23:34:43]
		bag
		beg

7. Mostrar las líneas del fichero /usr/share/dict/words que contengan subcadenas de tres letras que comiencen por ‘b’, terminen por ‘g’ y en medio tengan cualquier carácter excepto una ‘a’ o una ‘e’.
	
	ana:~/ $ cat grep_text.txt| grep "^b[ae]g$"                                                                                                                                       [23:34:43]
		bag
		beg
	ana:~/ $ cat grep_text.txt| grep "b[^ae]g"                                                                                                                                        [23:37:22]
		big
		bog

8. Mostrar las líneas del fichero /usr/share/dict/words que contengan las subcadenas ‘car’ ó ‘truck’.
	ana:~/ $ cat grep_text.txt| grep -E 'bag|beg'                                                                                                                                     [23:41:14]
		bag
		beg

Actividad 14 (intermedia): búsqueda de ficheros (find)
1. Buscar los ficheros contenidos bajo /ana cuyo nombre comience por ‘ls’ y termine por ‘.txt’.
	ana:~/ $ find ./URJC -name "*.txt"                                                                                                                                                [23:52:19]
		./URJC/test.txt

	ana:~/ $ find ./URJC -name "t*.txt"                                                                                                                                               [23:56:20]
		./URJC/test.txt


2. Buscar los ficheros contenidos bajo /usr/lib cuyo tamaño sea mayor que 2 MB.
		find /home -name “*.txt” -size +1000k

3. Buscar los ficheros contenidos bajo el directorio raíz del usuario sobre los que el propio usuario tenga permiso de escritura.


4. Buscar los directorios contenidos bajo el directorio raíz del usuario cuyo nombre contenga la subcadena ‘os’ y sobre los que el propio usuario tenga permiso de escritura.




--------------------------------------------------------------------
-
____________________________________________________________________

1- Escribir una línea de mandatos conectados entre sí para mostrar por pantalla cuántos usuarios se encuentran conectados al sistema (who, wc).

	ana@ana-VirtualBox:~$ who
	ana      :0           2018-09-23 20:07 (:0)
	ana@ana-VirtualBox:~$ who | wc
	      1       5      44

2- Escribir una línea de mandatos conectados entre sí para mostrar por pantalla en ordenalfabético los nombres de los usuarios que permanecen conectados (who, sort).

	ana@ana-VirtualBox:~$ who
	ana      :0           2018-09-23 20:07 (:0)
	ana@ana-VirtualBox:~$ who | sort
	ana      :0           2018-09-23 20:07 (:0)



3- Escribir una línea de mandatos conectados entre sí para mostrar por pantalla cuántos usuarios hay en el sistema (sin tener en cuenta si están conectados o no) (cat, wc).

	ana@ana-VirtualBox:/$ cat etc/passwd
	root:x:0:0:root:/root:/bin/bash
	daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
	bin:x:2:2:bin:/bin:/usr/sbin/nologin
	sys:x:3:3:sys:/dev:/usr/sbin/nologin
	sync:x:4:65534:sync:/bin:/bin/sync
	games:x:5:60:games:/usr/games:/usr/sbin/nologin
	man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
	lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
	mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
	news:x:9:9:news:/var/spool/news:/usr/sbin/nologin
	uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
	proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
	www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin
	backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
	list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
	irc:x:39:39:ircd:/var/run/ircd:/usr/sbin/nologin
	gnats:x:41:41:Gnats Bug-Reporting System (admin):/var/lib/gnats:/usr/sbin/nologin
	nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin
	systemd-network:x:100:102:systemd Network Management,,,:/run/systemd/netif:/usr/sbin/nologin
	systemd-resolve:x:101:103:systemd Resolver,,,:/run/systemd/resolve:/usr/sbin/nologin
	syslog:x:102:106::/home/syslog:/usr/sbin/nologin
	messagebus:x:103:107::/nonexistent:/usr/sbin/nologin
	_apt:x:104:65534::/nonexistent:/usr/sbin/nologin
	uuidd:x:105:111::/run/uuidd:/usr/sbin/nologin
	avahi-autoipd:x:106:112:Avahi autoip daemon,,,:/var/lib/avahi-autoipd:/usr/sbin/nologin
	usbmux:x:107:46:usbmux daemon,,,:/var/lib/usbmux:/usr/sbin/nologin
	dnsmasq:x:108:65534:dnsmasq,,,:/var/lib/misc:/usr/sbin/nologin
	rtkit:x:109:114:RealtimeKit,,,:/proc:/usr/sbin/nologin
	cups-pk-helper:x:110:116:user for cups-pk-helper service,,,:/home/cups-pk-helper:/usr/sbin/nologin
	speech-dispatcher:x:111:29:Speech Dispatcher,,,:/var/run/speech-dispatcher:/bin/false
	whoopsie:x:112:117::/nonexistent:/bin/false
	kernoops:x:113:65534:Kernel Oops Tracking Daemon,,,:/:/usr/sbin/nologin
	saned:x:114:119::/var/lib/saned:/usr/sbin/nologin
	pulse:x:115:120:PulseAudio daemon,,,:/var/run/pulse:/usr/sbin/nologin
	avahi:x:116:122:Avahi mDNS daemon,,,:/var/run/avahi-daemon:/usr/sbin/nologin
	colord:x:117:123:colord colour management daemon,,,:/var/lib/colord:/usr/sbin/nologin
	hplip:x:118:7:HPLIP system user,,,:/var/run/hplip:/bin/false
	geoclue:x:119:124::/var/lib/geoclue:/usr/sbin/nologin
	gnome-initial-setup:x:120:65534::/run/gnome-initial-setup/:/bin/false
	gdm:x:121:125:Gnome Display Manager:/var/lib/gdm3:/bin/false
	ana:x:1000:1000:ana,,,:/home/ana:/bin/bash

	ana@ana-VirtualBox:/$ cat etc/passwd | wc
	     41      69    2398


4- Escribir una línea de mandatos conectados entre sí para mostrar por pantalla los login names de los usuarios del sistema. Realizar dos versiones:
	• Mostrar todos los login names por orden alfabético (cut, sort).
	 # -d es el delimitador y -f el número de campo (field)

		ana@ana-VirtualBox:/$ cut -d":" -f1 /etc/passwd | sort
		ana
		_apt
		avahi
		avahi-autoipd
		backup
		bin
		colord
		cups-pk-helper
		daemon
		dnsmasq
		games
		gdm
		geoclue
		gnats
		gnome-initial-setup
		hplip
		irc
		kernoops
		list
		lp
		mail
		man
		messagebus
		news
		nobody
		proxy
		pulse
		root
		rtkit
		saned
		speech-dispatcher
		sync
		sys
		syslog
		systemd-network
		systemd-resolve
		usbmux
		uucp
		uuidd
		whoopsie
		www-data


	• Mostrar sólo aquéllos cuyo login name comienza por “r” (cut, grep).

		ana@ana-VirtualBox:/$ cut -d":" -f1 /etc/passwd | grep "^r"   # El sombrerito ^ es para que empiece por 
		root
		rtkit