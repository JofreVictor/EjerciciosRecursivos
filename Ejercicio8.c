/********************************************************/
/*Estructura de datos
Victor Jofre*/
/********************************************************/
#include <stdio.h>
#include <stdlib.h>
/********************************************************/
typedef struct Nodo{
	int valor;
	struct Nodo *sgte;
}nodo;
typedef struct Lista{
	nodo *ini;
	nodo *fin;
	int tam;
}lista;

lista *crearLista(){
	lista *newlista;
	if (newlista=(lista*)malloc(sizeof(lista))){
		newlista->ini=NULL;
		newlista->fin=NULL;
		newlista->tam=0;
	}else{
		printf("\nError, memoria no asignada");
	}
	return newlista;
	free(newlista);
}

void agregarNodo(lista *listaA,int num){
	nodo *newNodo;
	if(newNodo=(nodo*)malloc(sizeof(nodo))){
		newNodo->valor=num;
		if (listaA->tam==0){
			listaA->fin=newNodo;
			newNodo->sgte=NULL;
		}
		newNodo->sgte=listaA->ini;
		listaA->ini=newNodo;
		listaA->tam++;
	}
}
/********************************************************/
/*Escriba una función recursiva llamada listarLista que imprima los valores de una lista simplemente enlazada.
 */
/********************************************************/
void listarLista(lista *listaO,nodo *ptrO){
	if(ptrO==listaO->ini){
		printf("\nLos valores de la lista son");
	}
	if (ptrO!=NULL){
		listarLista(listaO,ptrO->sgte);
		printf("\n%i",ptrO->valor);
	}
}
/********************************************************/
/*Menu*/
/********************************************************/
void main(){
	lista *pruebaLista;
	pruebaLista=crearLista();
	agregarNodo(pruebaLista,2);
	agregarNodo(pruebaLista,4);
	agregarNodo(pruebaLista,6);
	agregarNodo(pruebaLista,8);
	nodo *ptr=pruebaLista->ini;
	listarLista(pruebaLista,ptr);
}
