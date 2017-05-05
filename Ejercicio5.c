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
/*Escriba una función recursiva llamada imprimirArreglo que imprima los elementos del arreglo A.
 */
/********************************************************/
void imprimirArreglo(int *arreglo,int largo){
	if(largo!=0){
		imprimirArreglo(arreglo,largo-1);
		printf("Valor %d del arreglo es:%d\n",largo,arreglo[largo-1]);
	}
}
/********************************************************/
/*Menu*/
/********************************************************/
void main(){
	int *arreglo;
	int largo;
	printf("Indique el largo de su arreglo:\n");
	scanf("%i",&largo);
	arreglo=crearArreglo(largo);
	arreglo=agregarNumeros(arreglo,largo);
	imprimirArreglo(arreglo,largo);
}
