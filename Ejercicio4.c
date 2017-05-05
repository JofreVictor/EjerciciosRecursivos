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
/*Escriba una función recursiva llamada buscarX que busque un valor X en un arreglo A.
 */
/********************************************************/
void buscarX(int *arreglo,int largo, int x){
	if(largo!=0){
		buscarX(arreglo,largo-1,x);
		if (arreglo[largo-1]==x){
			printf("El numero %d esta en la posicion %d\n",x,largo-1);
		}
	}
}
/********************************************************/
/*Menu*/
/********************************************************/
void main(){
	int *arreglo;
	int largo,numX;
	printf("Indique el largo de su arreglo:\n");
	scanf("%i",&largo);
	arreglo=crearArreglo(largo);
	arreglo=agregarNumeros(arreglo,largo);
	printf("Que numero busca?:\n");
	scanf("%i",&numX);
	buscarX(arreglo,largo,numX);
}
