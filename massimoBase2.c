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

int potenza (int base,int esponente)
{
    int risultato=0;
    
    if (esponente == 0)
        return 1;    
    
    risultato = base * potenza(base, esponente-1);
    return risultato;
}

int inserisci(char *stringa, int cifre, int i)//trasformo un pezzo di stringa in un numero
{
    int numero=0, esponente=0, totale=0;
    while (cifre!=0)
    {
        if (stringa[i]=='+')
        {
            totale+=numero;
            numero=0;
            esponente = 0;
        }
        else
        {
            if (stringa[i] == '-')
            {
                totale-=numero;
                numero=0;
                esponente = 0; 
            }
            else
            {
                numero += (stringa[i]-'0') * (potenza(10,esponente));
                esponente++;
            }
        }  
        cifre--;
        i--;
    }
    totale += numero;
    return totale;
}

void aggiungi_elemento(int numero)//aggiungo numero in coda alla lista
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
    
    if (corrente == NULL || posizione < 0)
    {
        printf ("Non posso selezionare l'elemento\n");
        return 0;
    }
    else
        return corrente->data;
}


Node * trasforma_in_lista(char *stringa)//trasformo la stringa in una lista
{
    int i, l=strlen(stringa), c=0, numero=0;
    crea();
    
    for (i=0; i < l+1; i++)
    {
        if (stringa[i] != ' ' && stringa[i] != '\0')
            c++;
        
        if ((stringa[i] == ' ' || stringa[i] == '\0') && (stringa[i-1] == ' ' || i == 0));//questo nel caso abbia più spazi allora non faccio niente
        
        else{
            if (stringa[i] == ' ' || stringa[i] == '\0')
            {
                numero = inserisci(stringa, c , i-1);

                aggiungi_elemento(numero);
                c = 0;
    
            }
        }
    }
    stampa (first);
    return first;
}
int converti(Node *tmp, Node *tmps)//converto il numero puntato da tmps nella base puntata da tmp
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

int eval(char *expr, char *expr2) {//ritorno il numero convertito maggiore
    int i, tmp=0, numero=0;
    printf("i valori sono\n");
    Node *valori = trasforma_in_lista(expr);
    
    printf ("le posizioni sono\n");
    Node *posizioni = trasforma_in_lista(expr2);
    
    crea();//creo una nuova lista in cui andrò ad inserire i valori convertiti
    Node *t = valori;//lo uso per scorrere la lista dei valori
    Node *p = posizioni;//lo uso per scorrere la lista delle posizioni
    while(t != NULL)
    {
        numero=converti(t, t->next);
        printf("il numero convertito è %i\n", numero);
        aggiungi_elemento(numero);//aggiungo il numero alla nuova lista
        t=t->next;//scorro la lista per coppie di numeri
        t=t->next;
    }
    printf("la lista dei valori coi numeri convertiti è:\n");
    stampa(first);
    while(p != NULL)
    {
        if (tmp == 0)
            tmp = seleziona_elemento(first, p->data); 

        else
        {
            if (seleziona_elemento(first, p->data) > tmp)
                tmp = seleziona_elemento(first, p->data);
        }
        printf("tmp è %d\n", tmp);
        p = p->next;
    }
    return tmp;
}

int main()
{
    printf ("il numero maggiore è %d\n", eval("9 -4 3 1 7 -3 3 2","2"));
}