# SISTEMAS OPERATIVOS TEMA 1 - EJERCICIOS 
# INTÉRPRETE DE MANDATOS

Actividad 15 (intermedia): manipulación de permisos de los ficheros (chmod, umask)
1. Escribir umask para saber cuál es la máscara por defecto para los permisos de creación de nuevos	ficheros y directorios. Anotar dicho valor.
2. Usar touch para crear un fichero llamado permisos. Comprobar los permisos de acceso del ficherosrecién creado y compararlos con los especificados con la máscara obtenida en el paso anterior.
3. Cambiar los permisos del fichero permisos para que el propio usuario no pueda leerlo (asegurarse	de que no se puede ver su contenido con cat).
4. Volver a darle permiso de lectura para el propio usuario.
5. Darle permiso de modificación a los usuarios del grupo.
6. Quitarle permiso de lectura a otros usuarios.
7. Comprobar con ls -l que los permisos son rwrw.
8. Cambiar la máscara por defecto de modo que los permisos para los nuevos ficheros y directorios	queden del siguiente modo:
	• Propietario: únicamente tendrá permiso de lectura.
	• Grupo: sólo permiso de ejecución.
	• Resto: permiso de lectura, escritura y ejecución.
9. Crear un directorio nuevo llamado nuevodir.
10. Hacer ls –l para comprobar los permisos del directorio recién creado.
11. Intentar entrar en nuevodir. ¿Qué sucede? Añadir un único permiso en nuevodir para que el propietario pueda entrar en él.
12. Una vez dentro de nuevodir, crear con touch un fichero vacío llamado nuevofichero. ¿Qué sucede? Cambiar un único permiso en nuevodir para que la creación del fichero sea posible, y crear el fichero.
13. Hacer ls –l para comprobar los permisos del fichero recién creado.
14. Intentar modificar el contenido de nuevofichero. ¿Qué sucede? Cambiar un único permiso en nuevofichero para que el propietario pueda modificarlo, y modificar el contenido del fichero.
15. Restaurar los permisos del paso 1 con umask.