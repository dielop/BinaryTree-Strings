#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define long_max 25
#define TRUE 1
#define FALSE 0


typedef struct nodo
{
      char dato[long_max];
      struct nodo *izquierda,*derecha; 
}arbol;

//declaracion de funciones
void insert(arbol**, char[]);
int isMember(arbol*, char[]);
char deleteMin(arbol**); 
void delete(arbol**, char[]);
void pre_orden(arbol*);
void in_orden(arbol*);
void post_orden(arbol*);

int main()
{
    arbol *raiz;
    raiz = NULL;

    insert (&raiz, "juan");
    insert (&raiz, "diego");
    insert (&raiz, "chau");
    insert (&raiz, "pedro");
    insert (&raiz, "jaja");

    //Imprimo los distintos ordenes

    printf("\nImprimo PRE-ORDER\n\n");
    pre_orden(raiz);
    printf("\nImprimo IN-ORDER\n\n");
    in_orden(raiz);
    printf("\nImprimo POST-ORDER\n\n");
    post_orden(raiz);
   
    //Corroboro si los elementos estan
    if (isMember (raiz, "tomas") == TRUE)
        printf ("El elemento existe\n");
     else    
        printf ("El elemento no existe\n");

     if (isMember (raiz, "juan") == TRUE)
        printf ("El elemento existe\n");
     else    
        printf ("El elemento no existe\n");    
     return 0;    
}

void insert(arbol **A, char x[])
{
  if(*A == NULL)
    {
       *A = (arbol*)malloc(sizeof(arbol));
       strcpy((*A)->dato, x);
       (*A)->izquierda = NULL;
       (*A)->derecha = NULL;
    }   
  else
  {
      if (x<(*A)->dato)
         insert (&((*A)->izquierda),x);
         else if (x > (*A)->dato)
         insert (&((*A)->derecha),x);
  }

}

int isMember(arbol *A, char x[])
{
    if (A!=NULL){
     if (A->dato == x)
        return TRUE;
     else if (A->dato > x)
     return isMember (A->izquierda, x);
     else 
     return isMember (A->derecha, x);    
     }else{
         return FALSE;
     }
 
}

char deleteMin(arbol**A)
{
    char ref[long_max];
    if ((*A)->izquierda == NULL)
    {
        strcpy(ref,(*A)->dato);
        arbol *tmp = *A;
        *A = (*A)->derecha;
        free (tmp);
        return *ref;
    }
    else
    {
        return deleteMin(&((*A)->izquierda));
    }
} 

void delete (arbol **A, char x[]){
    if (*A != NULL){
        if (x < (*A)->dato)
            delete (&((*A)->izquierda), x);
        else if (x > (*A) ->dato)
            delete (&((*A)->derecha), x);
        else if ((*A)->izquierda == NULL && (*A)->derecha == NULL ){
            arbol *tmp = *A;
            *A = NULL ;
            free (tmp);
        }
        else if ((*A)->izquierda == NULL ){
            arbol *tmp = *A;
            *A =(*A)->derecha;
            free (tmp);
        }
        else if ((*A)->izquierda == NULL ){
            arbol *tmp = *A;
            *A = (*A)->izquierda;
            free (tmp);
        }
        else { // ambos hijos estan presentes
        strcpy((*A)->dato,deleteMin(&((*A)->derecha)));
        }
    }
}

void pre_orden(arbol*A)
{
    if (A!=NULL)
    {
       printf("%s\n",A->dato);
       pre_orden(A->izquierda);
       pre_orden(A->derecha);
    }

}

void post_orden(arbol*A)
{
    if (A!=NULL)
    {
       post_orden(A->izquierda);
       post_orden(A->derecha);
       printf("%s\n",A->dato);
    }

}

void in_orden(arbol*A)
{
    if (A!=NULL)
    {
       in_orden(A->izquierda);
       printf("%s\n",A->dato);
       in_orden(A->derecha);
    }

}
