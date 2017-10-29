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
    int numero=0, esponente=0, totale=0;
    while (cifre!=0)
    {
        if (!isdigit(stringa[i])){
            totale+= stringa[i]=='+' ? numero : numero*(-1);
            numero=0;
            esponente=0;}
        else{
            numero += (stringa[i]-'0') * (potenza(10,esponente));
            esponente++;}
        cifre--;
        i--;
    }
    totale+=numero;
    return totale;
}

void aggiungi_elemento(int numero, Node **start)
{
    Node *new;
    new = (Node*) malloc(sizeof(Node));
    new->data = numero;
    new->next = NULL;
    if (*start == NULL)
    {
        *start = new;
        last = new;
    }
    else 
    { 
        last->next=new; 
        last = new;
   }
}

int seleziona_elemento(Node *start, int posizione)
{
    if (start == NULL)
    {
        printf ("lista vuota\n");
        return 0;
    }
    Node *corrente = start;
    Node *precedente = NULL;
    
    while (posizione > 0 && corrente != NULL)
    {
        precedente = corrente;
        corrente = corrente->next;
        posizione --;
    }
    
    if (corrente == NULL || posizione<0)
    {
        printf ("Non posso selezionare l'elemento\n");
        return 0;
    }
    else 
        return corrente->data;
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

                aggiungi_elemento(numero, &first);
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

int eval(char *ns, char *is) {
    int tmp=0, numero=0;
    
    Node *valori = trasforma_in_lista(ns);
    stampa(valori);
    Node *posizioni = trasforma_in_lista(is);
    stampa(posizioni);
    Node *t = valori;
    crea();
    Node *val = first;
    Node *pos = posizioni;
    while(t != NULL)
    {
        numero = converti(t, t->next);
        printf("numero convertito: %d\n", numero);
        aggiungi_elemento(numero, &val);
        t=t->next;
        t=t->next;
    }
    stampa(val);
    while(pos != NULL)
    {
        if (tmp == 0)
        {
            tmp = seleziona_elemento(val, pos->data);
        }
        else
        {
            if (seleziona_elemento(val, pos->data) > tmp)
                tmp = seleziona_elemento(val, pos->data);
        }
        pos=pos->next;
    }
    return tmp;
}

int main()
{
    printf ("il numero maggiore è %d\n", eval("9 -4 3 1 7 -3 3 2","5 0 3 6"));
}