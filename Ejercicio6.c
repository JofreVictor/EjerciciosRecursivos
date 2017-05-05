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
/*Escriba una función recursiva llamada calcularOcurrencia que cuente la cantidad de ocurrencias de un elemento x en una lista L.
 */
/********************************************************/
int calcularOcurrencia(lista *listaO,int x,nodo *ptrO){
	int acum=0;
	if (ptrO!=NULL){
		acum=calcularOcurrencia(listaO,x,ptrO->sgte);
		if(x==ptrO->valor){
			acum++;
		}
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
	int valor;
	pruebaLista=crearLista();
	agregarNodo(pruebaLista,1);
	agregarNodo(pruebaLista,2);
	agregarNodo(pruebaLista,3);
	agregarNodo(pruebaLista,1);
	agregarNodo(pruebaLista,2);
	agregarNodo(pruebaLista,3);
	agregarNodo(pruebaLista,2);
	agregarNodo(pruebaLista,2);
	recorrerLista(pruebaLista);
	printf("Numero repetido que se quiere buscar en la lista:\n");
	scanf("%i",&valor);
	nodo *ptr=pruebaLista->ini;
	int cantidad=calcularOcurrencia(pruebaLista,valor,ptr);
	printf("La cantidad de veces que se repite el valor %i es de: %i",valor,cantidad);
}
