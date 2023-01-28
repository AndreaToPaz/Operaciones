// Libreria de pilas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//-------------------------------------Implementacion de las funciones--------------------------------------- 

nodo_pila* push(nodo_pila* auxp,char* elmnagg){
	nodo_pila* auxp1=NULL;
	if(auxp==NULL){
		auxp1=(nodo_pila*)malloc(sizeof(nodo_pila));
		if(auxp1!=NULL){
			strcpy(auxp1->elmn,elmnagg);
			auxp1->sig=NULL;
			auxp1->size=1;
			return auxp1;
		}else{
			printf("Error al reservar memoria dinamica\n");
			return NULL;
		}
	}else
		if(auxp!=NULL){
			auxp1=(nodo_pila*)malloc(sizeof(nodo_pila));
			if(auxp1!=NULL){
				strcpy(auxp1->elmn,elmnagg);
				auxp1->sig=auxp;
				auxp1->size=(auxp->size)+1;
				return auxp1;
			}else{
				printf("Error al reservar memoria dinamica\n");
				return NULL;
			}
		}
}

//----------------------------------------------------------------------------------------------------------

nodo_pila* pop(nodo_pila* auxpila,char* pch){
	if(auxpila==NULL){
		printf("La pila se encuentra vacia\n");
		return NULL;
	}else
		if(auxpila->sig==NULL){
		
			strcpy(pch,auxpila->elmn);
			free(auxpila);
			return NULL;
		}else
			if(auxpila!=NULL){
				nodo_pila* auxp1=NULL;
				auxp1=auxpila->sig;
				
				strcpy(pch,auxpila->elmn);
				free(auxpila);
				return auxp1;		
			}
					
}

//-----------------------------------------------------------------------------------------------------------

char* top(nodo_pila* auxpila){
	if(auxpila!=NULL)
		return auxpila->elmn;
		else
			return "";
		
	

}











