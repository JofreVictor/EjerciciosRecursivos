/********************************************************/
/*Estructura de datos
Victor Jofre*/
/********************************************************/
#include <stdio.h>
#include <stdlib.h>
/********************************************************/
/*Escriba una función recursiva llamada multiplicarConSuma que calcule x*y utilizando sumas.
 */
/********************************************************/
int multiplicarConSuma(int num1, int num2){
	int multi=0;
	if (num1>0){
		multi=multiplicarConSuma(num1-1,num2);
		multi=multi+num2;
		return multi;
	}else{
		return multi;
	}
}

/********************************************************/
/*Menu*/
/********************************************************/

void main(){
	int primero,segundo,producto;
	printf("Ingrese primer valor:\n");
	scanf("%i",&primero);
	printf("Ingrese segundo valor:\n");
	scanf("%i",&segundo);
	producto=multiplicarConSuma(primero,segundo);
	printf("El producto de los numeros %i y %i es %i",primero,segundo,producto);
}
