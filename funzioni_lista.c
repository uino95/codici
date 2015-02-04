#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valore;
    struct node *next;
}Node;


Node *first=NULL, *last=NULL;//inizializzo una lista vuota, semplicemente mettendo a NULL il primo e l'ultimo elemento che per adesso qundi coincidono

void inserisci_inCoda(int valore)//inserisco in coda i nuovi elementi della lista
{
    Node *new;//dichiaro un nuovo nodo
    new = (Node *) malloc(sizeof(Node));//gli alloco lo spazio
    new->valore = valore;//inserisco il valore che voglio nel nuovo nodo
    new->next = NULL;
    if (first == NULL)//se la lista è vuota, allora il primo elemento sarà sia il primo che l'ultimo
    {
        first = new;
        last = new;
    }
    else //se no il nuovo elemento diventerà l'ultimo elemento
    { 
        last->next=new; 
        last = new;
    }
}

void inserisci_inTesta(int valore)//inserisco in testa
{
    Node *new;
    new = (Node *) malloc(sizeof(Node));
    new->valore = valore;
    new->next = first;//il nuovo elemento punterà al primo elemento della lista
    if (first == NULL)//se vuota sarà anche l'ultimo
    {
        last = new;
    }
    first = new;//poi diventa lui il primo elemento della lista
}

void inserisci_dove_vuoi (int posizione, int valore)//inserisco il nuovo elemento nella posizione che gli passo
{
    if (first == NULL){
        printf ("lista vuota\n");
        }
    
    Node *precedente = NULL;//dichiaro un precedente che per adesso tende a NULL e un corrente che tende al primo elemento della lista
    Node *corrente = first;
    Node *new;
    new = (Node *) malloc(sizeof(Node));
    new->valore= valore;
    if (posizione == 0)//se la posizione è 0 semplicemente lo inserisco in testa
    {
        new->next = first;
        if (first == NULL)
            last = new;
        first = new;
        return;}//e poi esco perche ho finito
        
    while (posizione > 0 && corrente != NULL)//se no scorro la lista fino a quando non avrò trovato la mia posizione
    {
        precedente = corrente;
        corrente = corrente->next; 
        posizione --;
    }
    //printf("posizione è: %d\n", posizione);
    //printf("corrente è %p\n", corrente);
    //printf ("last è %d\n", last->valore);
    
    if (corrente == NULL && posizione > 0)//se esco dal ciclo while perche la posizione selezionata non è presente nella lista allora non posso inserire il nuovo elemento
        {printf ("Non posso inserire il nuovo elemento\n");}
    
    if (corrente == NULL && posizione <= 0){//se invece seleziono il primo elemento dopo l'ultimo allora inserisco in coda
        new->next = NULL;
        if (first == NULL){
            first = new;
            last = new;}
        else{
            precedente->next = new;
            last = new;}
    }
    else{//altrimenti il nuovo elemento si inserisce in mezzo tra corrente e precedente
        new->next = corrente;
        precedente->next = new;
    }
}

void stampa (int valore)//mi stampa una lista in questo modo: elemento-->elemento-->NULL
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
        //inserisci_inCoda(valore);
        inserisci_inTesta(valore);
        stampa(valore);
        scanf ("%d", &valore);
    }
    printf("seleziona posizione e valore da inserire\n");
    scanf ("%d,%d", &posizione, &valore);
    inserisci_dove_vuoi(posizione, valore);
    stampa(valore);
}