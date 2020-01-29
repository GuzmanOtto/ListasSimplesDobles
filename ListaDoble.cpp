#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

using namespace std;

typedef struct nodo{
	int valor;
	struct nodo *siguiente;
	struct nodo *anterior;
}tiponodo;

typedef tiponodo *pNodo, *Lista;

void Insertar(Lista *l);
void Borrar(Lista *l);
void Lista_Ascendente(Lista l);
void Lista_Descendente(Lista l);
void BorrarLista(Lista *l);
pNodo CrearNodo(void);

int main (){
	//Aqui se define el verdadero valor de lista
	Lista lista = NULL;
	 
	int op=0;
	do{
		system("cls");
		cout<<"\n\t\tLISTAS DOBLEMENTE ENLAZADAS\n";
		cout<<"\t\t\t1. Insertar valor\n";
		cout<<"\t\t\t2. Eliminar valor\n";
		cout<<"\t\t\t3. Mostrar lista ascendente\n";
		cout<<"\t\t\t4. Mostrar lista Descendente\n";
		cout<<"\t\t\t5. Eliminar lista\n";
		cout<<"\t\t\t6. Salir\n";
		cout<<"\t\t\t\tOpcion: ";
		cin>>op;
		
		switch(op){
			case 1: Insertar(&lista);
					system ("pause");
					break;
					
			case 2: Borrar(&lista);
					system ("pause");
					break;
			
			case 3: Lista_Ascendente(lista);
					system ("pause");
					break;
					
			case 4: Lista_Descendente(lista);
					system ("pause");
					break;
				
			case 5: BorrarLista(&lista);
					system ("pause");
					break;
			
			case 6: cout<<"\nSaliendo del Programa\n";
					break;
		}
		
	}while (op!=6);
	
	return 0;
}

//Funciones

//Crear Nodo
pNodo CrearNodo(void){
	
	//Se declara el puntero nuevo
	pNodo nuevo;
	//Se pide espacio en memoria
	nuevo = (pNodo)malloc(sizeof(tiponodo));
	//Se pide el dato y se almacena
	if(nuevo != NULL){
		cout<<"\n\tIngrese el valor: ";
		cin>>nuevo->valor;
		return nuevo;
	//No hubo espacio en la ram
	}else
		return NULL;
}


//Insertar elementos
//Es necesario mandar por referencia
//El verdadero valor de lista esta en el main
void Insertar(Lista *lista){
	//Se declaran nodos nuevo y auxiliar
	pNodo nuevo, aux;
	//Invoca la funcion CrearNodo
	nuevo = CrearNodo();
	//malloc si dio espacio en la RAM
	if( nuevo != NULL){
		//Colocamos auxiliar en la primera posicion de la lista
		aux = *lista;
		if(aux != NULL){
			while (aux->anterior != NULL)
			aux = aux->anterior;
		}
		//Si la lista esta vacia o se inserta al inicio
		if(aux == NULL || aux->valor > nuevo->valor){
			//añadimos la lista a continuacion del nuevo nodo
			nuevo->siguiente = aux;
			nuevo->anterior = NULL;
			if(aux != NULL)
				aux->anterior = nuevo;
			if(*lista == NULL)
				*lista = nuevo;
		}else{
			while ((aux->siguiente != NULL)&& (aux->siguiente->valor <= nuevo->valor)){
				aux = aux->siguiente;
			}
			nuevo->siguiente = aux->siguiente;
			aux->siguiente = nuevo;
			nuevo->anterior = aux;
			if(nuevo->siguiente != NULL)
				nuevo->siguiente->anterior = nuevo;
		}
	}else
		printf("\nNo se puede insertar");
}

//Mostrar por pantalla toda la lista de forma ascendente
//se envia por valor por que no se modifica
void Lista_Ascendente(Lista lista){
	
	pNodo aux = lista;
	
	if(lista==NULL)
		printf("\tLista vacia\n");
	else{
		
		while(aux->anterior!=NULL)
			aux = aux->anterior;
		
		cout<<"\n\tLista ascendente: \t";
		
		while(aux!=NULL){
			printf("%d->", aux->valor);
			aux = aux->siguiente;
		}
		cout<<"NULL"<<endl<<endl;
	}
	
}

//Mostrar por pantalla toda la lista de forma descendente

void Lista_Descendente(Lista lista){
		
	pNodo aux = lista;
	
	if(lista == NULL)
		printf("\n \tLista vacia\t");
	else
	{
		while(aux->siguiente != NULL)
		aux = aux->siguiente;
		
		cout<<"\n\tLista Descendente: \t";
		
		while(aux != NULL)
		{
			printf("%d->", aux->valor);
			aux = aux->anterior;
		}
		cout<<"NULL"<<endl<<endl;
	}
	
}

//Borrar toda la lista

void BorrarLista(Lista *lista){
	
	pNodo nodo, aux;
	aux = *lista;
	
	if(*lista == NULL)
		printf("\n Lista vacia");
	else{
		while(aux->anterior!=NULL)
			aux = aux->anterior;
			
		while(aux!=NULL){
			nodo = aux;
			aux = aux->siguiente;
			free(nodo);
		}
		*lista = NULL;
		cout<<"\n\tLista Eliminada\n";
	}
}

//Borrar un elemento

void Borrar(Lista *lista){
	
	pNodo aux;
	int v = 0;
	
	if(*lista !=NULL){
		cout<<"\nIngrese el valor a eliminar: ";
		cin>>v;
		
		aux = *lista;
		
		while(aux!=NULL && aux->valor<v)
			aux = aux->siguiente;
			
		while(aux!=NULL && aux->valor>v)
			aux = aux->anterior;
			
	
		if(aux==NULL || aux->valor!=v){
		
			cout<<"\n\tElemento no encontrado\n";
			return;
		}
	
		if(aux == *lista){
			if(aux->anterior)
				*lista=aux->anterior;
			else
				*lista = aux->siguiente;
		}
		
		if(aux->anterior!=NULL)
			aux->anterior->siguiente = aux->siguiente;
			
		if(aux->siguiente!=NULL)
			aux->siguiente->anterior = aux->anterior;
		
		free(aux);
		cout<<"\n\tElemto eliminado\n";
	
	}else
		printf("\nNo hay elementos en lista");
}

