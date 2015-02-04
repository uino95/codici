#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *first, *last;

void crea()//mi crea una lista vuota
{
    first = NULL;
    last = NULL;
}


int potenza (int base,int esponente)//eleva la base all'esponente
{
    int risultato=0;
    
    if (esponente == 0)
        return 1;    
    
    risultato = base * potenza(base, esponente-1);
    return risultato;
}

void stampa (Node *first)//stampa la lista
{
    Node *t = first;
    while (t != NULL)
    {
        printf("%d-->", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int inserisci(char *stringa, int cifre, int i)//mi trasforma un pezzo di stringa in un intero
{
    int numero=0, esponente=0;
    while (cifre!=0)
    {
        if (stringa[i]=='-')
            numero-=numero*2;
        else
            numero += (stringa[i]-'0') * (potenza(10,esponente));
        cifre--;
        esponente++;
        i--;
    }
 
    return numero;
}

void aggiungi_elemento(int numero)//mi aggiunge l'elemento in coda
{
    //printf ("first è %p\n", first);
    //printf ("last è %p\n", last);
    Node *new;
    new = (Node*) malloc(sizeof(Node));
    new->data = numero;
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
   //printf ("first è %p\n", first);
   //printf ("last è %p\n", last);
   //stampa (first);
}

Node * trasforma_in_lista(char *stringa)//mi trasforma una stringa in una lista
{
    int i, l=strlen(stringa), c=0, numero=0;
    crea();
    
    for (i=0; i < l+1; i++)
    {
        if (stringa[i] != ' ' && stringa[i] != '\0')
            c++;
        
        if (stringa[i] == ' ' || stringa[i] == '\0')
        {
            numero = inserisci(stringa, c , i-1);
            //printf ("numero è %d\n", numero);
            aggiungi_elemento(numero);
            c = 0;
            //printf ("first è %p\n", first);
            //printf ("last è %p\n", last);
            //*lungh+=1;
        }
    }
    
    return first;
}

int main ()
{
    char *stringa1="123 46 68 80 905";
    char *stringa2 = "23 5 1 43 56 52";
    printf ("la stringa è %s\n", stringa1);
    printf("la lista è \n");
    stampa(trasforma_in_lista(stringa1));
    printf ("la stringa è %s\n", stringa2);
    printf("la lista è \n");
    stampa(trasforma_in_lista(stringa2));
}
