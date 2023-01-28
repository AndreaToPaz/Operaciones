
//OpConAndAd.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Realiza operaciones de interseccion sobre dos conjuntos

str_conj* interseccion(str_conj* auxlist,char* conj1,char* conj2){
	conj_node* auxconj1=NULL;
	conj_node* auxconj2=NULL;
	str_conj* result;
	int i,j;
	
	i=ContarElmn(auxlist,conj1);
	j=ContarElmn(auxlist,conj2);
	 
	
	if(i>=j)
		for(;auxlist!=NULL;auxlist=auxlist->sig){
			if(strcmp(auxlist->name_conj,conj1)==0)
				auxconj1=auxlist->p_elmn_conj;
			else
				if(strcmp(auxlist->name_conj,conj2)==0)
					auxconj2=auxlist->p_elmn_conj;		    	
		}else{
			for(;auxlist!=NULL;auxlist=auxlist->sig){
				
				if(strcmp(auxlist->name_conj,conj1)==0)
					auxconj2=auxlist->p_elmn_conj;
				else
					if(strcmp(auxlist->name_conj,conj2)==0)
						auxconj1=auxlist->p_elmn_conj;
			}
		}
		
		if((auxconj1==NULL)||(auxconj2==NULL)){
			printf("Error Conjunto no existe");
			return NULL;
		}else{
	 		result=NuevoConj("resultadointer",auxlist);
	 		conj_node* auxconj2x; 
	 		for(;auxconj1!=NULL;auxconj1=auxconj1->sig){
	 		 	auxconj2x=auxconj2;
	 			for(;auxconj2x!=NULL;auxconj2x=auxconj2x->sig){
	 			if(strcmp(auxconj1->elemento,auxconj2x->elemento)==0){
	 				AggElmn(auxconj1->elemento,result,"resultadointer");
	 				break;
	 			}	
	 		}
	 		
	 	}                            
	}
	return result;
}

//Realiza Operaciones de union sobre dos conjuntos.

str_conj* unionc(str_conj* auxlist,char* conj1, char* conj2){
	conj_node* auxconj1=NULL;
	conj_node* auxconj2=NULL;
	str_conj* result=NULL;
	int i,j;
	
	i=ContarElmn(auxlist,conj1);
	j=ContarElmn(auxlist,conj2); 
	if(i>=j)
		for(;auxlist!=NULL;auxlist=auxlist->sig){
			if(strcmp(auxlist->name_conj,conj1)==0)
				auxconj1=auxlist->p_elmn_conj;
			if(strcmp(auxlist->name_conj,conj2)==0)
				auxconj2=auxlist->p_elmn_conj;	
		}
	else{
		for(;auxlist!=NULL;auxlist=auxlist->sig){
			if(strcmp(auxlist->name_conj,conj1)==0)
				auxconj2=auxlist->p_elmn_conj;
			if(strcmp(auxlist->name_conj,conj2)==0)
				auxconj1=auxlist->p_elmn_conj;
		}
	}	
	
	if((auxconj1==NULL)||(auxconj2==NULL)){
		printf("Error Conjunto no existe");
		return NULL;
	}else{
	 	result=NuevoConj("resultadoun",auxlist);
	 	 
	 	 conj_node* auxconj2x; 
	 	for(;auxconj1!=NULL;auxconj1=auxconj1->sig,auxconj2x=auxconj2){
	 		int f=0;
	 		for(f=0;auxconj2x!=NULL;auxconj2x=auxconj2x->sig){
	 			if(strcmp(auxconj1->elemento,auxconj2x->elemento)==0){
	 				f=1;
	 				AggElmn(auxconj1->elemento,result,"resultadoun");
	 				break;
	 			}	
	 		}
	 		if(f==0){
	 			
	 			AggElmn(auxconj1->elemento,result,"resultadoun");	
	 		}
	 	}                            
	}
	return result;
}

//Realiza operaciones de complemento sobre un conjunto

str_conj* complemento(str_conj* auxlist,char* conj){
	
	conj_node* auxnodec=NULL;
	conj_node* auxnodeuniv=NULL;
	auxnodeuniv=auxlist->p_elmn_conj;
	str_conj* auxlist1=auxlist;
	str_conj* result=NULL;

	for(;auxlist!=NULL;auxlist=auxlist->sig){
		if(strcmp(auxlist->name_conj,conj)==0)
			auxnodec=auxlist->p_elmn_conj;
	}
	if(auxnodec==NULL){
		printf("No existe el conjunto\n");
		return NULL;
	}
	result=NuevoConj("resultadocomp",auxlist);
	
	conj_node* auxnodec2=NULL;
	for(;auxnodeuniv!=NULL;auxnodeuniv=auxnodeuniv->sig){
		auxnodec2=auxnodec;
		for(;auxnodec2!=NULL;auxnodec2=auxnodec2->sig){
			if(strcmp(auxnodeuniv->elemento,auxnodec2->elemento)==0)
				break;
			if(auxnodec2->sig==NULL){
				AggElmn(auxnodeuniv->elemento,result,"resultadocomp");
				break;
			}
		}
	}
return result;		
}

//Para extraer secciones de un string.

void copianro(char* expr,char*expr2,int ini,int fin){
	int j=0;
	for(;ini<=fin;ini++,j++){
		expr2[j]=expr[ini];
	}

}


//recibe la expresion a evaluar y realiza la llamada a la funcion correspondiente a la operacion

/*void calcular(str_conj*auxlist,str_conj*reslist,char*expr){
	int poscj1=0,poscj2=0,j,i,i2;
	char op;
	char conj1[50],conj2[50]
	
	for(j=0;j<strlen(expr);j++){
		switch(expr[j]){
			case '+':
				copianro();
				
				
				
				break;
			case '-':
				break;
			case 'X':
				break;	
		
		}
	
	}	








}*/





