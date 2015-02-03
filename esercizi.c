#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *next;
};

typedef struct node Lista;
typedef Lista *ListaPtr;

void stampaLista(Lista *start)
{
    if (start==NULL)
        printf("La lista è vuota\n");
    else
    {
        while(start !=NULL)
        {
            printf("%c --> ", start->data);
            start = start->next;
        }
        printf ("NULL\n");
    }
}
void inserisci(Lista *start, char elemento)
{
    ListaPtr new;
    ListaPtr precedente;
    ListaPtr corrente;
    
    new = malloc(sizeof(Lista));
    
    if (new != NULL)
    {
        new->data=elemento;
        new->next=NULL;
        
        precedente = NULL;
        corrente = start;
        
        while(corrente != NULL && elemento > corrente->data)
        {
            precedente = corrente;
            corrente = corrente->next;
        }
        
        if (precedente == NULL)
        {
            new->next = start;
            start = new;
        }
        else
        {
            precedente->next=new;
            new->next = corrente;
        }
    }
    else 
        printf("%c non inserito. Non c'è memoria a sufficienza\n", elemento);
}
int main (void)
{
    ListaPtr start = NULL;
    char elemento;
    printf("Inserisci una lettera: \n");
    scanf ("%c", &elemento);
    inserisci(start, elemento);
    stampaLista(start);
}