
#include<stdio.h>
#include<stdlib.h>

struct Dato{
   int datos;
   struct Dato *ptrSig;
};

typedef struct Dato *lista, *nodo;
 
int Menu();
nodo CrearNodo(void);
void InsertarElemento(lista *Inicio, lista *Fin);
void RecorrerLista(lista Inicio);
void Longitud(lista Inicio);
void Buscar(lista Inicio);
void EliminarElemento(lista *Inicio, lista *Fin);
void ModificarElemento(lista *Inicio);
void Eliminarlista(lista *Inicio, lista *Fin);

int main(){
	lista Inicio=NULL, Fin=NULL;
	
	int opc;
	while(opc<8)
	{
		opc=Menu();
		switch (opc)
		{
			case 1:
				InsertarElemento(&Inicio,&Fin);
				break;
			case 2: 
			    RecorrerLista(Inicio);
			    break;
			case 3: 
			    Longitud(Inicio);
			    break;
			case 4:
			    Buscar(Inicio);
			    break;
			case 5: 
			    EliminarElemento(&Inicio,&Fin);
			    break;
			case 6: 
			    ModificarElemento(&Inicio);
			    break;
			case 7: 
			    Eliminarlista(&Inicio,&Fin);
			    break;
				
		}
	}
	
	return 0;
}


nodo CrearNodo(void){
	system("cls");
	nodo nuevo; int dato;
	nuevo = (nodo)malloc(sizeof(struct Dato));
	if(nuevo!=NULL){
		printf("\n\tIngreso de datos\n");
		printf("\nElemento: ");
		scanf("%d",&dato);
		nuevo->datos = dato;
		return nuevo;
	}else
		return NULL;
}


void InsertarElemento(lista *Inicio, lista *Fin){
	nodo Nuevo=NULL, Aux=NULL;
	Nuevo = CrearNodo();
	
	if(Nuevo != NULL){
		//lista vacia, se inserta primer elemento
		if(*Inicio == NULL){
			*Inicio = Nuevo;
			(*Inicio)->ptrSig = NULL;
			*Fin = Nuevo;
		}
		else{
			//lista no vacia, se inserta al final
			if(Nuevo->datos > (*Fin)->datos){
				(*Fin)->ptrSig = Nuevo;
				Nuevo->ptrSig = NULL;
				*Fin = Nuevo;
			}
			//lista no vacia, se inserta al inicio
			else{
				Aux = *Inicio;
				while((Aux->ptrSig!=NULL)&&(Aux->ptrSig->datos <= Nuevo->datos))
				{
					Aux= Aux->ptrSig;
				}
				
				Nuevo->ptrSig = Aux->ptrSig;
				Aux->ptrSig = Nuevo;
			}
		}
	}else
		printf("\n\t No se puede insertar");
}


void RecorrerLista(lista Inicio){
	nodo Aux = NULL;
	if(Inicio != NULL)
	{
		system("cls");
		printf("\n\t Elementos de la lista\n");
		Aux = Inicio;
		
		while (Aux!=NULL){
			printf("\n Dato: %d", Aux->datos);
		 	Aux = Aux->ptrSig;	
		}
	}
	else
	{
		printf("\n\tLa lista esta vacia");
	}
	printf("\n\n"); system("pause");
}


void Longitud(lista Inicio){
	nodo Aux;
	if(Inicio != NULL){
		system("cls");
		int cont=0;
		Aux = Inicio;
		while (Aux != NULL)
		{
			cont++;
			Aux = Aux->ptrSig;
		}
		
		printf("\n\tLongitud de la lista es: %d", cont);
	}
	else
		printf("\n\tNo hay longitud, Lista Vacia");
		printf("\n\n"); system("pause");
}


