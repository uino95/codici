#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *first, *last;

void crea()//creo una lista vuota
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

void stampa (Node *first)//stampa una lista
{
    Node *t = first;
    while (t != NULL)
    {
        printf("%d-->", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int inserisci(char *stringa, int cifre, int i)//trasforma una pezzo di stringa in numero
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

void aggiungi_elemento(int numero)//aggiunge un numero in coda alla lista
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

int seleziona_elemento(Node *start, int posizione)//seleziona l' elemento della lista indicato da posizione
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
    
    if (corrente == NULL || posizione < 0)
    {
        printf ("Non posso selezionare l'elemento\n");
        return 0;
    }
    else
        return corrente->data;
}

Node * trasforma_in_lista(char *stringa)//trasforma una stringa in una lista
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
            aggiungi_elemento(numero);
            c = 0;
        }
    }
    stampa(first);
    return first;
}

int eval(char * val, char * pos) //ritorna il numero maggiore della lista Val tra quelli indicati dalla lista Pos
{
    printf("\n");
    Node *startVal = trasforma_in_lista(val);
    Node *startPos = trasforma_in_lista(pos);
    
    int tmp=0, i;
    Node *Val = startVal;
    Node *Pos = startPos;
    
    while (Pos != NULL)
    {   
        if (tmp == 0)
            tmp = seleziona_elemento(Val, Pos->data); 

        else{
            if (seleziona_elemento(Val, Pos->data) < tmp)
                tmp = seleziona_elemento(Val, Pos->data);}
        Pos = Pos->next;
    }
    return tmp;
}

int main()
{
    printf("il numero è: %d\n", eval("7220 71 42 78 78 63 25 272 53", "2 4 1 6 0"));
}