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

void recorrerLista(lista *listaR){
	nodo *aux;
	aux=listaR->ini;
	printf("\nLa lista contiene los siguientes elementos");
	while(aux!=NULL){
		printf("\n%i",aux->valor);
		aux=aux->sgte;
	}
	free(aux);
}
/********************************************************/
/*Escriba una función recursiva llamada sumaLista que retorne la suma de los elementos de una lista de enteros L.
 */
/********************************************************/
int sumaLista(lista *listaO,nodo *ptrO){
	int acum=0;
	if (ptrO!=NULL){
		acum=sumaLista(listaO,ptrO->sgte);
		acum=acum+ptrO->valor;
		return acum;
	}else{
		return acum;
	}
}
/********************************************************/
/*Menu*/
/********************************************************/
void main(){
	lista *pruebaLista;
	pruebaLista=crearLista();
	agregarNodo(pruebaLista,5);
	agregarNodo(pruebaLista,10);
	agregarNodo(pruebaLista,15);
	recorrerLista(pruebaLista);
	nodo *ptr=pruebaLista->ini;
	int suma=sumaLista(pruebaLista,ptr);
	printf("\nLa suma de los valores de la lista es:%i\n",suma);
}
