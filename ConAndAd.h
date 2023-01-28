                /* ConAndAd.h */ 

                #include <stdlib.h>
                #include <stdio.h>
                #include <string.h>
                
                /* DEFINICION DEL TIPO DE DATO*/
                
                typedef struct c_node{char elemento[30]; struct c_node *sig; struct c_node *ant;} conj_node;                           //Estructura que almacena los Elementos
                typedef struct nc_node{char name_conj[20];struct nc_node* sig;struct nc_node* ant;conj_node* p_elmn_conj;}str_conj;           //Estructura que almacena nombre de conjuntos y direccion
                
                
                /* PROTOTIPOS DE FUNCIONES*/
                
                conj_node* NuevoElmn(char* Elemento);                                                    // Crear un nuevo elemento.
                void AggElmn(char*ElmnAgg,str_conj* list_conj,char*nombre_conj);                         // Agrega Elementos a un conjunto.
                void supElmn(str_conj* list_conj,char*nombre_conj,char* elemento1);                      // Elimina un elemnto del conjunto.
                void imp_conj(str_conj* lconj1, char*nameconj);                                     // Imprime conjuntos.
                str_conj* NuevoConj(char* nameasig,str_conj* list_conj);                                      //crea un nuevo conjunto y le asigna un nombre.
                int ContarElmn(str_conj* auxlist,char* nconj);		//Cuenta cuantos elementos posee el conjunto
                int validarconj(str_conj*auxlist,char*conj);		//Verifica la existencia de un conjunto
                int validarelmn(str_conj* auxlist,char* elmnval);   //Verifica la existencia de un elemento dentro del universo
