/*Proyecto 1- Algoritmos Y Programacion II
  Teoria de conjuntos
  Elaborado Por:
  -Andrea Torres.
  -Adrian Luces.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ConAndAd.h"				//Libreria de TAD-Conjunto y Operaciones Sobre el TAD
#include "ConAndAd.c"

#include "OpConAndAd.h"				//Libreria de operaciones sobre conjuntos
#include "OpConAndAd.c"

#include "splitodesu.h"
#include "splitodesu.c"

#include "pilas.h"
#include "pilas.c"

#include "Interprete.h"
#include "Interprete.c"

#define max 500



//---------------------Imprimir todos los Conjuntos cargados-----------------------------------

void PrintAll(str_conj* auxlist){
	conj_node* auxnode=NULL;
	str_conj*auxlist1=auxlist;
	for(;auxlist1!=NULL;auxlist1=auxlist1->sig){
		imp_conj(auxlist,auxlist1->name_conj);
	}
}

//-----------------------------------------------------------------------------------------------------------

int main(){
	int menu=00;	
	str_conj *Listconjuntos=NULL;
	str_conj* Listres=NULL;
	char conj1[75];
	char conj2[75];
	char op[2];
//--------------------------------------------Cargar Archivo-------------------------------------------------

FILE *Arcp; char direccion[20]; int c; 
    
    
    
										//ARCHIVOS
	printf("Ingrese la direccion del archivo\n");
	scanf("%s",direccion); 
										//Apertura del archivo 
	Arcp = fopen(direccion , "r"); 
    if( Arcp == NULL){ //Validacion de archivos
        printf("Error al abrir el archivo\n");
        ;
     }
    printf("Apertura Existosa del Archivo\n");
  
    									// DECLARACIONES DE VARIABLES - COPIA CONTENIDO ARCHIVO
    char **Conjunto, string[max] = " ", caracter;
    
    									//RECORRIDO DEL ARCHIVO
    int j = 0; 							//VARIBLE DE CONTROL - ASIGNACION CHAR A CHAR
    while((caracter =fgetc(Arcp))!=  EOF){ 
        string[j++] = caracter;
    }
		c=fclose(Arcp);
    //TODO EL ARCHIVO ESTA EN STRING
    
	int i = 0, con = 0;					//VARIABLE DE CONTROL - CONJUNTO
	Conjunto = split(string ,'\n');		//SPLIT -SALTO DE LINEA
	
	while (Conjunto[i] != NULL) {
         con++;
         Conjunto[i++];
	} 
	
	//DECLARACION DE VARIABLES - COPIA NOMBRE CONJUNTO

	char **NombreConjunto; 
	int aux = con-1; i = 0; int k = 0;
		
	//DECLARACION DE VARIABLES - ELEMENTO ELEMENTO
	
	char **ElementoConjunto; int ia=0; 
	
	while (i <= aux){ 

	    NombreConjunto = split(Conjunto[i],':');	    	
	    while (NombreConjunto[k] != NULL) {

	        if(k == 0)  
	        	
                Listconjuntos=NuevoConj(NombreConjunto[k],Listconjuntos);
             
             k+=1;
             if (k == 1){

	            ElementoConjunto = split(NombreConjunto[k],'-');	    	           
	             while (ElementoConjunto[ia] != NULL) {

                    AggElmn(ElementoConjunto[ia],Listconjuntos,NombreConjunto[0]);
	             	ia++;
	             } 
	             ia = 0;
              }
	    }
	    k = 0;
	    i++;
	}
//----------------------------------------------------------------------------------------------------------
	
	while(menu!=27){
		system("clear");
		menu=00;
		
		printf("------------------Conjuntos Cargados Actualmente------------------------------\n\n");
		PrintAll(Listconjuntos);printf("\n\n");
	
	
	//--------------------------------------Menu de-----------------------------------------------------	
		
		printf("-Teoria de Conjuntos en C!\n");
		printf("Presione la tecla correspondiente a la accion deseada.\n");
		printf("1)Crear Nuevo conjunto.\n");
		printf("2)Agregar un elemento a un conjunto.\n");
		printf("3)Para realizar una operacion sobre conjuntos.\n");
		printf("4)Evaluar expresiones.\n");
		printf("Esc) Para salir.\n\n");
	
	//--------------------------------------------------------------------------------------------------	
		menu=getchar();
		char namec[30]={""};
		char nameelmn[30]={""};
		int val=2;
		char Expr[75]="";
		
		char Exprpost[75]="";
		switch(menu){
			case 49:
				//system("clear");
				
				printf("-----------Conjuntos Cargados Actualmente------------------------------\n\n");
				PrintAll(Listconjuntos);printf("\n\n");
				
	
				printf("Introduzca el Nombre del Conjunto\n");
				scanf("%s",namec);
				
				Listconjuntos=NuevoConj(namec,Listconjuntos);
				
				break;
		
			case 50:
				printf("------------Conjuntos Cargados Actualmente------------------------------\n\n");
				PrintAll(Listconjuntos);printf("\n\n");
				
				
				printf("Ingrese el elemento a agregar\n");
				scanf("%s",nameelmn);
				
				if((validarelmn(Listconjuntos,nameelmn))==0){
					printf("Ingrese el nombre del conjunto donde se agregara el elemento\n");
					scanf("%s",namec);
					if((validarconj(Listconjuntos,namec))==0)
						AggElmn(nameelmn,Listconjuntos,namec);
						else
							printf("El conjunto no existe\n");
				}else
					printf("Elemento No valido\n");
				
				break;
			case 51:
					printf("Ingrese la expresion a evaluar.\n");
					scanf("%s",Expr);
					val=parentesis(Expr);
					if(val==0){
						convpost(Expr,Exprpost);
						printf("%s",Exprpost);
						/*int ic=0,ic2=0;
						for(;ic<strlen(Exprpost);ic++){
							for(;;){
							}
							calcular(Listconjuntos,Listres,)
						}*/
						
						
					}else
						printf("Expresion mal formulada.\n");
						
				break;	
				case 52:
					
					printf("Ingrese el operador (x,+,-)\n");
					scanf("%s",op);
					printf("Ingrese el nombre del conjunto 1 \n");
					scanf("%s",conj1);
					printf("Ingrese el nombre del conjunto 2\n");
					scanf("%s",conj2);
					
					
					
					switch(op[0]){
						case '+':
								Listres=unionc(Listconjuntos,conj1,conj2);
								imp_conj(Listres,"resultadoun");
							break;
						case '-':Listres=complemento(Listconjuntos,conj1);
								imp_conj(Listres,"resultadocomp");
								
							break;
						case 'x':Listres=interseccion(Listconjuntos,conj1,conj2);
								imp_conj(Listres,"resultadointer");
							break;
					}
				break;					
		}	
	}
return 0;
}
