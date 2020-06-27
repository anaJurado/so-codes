/*
TEMA 4  - EJERCICIOS PROPUESTOS - THREADS (2)

Escriba un programa en C llamado mut que cree dos threads que accedan simultáneamente a un buffer de 10000 enteros. Uno de ello lee en el buffer y el otro escribe en el mismo. El thread escritor, debe escribir el mismo valor en todos los elementos del buffer incrementando en uno el valor en cada pasada. El thread lector debe ir comprobando que todos los números del buffer son iguales, mostrando un mensa e de error en caso contrario o un mensa e de correcto si la condición se cumple. El código a realizar utilizará un mutex para acceder al bufffer si se indica un parámetro al e ecutar el programa. En caso contrario, los threads accederán al buffer de cualquier manera. 

*/