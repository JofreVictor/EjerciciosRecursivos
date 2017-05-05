/********************************************************/
/*Estructura de datos
Victor Jofre*/
/********************************************************/
#include <stdio.h>
#include <stdlib.h>
/********************************************************/
/*Escriba una funci�n recursiva llamada calcularFactorial que calcule el factorial de un n�mero X
 */
/********************************************************/

double calcularFactorial(double n){
	double factor=1;
	if(n>0){
		factor=calcularFactorial(n-1);
		factor=factor*n;
		return factor;
	}else{
		return factor;
	}
}

/********************************************************/
/*Menu*/
/********************************************************/

void main(){
	double valor,factorial;
	printf("Ingrese un valor:\n");
	scanf("%d",&valor);
	factorial=calcularFactorial(valor);
	printf("El factorial de %d es: %d",valor,factorial);
}
