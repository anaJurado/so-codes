# SISTEMAS OPERATIVOS TEMA 1 - EJERCICIOS 
# INTÉRPRETE DE MANDATOS

# EJERCICIO 2
Actividad 2 (básica): mandato echo
1. Ejecutar el mandato echo con diferentes parámetros. Por ejemplo:
	$ echo “Hola Mundo”
	$ echo Hola Mundo
	$ echo No sé multiplicar 4*2
	$ echo PATH
	$ echo $PATH

	$ echo “Hola Mundo”
	“Hola Mundo”
	
	$ echo Hola Mundo
	Hola Mundo
	
	$ echo No sé multiplicar 4*2
	No sé multiplicar 4*2

	$ expr 4 + 2
	6
	
	$ expr 4 * 2
	expr: syntax error
	
	$ echo "4 * 2" | bc  # -> |bc
	8

	$ echo $((4 * 2))  # ->  $((operacion))
	8

	$ echo PATH
	PATH
	
	$ echo $PATH
	/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Frameworks/Mono.framework/Versions/Current/Commands

2. Ejecutar el mandato echo varias veces en una única línea separando cada ejecución mediante el
carácter ; con diferentes parámetros. Por ejemplo:
	$ echo “Hola”; echo ; echo “Mundo”
	$ echo Directorios para ejecutables: ; echo $PATH

3. Probar lo siguiente:
	$ echo Quiero imprimir el carácter “;”
	Quiero imprimir el carácter “
	-bash: ”: command not found
	
	$ echo Quiero imprimir el carácter “\;”
	Quiero imprimir el carácter “;”



# EJERCICIO 3
Actividad 3 (básica): man (texto)
1. Ver la página de manual del mandato echo.
2. Ver la página de manual del mandato man.

Notas
• En el material de clase se indica qué teclas hay que utilizar para navegar dentro de una página de manual en la versión de texto.
• Para salir de la página de manual pulsar la tecla Q.



# EJERCICIO 4
Actividad 4 (básica): xman (gráfico)
1. Ejecutar xman desde la línea de mandatos.
2. En la ventana pequeña inicial de xman, pinchar en Manual Page.
3. En la nueva ventana que aparece, pinchar en Sections y, manteniendo el botón pinchado,arrastrar el ratón hasta (1) User Commands y soltar el botón. Así se pueden ver los ítems de manual que están en la sección 1.
4. Dentro de la lista de mandatos, que están ordenados en orden alfabético, pinchar sobre el mandato echo. Ver notas más abajo para saber cómo navegar en la lista.
5. Buscar la página de man. Para ello, repetir el paso 3 y buscar man en la lista.
6. Repetir el paso 3 pero entrando en otras secciones del manual.
7. Para salir, pinchar en Options y arrastrar hasta la opción Quit, o bien pinchar en Quit en la ventana pequeña inicial de xman.

Notas
• Para movernos hacia delante pulsaremos con el botón izquierdo del ratón sobre la barra de desplazamiento de la ventana, que está situada a nuestra izquierda.
• Para movernos hacia atrás pulsaremos sobre la misma barra de desplazamiento con el botón derecho.
• Si pinchamos muy abajo en la barra avanzaremos mucho, y si pinchamos muy arriba avanzaremos poco.
• Estos consejos sirven para avanzar o retroceder dentro de la lista de mandatos, y también dentro de la página de manual.



# EJERCICIO 5 - NO TIENE MUCHO MISTERIO
Actividad 5 (básica): man, whatis, apropos
1. Consultar la página de write como mandato.
	$ man 1 write  
	El 1 es para mandatos generales

	WRITE(1)                  BSD General Commands Manual                 WRITE(1)

	NAME
	     write -- send a message to another user


2. Consultar la página de write como llamada al sistema.
	$ man 2 write  
	El 2 es para llamda al sistema

	WRITE(2)                    BSD System Calls Manual                   WRITE(2)

	NAME
     	pwrite, write, writev -- write output


Para buscar una página del manual:
§ whatis <palabraclave> : búsqueda por nombre.
§ apropos <palabraclave> : búsqueda exhaustiva. Igual que man –k <palabraclave>

3. Usar el mandato whatis para ver si hay páginas de manual llamadas ls.
4. Usar el mandato whatis para ver si hay páginas de manual llamadas write.
5. Utilizando apropos y/o man –k, ver qué páginas de manual hablan sobre directorios, buscando mediante el término directory.
6. Utilizando apropos y/o man –k, ver qué páginas de manual hablan sobre ficheros, buscando mediante el término file.
7. Buscar páginas sobre otros mandatos y términos


# EJERCICIO 6
Actividad 6 (básica): info
1. Entrar en la página info del mandato echo. Usar las teclas indicadas arriba para moverse por la descripción del mandato.
2. Situar el cursor encima de *note Common options y pulsar Intro para saltar al nodo relacionado. Explorar las opciones comunes indicadas en el nuevo nodo que aparece.
3. Pulsar L para volver a la descripción del mandato echo.
4. Pulsar T para ir a la página de introducción de las utilidades de GNU.
5. Para salir, pulsar Q.
6. Explorar la página info de otros mandatos.
7. Ejecutar info sin parámetros para ir al nodo superior de la jerarquía. Sin salir de info, navegar por este nodo y entrar al nodo superior de la descripción del editor nano.



# EJERCICIO 7
Actividad 7 (básica): bash
1. Escribir mandatos incompletos y completarlos con el tabulador (info, echo, etc).
2. Recorrer la lista de mandatos escritos previamente con las flechas de cursor.
3. Modificar líneas introducidas previamente, editándolas con las flechas izquierda y derecha, y las teclas de inicio y fin.
4. Pulsar Ctrl R y escribir parcialmente algún mandato anterior. Pulsar Intro cuando haya aparecido para ejecutarlo.


