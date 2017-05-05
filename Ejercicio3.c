/********************************************************/
/*Estructura de datos
Victor Jofre*/
/********************************************************/
#include <stdio.h>
#include <stdlib.h>
/********************************************************/
/*-Se crea un funcion que construya un arreglo de tipo double,en caso de ingresar numeros demasiado grandes
-Se crea una funcion que añada elementos dentro del arreglo creado
 */
/********************************************************/
int *crearArreglo(int ini){
	int *creaArr;
	creaArr=(int*)malloc(ini*sizeof(int));
	return creaArr;
}

int *agregarNumeros(int *creaArr,int largo){
	int i,valor;
	for (i=0;i<largo;i++){
		printf("Numero %d para agregar:\n",i+1);
		scanf("%i",&valor);
		creaArr[i]=valor;
	}
	return creaArr;
}
/********************************************************/
/*Escriba una función recursiva llamada sumarArreglo que sume los elementos de un arreglo A.
 */
/********************************************************/
int sumarArreglo(int *arreglo,int largo){
	int acum=0;
	if(largo!=0){
		acum=sumarArreglo(arreglo,largo-1);
		acum=acum+arreglo[largo-1];
		return acum;
	}else{
		return acum;
	}
}
/********************************************************/
/*Menu*/
/********************************************************/
void main(){
	int *arreglo;
	int largo,sum;
	printf("Indique el largo de su arreglo:\n");
	scanf("%i",&largo);
	arreglo=crearArreglo(largo);
	arreglo=agregarNumeros(arreglo,largo);
	sum=sumarArreglo(arreglo,largo);
	printf("La suma de los valores dentro del arreglo es:%d\n",sum);
}
