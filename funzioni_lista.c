#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valore;
    struct node *next;
}Node;


Node *first=NULL, *last=NULL;

void inserisci_inCoda(int valore)
{
    Node *new;
    new = (Node *) malloc(sizeof(Node));
    new->valore = valore;
    new->next = NULL;
    if (first == NULL)
    {
        first = new;
        last = new;
    }
    else 
    { 
        last->next=new; 
        last = new;
    }
}

void inserisci_inTesta(int valore)
{
    Node *new;
    new = (Node *) malloc(sizeof(Node));
    new->valore = valore;
    new->next = first;
    if (first == NULL)
    {
        last = new;
    }
    first = new;
}

void inserisci_dove_vuoi (int posizione, int valore)
{
    if (first == NULL){
        printf ("lista vuota\n");
        }
    
    Node *precedente = NULL;
    Node *corrente = first;
    Node *new;
    new = (Node *) malloc(sizeof(Node));
    new->valore= valore;
    if (posizione == 0)
    {
        new->next = first;
        if (first == NULL)
            last = new;
        first = new;
        return;}
        
    while (posizione > 0 && corrente != NULL)
    {
        precedente = corrente;
        corrente = corrente->next; 
        posizione --;
    }
    //printf("posizione è: %d\n", posizione);
    //printf("corrente è %p\n", corrente);
    //printf ("last è %d\n", last->valore);
    
    if (corrente == NULL && posizione > 0)
        {printf ("Non posso inserire il nuovo elemento\n");
        return;}
    
    if (corrente == NULL && posizione <= 0){
        precedente->next = new;
        last = new;
        new->next = NULL;
        return;
    }
    if (corrente->next == NULL){
        new->next = last;
        precedente->next = new;
    }
    else {
        new->next = corrente;
        precedente->next = new;
    }
}

void stampa (int valore)
{
    Node *t = first;
    while (t != NULL)
    {
        printf("%d-->", t->valore);
        t = t->next;
    }
    printf("NULL\n");
}
int main ()
{
    int valore=0, posizione=0;
    //crea();
    printf ("Inserisci un valore (-1 per finire)\n");
    scanf ("%d", &valore);
    
    
    while( valore != -1)
    {
       inserisci_inTesta(valore);
       stampa(valore);
       scanf ("%d", &valore);
    }
    printf("seleziona posizione e valore da inserire\n");
    scanf ("%d,%d", &posizione, &valore);
    inserisci_dove_vuoi(posizione, valore);
    stampa(valore);
}