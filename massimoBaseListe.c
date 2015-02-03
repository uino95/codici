#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *first, *last;

void crea()
{
    first = NULL;
    last = NULL;
}

void stampa (Node *first)
{
    Node *t = first;
    while (t != NULL)
    {
        printf("%d-->", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int potenza (int base,int esponente)
{
    int risultato=0;
    
    if (esponente == 0)
        return 1;    
    
    risultato = base * potenza(base, esponente-1);
    return risultato;
}

int inserisci(char *stringa, int cifre, int i)
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

void aggiungi_elemento(int numero)
{
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
}

Node * trasforma_in_lista(char *stringa)
{
    int i, l=strlen(stringa), c=0, numero=0;
    crea();
    
    for (i=0; i < l+1; i++)
    {
        if (stringa[i] != ' ' && stringa[i] != '\0')
            c++;
        
        if ((stringa[i] == ' ' || stringa[i] == '\0') && (stringa[i-1] == ' ' || i == 0));
        
        else{
            if (stringa[i] == ' ' || stringa[i] == '\0')
            {
                numero = inserisci(stringa, c , i-1);

                aggiungi_elemento(numero);
                c = 0;
    
            }
        }
    }
    return first;
}

int converti(Node *tmp, Node *tmps)
{
    int risultato=0, c=0;
    int base=tmp->data;
    int numero=tmps->data;
    while(numero!= 0){
        risultato += (numero%10) * potenza(base,c);
        c++;
        numero/=10;
    }

    return risultato;
}

int eval(char *expr) {
    int i, l=0, tmp=0, numero=0;
    trasforma_in_lista(expr);
    Node *t = first;
    while(t != NULL)
    {
        numero=converti(t, t->next);
        if(numero>tmp)
            tmp = numero;
        t=t->next;
        t=t->next;
    }
    return tmp;
}

int main()
{
    printf ("il numero maggiore è %d\n", eval("2 1 4 3 8 3"));
}