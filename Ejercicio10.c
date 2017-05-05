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
		printf("\n%d",aux->valor);
		aux=aux->sgte;
	}
	free(aux);
}
/********************************************************/
/*Escriba una función recursiva llamada existeElemento que verifique si un elemento x se encuentra en una lista L.
 */
/********************************************************/
int existeElemento(lista *listaO,int x,nodo *ptrO){
	int verificador=0;
	if (ptrO!=NULL){
		verificador=existeElemento(listaO,x,ptrO->sgte);
		if(x==ptrO->valor){
			verificador=1;
		}
		return verificador;
	}else{
		return verificador;
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
	agregarNodo(pruebaLista,5);
	agregarNodo(pruebaLista,6);
	agregarNodo(pruebaLista,2);
	agregarNodo(pruebaLista,3);
	agregarNodo(pruebaLista,5);
	agregarNodo(pruebaLista,1);
	agregarNodo(pruebaLista,6);
	recorrerLista(pruebaLista);
	printf("\nIngrese un valor para saber si existe en la lista:\n");
	scanf("%i",&valor);
	nodo *ptr=pruebaLista->ini;
	int verificador=existeElemento(pruebaLista,valor,ptr);
	if(verificador==1){
		printf("\nEl valor %d si existe en la lista");
	}else{
		printf("\nEl valor %d no existe en la lista");
	}
}
