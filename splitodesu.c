#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char **split ( char *string, const char sep) {

  //declaraciones de variables
    char **lista, *p = string;
    int i = 0, pos;
    const int len = strlen (string);

  lista = (char **) malloc (sizeof (char *));
    if (lista == NULL) {
      return NULL;  
    }
  lista[pos=0] = NULL;

  while (i < len) {
    while ((p[i] == sep) && (i < len)) i++; 
      if (i < len) { 
        char **tmp = (char **) realloc (lista , (pos + 2) * sizeof (char *));
        // Validacion de puntero temporal    
        if (tmp == NULL) {  
          free (lista); 
          return NULL; 
        }    
        lista = tmp; tmp = NULL;    
        lista[pos + 1] = NULL; 
        lista[pos] = (char *) malloc (sizeof (char));
          //Validacion de String 
        if (lista[pos] == NULL) { 
          for (i = 0; i < pos; i++) 
            free (lista[i]); 
          free (lista); 
          return NULL; 
        } 
        int j = 0; 
        for (i; ((p[i] != sep) && (i < len)); i++) { 
          lista[pos][j] = p[i];   
          j++; 
          char *tmp2 = (char *) realloc (lista[pos],(j + 1) * sizeof (char)); 
          if (lista[pos] == NULL) { 
            for (i = 0; i < pos; i++) 
              free (lista[i]); 
            free (lista); 
            return NULL; 
          } 
          lista[pos] = tmp2; 
          tmp2 = NULL; 
        } 
      lista[pos][j] = '\0';   
      pos++; 
    } 
  } 
  return lista; 
} 




//VALIDACION DE PARENTESIS
int parentesis(char *aux){
 //DECLARACION DE VARIABLES
 int logitud = 0, balance = 0, i;
//----------------------------------    
    logitud = strlen(aux)-1;
    for(i = 0; i <= logitud;i++){
        if(aux[i] == '(')
           balance++; 
        else
            if(aux[i] == ')')
                balance--;
                
        if(aux[0] == ')')
            return 1;
            
    }        
    if(balance != 0)
        return 1;

return 0;
}


//VALIDACION DE NEGACIONES
int negacion(char *aux){
 //DECLARACION DE VARIABLES
 int longitud = 0, i , cont = 0;
 //----------------------------------
    longitud = strlen(aux)-1;
    for(i = 0; i <= longitud; i++){
        if(aux[i] == '-')
            cont++;
    }
    
    if((cont % 2) != 0)
        return 1;    

return 0;
}
