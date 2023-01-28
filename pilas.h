// Libreria de pilas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------------------------------Definicion del tipo pila-----------------------------------------

typedef struct node{
				char elmn[100];
				struct node* sig;
				int size;
			}nodo_pila;
			
//------------------------------------------------------------------------------------------------------------

			


nodo_pila* push(nodo_pila* auxp,char* elmnagg);

nodo_pila* pop(nodo_pila* auxpila,char* pch);

char* top(nodo_pila* auxpila);





