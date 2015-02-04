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
    int numero=0, esponente=0;
    while (cifre!=0)
    {
        if (stringa[i]=='-')//nel caso in cui il numero sia negativo dopo averlo convertito in intero gli sottraggo se stesso moltiplicato per 2 così da ottenre il negativo
            numero-=numero*2;
        else
            numero += (stringa[i]-'0') * (potenza(10,esponente));
        cifre--;
        esponente++;
        i--;
    }
 
    return numero;
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

int eval(char *expr) {//ritorno il numero convertito maggiore
    int i, tmp=0, numero=0;
    
    trasforma_in_lista(expr);
    printf("la lista è: ");
    stampa(first);
    
    Node *t = first;//lo uso per scorrere la lista
    
    while(t != NULL)
    {
        numero=converti(t, t->next);
        printf("il numero convertito è %d\n", numero);
        if (tmp == 0) //se è il primo giro
            tmp = numero;
        else
        {
            if(numero>tmp)
                tmp = numero;
        }
        
        t=t->next;//scorro la lista per coppie di numeri
        t=t->next;
    }
    return tmp;
}

int main()
{
    printf ("il numero maggiore è %d\n", eval("2 1     4 3 8 3"));
}