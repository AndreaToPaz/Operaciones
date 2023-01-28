//Interprete.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Pu 2
#define Pi 3
#define Pc 4
#define ppp 1
#define ppe 5

void convpost(char* expinf,char*exppost){
	nodo_pila* tope=NULL;
	
	int i=0;
	for (;i<strlen(expinf);i++){
		//printf("1-%s\n",exppost);
		if(tope==NULL){
			if((expinf[i]=='x')||(expinf[i]=='+')||(expinf[i]=='-')||(expinf[i]=='(')){
					switch(expinf[i]){
						case 'x':
							tope=push(tope,"x");
							break;
						case '+':
							tope=push(tope,"+");
							
							break;
						case '-':
							tope=push(tope,"-");
							break;
						case '(':
							
							tope=push(tope,"(");
					}
				
				
			}else{
				char auxstr[30]=" ";
				int j;
				int ini,fin;
				ini=i;
				for(j=i;(expinf[j]!='x')&&(expinf[j]!='+')&&(expinf[j]!='-')&&(expinf[j]!='(')&&(expinf[j]!=')')&&(expinf[j]!='(')&&(j<strlen(expinf));j++);
				
				fin=j-1;
				
				copianro(expinf,auxstr,ini,fin);
				auxstr[strlen(auxstr)+1]='.';				
				strcat(exppost,auxstr);
				
			}	
		}else
			if(tope!=NULL){
				if((expinf[i]=='x')||(expinf[i]=='+')||(expinf[i]=='-')||(expinf[i]=='(')||(expinf[i]==')')){
					char auxstr1[30]="";
					char auxstr[2]="";
					char strasig[10]="";
					char tops[2]="";
					strcpy(tops,top(tope));
					switch(expinf[i]){
						case ')':
							
							while(strcmp(auxstr,"(")!=0){
								strcpy(auxstr,top(tope));
								
								tope=pop(tope,strasig);
								
									if(strcmp(strasig,"(")==0)
										break;
								
								strcat(exppost,strasig);	
								}
							break;
						case 'x':
							switch(tops[0]){
								case '-':
										auxstr[0]=expinf[i];
										if(Pi>Pc){
											tope=push(tope,auxstr);
										}else{
											tope=pop(tope,auxstr1);
										
											strcat(exppost,auxstr1);
											tope=push(tope,auxstr);	
										}	
									break;
								case '+':
										auxstr[0]=expinf[i];
										if(Pi>Pu){
											tope=push(tope,auxstr);
										}else{
											tope=pop(tope,auxstr1);
											strcat(exppost,auxstr1);
											tope=push(tope,auxstr);
										}
									break;
								case '(':
										auxstr[0]=expinf[i];
										tope=push(tope,auxstr);
										
									break;
							}
								
							break;
						case '+':
							
								switch(tops[0]){
								case '-':
										auxstr[0]=expinf[i];
										if(Pu>Pc){
											tope=push(tope,auxstr);
										}else{
											tope=pop(tope,auxstr1);
											strcat(exppost,auxstr1);
											tope=push(tope,auxstr);	
										}	
									break;
								case 'x':
										auxstr[0]=expinf[i];
										if(Pu>Pi){
											tope=push(tope,auxstr);
										}else{
											tope=pop(tope,auxstr1);
											strcat(exppost,auxstr1);
											tope=push(tope,auxstr);
										}
									break;
								case '(':
								
										auxstr[0]=expinf[i];
										
										tope=push(tope,auxstr);
										
									break;
							}
							
							break;
						case '-':
								switch(tops[0]){
								case 'x':
										auxstr[0]=expinf[i];
										if(Pc>Pi){
											tope=push(tope,auxstr);
										}else{
											tope=pop(tope,auxstr1);
											strcat(exppost,auxstr1);
											tope=push(tope,auxstr);	
										}	
									break;
								case '+':
										auxstr[0]=expinf[i];
										if(Pc>Pu){
											tope=push(tope,auxstr);
										}else{
											tope=pop(tope,auxstr1);
											strcat(exppost,auxstr1);
											tope=push(tope,auxstr);
										}
									break;
								case '(':
										auxstr[0]=expinf[i];
										tope=push(tope,auxstr);	
									break;
							}
							
							break;
						case '(':
							auxstr[0]=expinf[i];
							tope=push(tope,auxstr);
							break;
							

					}
			}else{
				char auxstr[30]="";
				int j;
				int ini,fin;
				ini=i;
				
				for(j=i;(expinf[j]!='x')&&(expinf[j]!=')')&&(expinf[j]!='+')&&(expinf[j]!='-')&&(expinf[j]!='(')&&(j<strlen(expinf));j++);
				fin=j-1;
				
				copianro(expinf,auxstr,ini,fin);
				
				auxstr[strlen(auxstr)+1]='.';				
				strcat(exppost,auxstr);
				
			}				
	
	}
	
	
}
	if(tope!=NULL){
		while(tope!=NULL){
			
			char str3[2]="";
			tope=pop(tope,str3);
			
			if(strcmp(str3,"(")!=0)
			strcat(exppost,str3);
		}
	}
			
}