void Buscar(lista Inicio){
	nodo Aux;
	if(Inicio != NULL){
		system("cls");
		int buscar;
		Aux = Inicio;
		printf("\n\t Buscar Elemnto\n");
		printf("\n Elemento a buscar: ");
		scanf("%d", &buscar);
		
		while((Aux != NULL) && (Aux->datos != buscar))
		{
			Aux = Aux->ptrSig;
		}
		
		if(Aux != NULL)
		  printf("\n Elemento Encontrado: %d",Aux->datos);
		  else
		  	printf("\n\t Elemento no en la lista");
	}
	else
		printf("\n\t La lista esta vacia, no se puede buscar");
		printf("\n\n"); system("pause");
}


void EliminarElemento(lista *Inicio, lista *Fin){
	nodo Aux, Anterior;
	
	if(*Inicio != NULL)
	{
		system("cls");
		Aux = *Inicio;
		Anterior = NULL;
		bool encontrado = false;
		int buscar;
		printf("\n\t Eliminar Elemento\n");
		printf("\n Elemento a Buscar: ");
		scanf("%d", &buscar);
		
		while((Aux != NULL) && (encontrado != true))
		{
		  if(Aux->datos == buscar){
		  	//elimina nodo del inicio
		  	if(Aux == *Inicio)
		  		*Inicio=(*Inicio)->ptrSig;
		  	//elimina nodo del final
		  	else if(Aux ==* Fin)
				{
			  		Anterior->ptrSig = NULL;
			  		*Fin = Anterior;
				}else //elimina nodo intermedio
			  		Anterior->ptrSig = Aux->ptrSig;
			  
			  encontrado = true;
		  }	
		  Anterior = Aux;
		  Aux = Aux->ptrSig;
		}
		if(encontrado == true){
			printf("\n Elemento Eliminado: %d",Anterior->datos);
			free(Anterior);
		}
		else
		  printf("\n Elemento no encontrado");
	}
	else
		printf("\n\t La lista esta vacia, no se puede eliminar");
	 	printf("\n\n"); system("pause");
}



void ModificarElemento(lista *Inicio){
	nodo orden, Aux, Anterior;
	if (*Inicio != NULL)
	{
		system("cls");
		Aux = *Inicio;
		Anterior = NULL;
		bool encontrado = false;
		int buscar, modificar;
		printf("\n\t Modificar Elemento\n");
		printf("\n Elemento a modificar: ");
		scanf("%d", &buscar);
		
		while (Aux != NULL && encontrado != true)
		{
			if(Aux->datos == buscar)
			{
				printf("\nValor nuevo: ");
				scanf("%d", &modificar);
				   Aux->datos = modificar;
				   encontrado = true; 
			}
			Aux = Aux->ptrSig;
		}
		
		if(encontrado == true)
		   printf("\n Elemento Modificado");
		else
		   printf("\n Elemento no existe en la lista");
	}
	else
	    printf("\n\tLa lista esta vacia");
	    printf("\n\n"); system("pause");
}


void Eliminarlista (lista *Inicio, lista *Fin){
	
	nodo Aux;
	if(*Inicio != NULL)
	{
		system("cls");
		int valor = 0;
		printf("\n\t Eliminar lista\n");
		while(*Inicio != NULL)
		{
			Aux = *Inicio;
			*Inicio = (*Inicio)->ptrSig;
			valor = Aux->datos;
			printf("\n Elemento Eliminado: %d", valor);
			free(Aux);
		}
		*Fin = NULL;
		*Inicio = NULL;
	}
	else
	   printf("\n\tLa lista esta vacia");
	printf("\n\n"); system("pause");
}

int Menu()
{
	int opcion=0;
	
	do{
		system("cls");
		printf("\n\n\t   Menu de Opciones");
		
		printf("\n    ________________________________________");
			printf("\n\t1) Insertar Elemento");
			printf("\n\t2) Recorrer la Lista");
			printf("\n\t3) Longitud de la lista");
			printf("\n\t4) Buscar elemento en la lista");
			printf("\n\t5) Eleminar Elemento de la lista");
			printf("\n\t6) Modificar elemento");
			printf("\n\t7) Eliminar lista");
			printf("\n\t8) Salir");
		printf("\n    ________________________________________");
		printf("\n\t Opcion: "); scanf("%d", &opcion);
	}while (opcion<1 || opcion>8);
	return opcion;
}
