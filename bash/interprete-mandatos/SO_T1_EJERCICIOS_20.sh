# EJERCICIOS DE SCRIPTS

# Actividad 20 (avanzada): scripts
# (Paso previo) Posicionarse en el directorio home del usuario, y crear en él un directorio llamado
# scripts. Entrar en el directorio recién creado. Descargar en el directorio scripts el fichero de apoyo
# scripts.tgz, y descomprimirlo mediante la orden tar xvfz scripts.tgz. Al final de este paso, todos
# los ficheros contenidos en scripts.tgz deben encontrarse en el directorio scripts, que además
# debe ser nuestro directorio de trabajo actual. 

ana:~/ $ mkdir scripts

ana:~/ $ mv ./Downloads/scripts.tgz  scripts

ana:~/ $ cd scripts 

ana:scripts/ $ ls 
	scripts.tgz

ana:scripts/ $ tar xvfz scripts.tgz 
	x cambiar_dir.sh
	x imprimir_pid.sh
	x script_factorial.sh
	x script_for.sh
	x script_for_txt.sh
	x script_funciones.sh
	x script_init.sh
	x script_param2.sh
	x script_param.sh
	x script_test.sh

ana:scripts/ $ ls 
cambiar_dir.sh      imprimir_pid.sh     script_factorial.sh script_for.sh       
script_for_txt.sh   script_funciones.sh script_init.sh      script_param.sh     
script_param2.sh    script_test.sh      scripts.tgz


# 1. En la línea de mandatos, escribir directamente cambiar_dir.sh para invocar el script. ¿Qué sucede?
ana:scripts/ $ cambiar_dir.sh                                                                                                                                                                                                    [20:07:54]
zsh: command not found: cambiar_dir.sh


# 2. Invocar el script cambiar_dir.sh especificando su ruta parcial. ¿Qué sucede?
ana:scripts/ $ scripts/cambiar_dir.sh                                                                                                                                                                                            [20:08:49]
zsh: no such file or directory: scripts/cambiar_dir.sh


# 3. Cambiar los permisos de cambiar_dir.sh únicamente, para que el usuario pueda ejecutarlo. A continuación, ejecutarlo precedido de su ruta parcial. 
# ¿Qué sucede? ¿En qué directorio nos encontramos? Comprobarlo mediante el mandato pwd.
ana:scripts/ $ chmod u+x cambiar_dir.sh                                                                                                                                                                                          [20:11:57]
ana:scripts/ $ scripts/cambiar_dir.sh                                                                                                                                                                                            [20:12:30]
	zsh: no such file or directory: scripts/cambiar_dir.sh
ana:scripts/ $ cambiar_dir.sh                                                                                                                                                                                                    [20:12:39]
	zsh: command not found: cambiar_dir.sh
ana:scripts/ $ ./cambiar_dir.sh                                                                                                                                                                                                  [20:12:50]
	Directorio actual: /Users/ana
ana:scripts/ $ pwd                                                                                                                                                                                                               [20:13:03]
	/Users/ana/scripts


# 4. Escribir source cambiar_dir.sh para ejecutar el mandato. ¿Qué sucede? ¿En qué directorio nos
# encontramos? Comprobarlo mediante el mandato pwd.
ana:scripts/ $ source cambiar_dir.sh                                                                                                                                                                                             [20:13:07]
	Directorio actual: /Users/ana
ana:~/ $ pwd                                                                                                                                                                                                                     [20:13:43]
	/Users/ana


# 5. El script cambiar_dir.sh acepta un único argumento, que es un directorio. 
# Probar a ejecutar cambiar_dir.sh de las dos formas, con y sin anteponer el mandato source, 
# para tratar de cambiar a otros directorios existentes, y observar los efectos que se producen.

# SIN SOURCE
ana:~/ $ scripts/cambiar_dir.sh Downloads                                                                                                                                                                                        [20:15:30]
	Directorio actual: /Users/ana/Downloads
ana:~/ $ pwd                                                                                                                                                                                                                     [20:15:44]
	/Users/ana

# CON SOURCE
ana:~/ $ source scripts/cambiar_dir.sh Downloads                                                                                                                                                                                 [20:13:47]
	Directorio actual: /Users/ana/Downloads
ana:Downloads/ $ pwd                                                                                                                                                                                                             [20:14:47]
	/Users/ana/Downloads

ana:scripts/ $ cat cambiar_dir.sh                                                                                                                                                                                                [20:16:28]
	#!/bin/bash
	# Cambia al directorio especificado
	cd $1
	# Imprime el directorio actual
	echo "Directorio actual: $PWD"






