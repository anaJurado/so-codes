# SISTEMAS OPERATIVOS TEMA 1 - EJERCICIOS 
# INTÉRPRETE DE MANDATOS

Actividad 18 (avanzada): xargs / sustitución de mandato
1. Borrar todos los ficheros que se encuentren por debajo del directorio actual y cuyo nombre coincida con el patrón “*~” (find, xargs, rm).
2. Repetir el ejercicio anterior, pero ahora utilizando sustitución de mandato (find, rm).
3. Copiar todos los ficheros que se encuentren por debajo de la carpeta home del usuario y que encajen con el patrón “*.sh” en una carpeta llamada temporal creada previamente mediante un mandato anterior (find, xargs, cp).
4. Repetir el ejercicio anterior, pero ahora utilizando sustitución de mandato (find, cp).


Actividad 19 (intermedia): variables y expresiones aritméticas
1. Crear una variable llamada DATOA con valor 25, y otra variable llamada DATOB con valor 4.
2. Calcular el valor de DATOA*DATOB+5 mediante el mandato expr.
3. Calcular el valor de DATOA*DATOB+5 mediante los mandatos echo y bc.
4. Calcular el valor de DATOA*DATOB+5 mediante el mandato echo y la evaluación con $((operación)).
5. Mostrar las variables de entorno cuyo nombre termine por la cadena PATH (env, grep)