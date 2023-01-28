                /* ConAndAd.c*/

    
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
                
                
                //NuevoElmn crea un nuevo nodo elemento para un conjunto (se debe usar la funcion en asignacion al nodo anterior)
                
                conj_node* NuevoElmn(char* Elemento){
                    conj_node* aux;
                    aux=(conj_node *)malloc(sizeof(conj_node));
                    if(aux==NULL){
                        printf("Hubo un error al asignar memoria dinamica\n");
                        return NULL;
                    }
                    
                    strcpy(aux->elemento,Elemento);
                    aux->sig=NULL;
                    aux->ant=NULL;    
                    return aux;
                }

		int ContarElmn(str_conj* auxlist,char* nconj){
			int j=0;
			conj_node* auxnode=NULL;
			for(;auxlist!=NULL;auxlist=auxlist->sig){
				if(strcmp(auxlist->name_conj,nconj)==0)
					auxnode=auxlist->p_elmn_conj;
			}
			if(auxnode==NULL)
				return 0;
			for(;auxnode!=NULL;auxnode=auxnode->sig,j++);
				
			return j;
		}
                
                void AggElmn(char*ElmnAgg,str_conj* list_conj,char*nombre_conj){                    //Agrega un elemento a un conjunto
                    conj_node* aux;
                    str_conj* auxlist=list_conj;
                    if(list_conj!=NULL){
                        aux=NuevoElmn(ElmnAgg);
                        if(aux==NULL){
                            printf("Error al crear elemento\n");
                            return;
                        }
                        for(;(auxlist!=NULL)&&(strcmp(auxlist->name_conj,nombre_conj)!=0)&&(auxlist->sig!=NULL);auxlist=auxlist->sig);
                        if(strcmp(auxlist->name_conj,nombre_conj)!=0){
                        	printf("Conjunto Inexistente\n");
                        	return;
                        }
                        if(strcmp(auxlist->name_conj,nombre_conj)==0){
                            conj_node* aux1;
aux1=auxlist->p_elmn_conj;
                            if(aux1==NULL){
                                auxlist->p_elmn_conj=aux;
				
                                return;
                            }else{
                                for(;aux1->sig!=NULL;aux1=aux1->sig);
                                aux1->sig=aux;
                                return;
                            }
                        }
                    }else{
                        printf("Error en conjuntos\n");
                        return;
                    }
                }

                void supElmn(str_conj* list_conj,char*nombre_conj,char* elemento1){                         //Suprime un elemento del conjunto
                    if(list_conj==NULL){
                        printf("No existen conjuntos cargados\n");
                        return;
                    }
                        
                    str_conj* auxlist=list_conj;
                    for(;(auxlist!=NULL)&&(strcmp(nombre_conj,auxlist->name_conj));auxlist=auxlist->sig);
                    if(strcmp(nombre_conj,auxlist->name_conj)==0){
                        if(auxlist->p_elmn_conj==NULL){
                            printf("Error conjunto vacio\n");
                            return;    
                        }else{
                        	printf("LOL1");
                            conj_node* aux1=auxlist->p_elmn_conj;
                            
                            for(;(aux1!=NULL)&&(strcmp(elemento1,aux1->elemento)!=0);aux1=aux1->sig);
                            if(strcmp(elemento1,aux1->elemento)!=0){
                                printf("No existe el elemento en el conjunto\n");
                                return;
                            }
                            if((strcmp((auxlist->p_elmn_conj)->elemento,aux1->elemento))==0){        //Si el elemento a eliminado esta al inicio de la lista			
                               auxlist->p_elmn_conj=aux1->sig;
                               free(aux1);
                               
                               (auxlist->p_elmn_conj)->ant=NULL;
                               return; 
                            }else
                                if((aux1->sig)!=NULL){               //Si el elemento se encuentro en medio de la lista
                                    (aux1->ant)->sig=aux1->sig;
                                    (aux1->sig)->ant=aux1->ant;
                                    free(aux1);
                                    return;
                                
                            }else{
                                if((aux1->sig)==NULL){                //Si el elemento se encuentra al final de la lista.
                                    (aux1->ant)->sig=NULL;
                                    free(aux1);
                                    return;
                                }
                            }
                        }
                    }
                }
              
                //Crea un nuevo conjunto en tiempo de ejecucion

                str_conj* NuevoConj(char* nameasig,str_conj* list_conj){
                    str_conj* auxlist1=list_conj;
                    if(list_conj==NULL){
                        list_conj=(str_conj*)malloc(sizeof(str_conj));
                        if(list_conj==NULL){
                            printf("Error al reservar Memoria dinamica\n");
                            return NULL;
                        }else{
                        	
                            printf("Conjunto creado exitosamente\n");

                            strcpy(list_conj->name_conj,nameasig);
                            list_conj->sig=NULL;
                            list_conj->ant=NULL;
                            list_conj->p_elmn_conj=NULL;
                            

                            return list_conj;
                        }
                    }else{
                        for(;auxlist1->sig!=NULL;auxlist1=auxlist1->sig);
                        auxlist1->sig=(str_conj*)malloc(sizeof(str_conj));
                        if(auxlist1->sig==NULL){
                            printf("Error al reservar memoria dinamica\n");

                            return list_conj;
                        }else{
                        	
                            strcpy((auxlist1->sig)->name_conj,nameasig);
                            printf("Conjunto creado exitosament\n");
                            str_conj*auxs=auxlist1;
                            auxlist1=auxlist1->sig;
                            auxlist1->ant=auxs;
                            auxlist1->sig=NULL;
                            auxlist1->p_elmn_conj=NULL;
                           
                            return list_conj;
                        }
                    }
                }
                
                //Imprime en pantalla los conjuntos en formato (Nombre: elemento1 - elemento2 - elemento3 - elemento n).

                void imp_conj(str_conj* lconj1, char* nameconj){
                    str_conj* aux=lconj1;
                    conj_node* auxnode=NULL;
                    
                    for(;(aux!=NULL)&&(strcmp(aux->name_conj,nameconj)!=0);aux=aux->sig);
                        if(strcmp(aux->name_conj,nameconj)==0){
                            printf("%s:",aux->name_conj);
                            auxnode=aux->p_elmn_conj;
                        }else{
                            if(aux==NULL){
                                printf("No Existe el conjunto\n");
                                return;
                            }
                        }
                    if(auxnode==NULL){
                    printf("Vacio.\n");  
                    
                    }
                        
                    for(;auxnode!=NULL;auxnode=auxnode->sig){
                        if(auxnode->sig!=NULL)
                        	printf("%s - ",auxnode->elemento);
                        if(auxnode->sig==NULL)                        	
                            printf("%s.\n",auxnode->elemento);
                    }
                return;        
                }    
                
                //Verifica la Existencia de un elemento dentro del universo
                
                int validarelmn(str_conj* auxlist,char* elmnval){
					conj_node* auxnode=auxlist->p_elmn_conj;
					for(;auxnode!=NULL;auxnode=auxnode->sig){
						if(strcmp(auxnode->elemento,elmnval)==0){
			
							return 0;
						}	
						if((auxnode->sig==NULL)&&(strcmp(auxnode->elemento,elmnval)!=0)){
							printf("El elemento no existe en el universo\n");
							return 1;
						}
					}
				}

				int validarconj(str_conj*auxlist,char*conj){
					for(;auxlist!=NULL;auxlist=auxlist->sig){
						if(strcmp(auxlist->name_conj,conj)==0)
							return 0;
					}
					return 1;
				}
                            
