//OpConAndAd.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

str_conj* interseccion(str_conj* auxlist,char* conj1,char* conj2);  		//Interseccion de conjuntos
str_conj* unionc(str_conj* auxlist,char* conj1, char* conj2);       		//Union de conjuntos
str_conj* complemento(str_conj* auxlist,char* conj);						//Complemento de conjunto
void copianro(char* expr,char*expr2,int ini,int fin);						//Para extraer secciones de un string
void calcular(str_conj*auxlist,str_conj*reslist,char*conj1,char*conj2);		//Llama a la funcion correspondiente a la operacion
