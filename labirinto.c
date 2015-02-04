//Una funzione che mi dice se due parole sono in relazione l'una con l'altra, in base alle tre regole fatte:
//- se una è l'anagramma dell'altra.
//- se una ha una lettera in più o in meno rispetto all'altra.
//- se cambia solo una lettera tra l'una e l'altra.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordina (char *p1)
{
    int i, j;
    char temp;
    int len_p1 = strlen(p1);
    
    for (j=0; j<len_p1-1; j++)//bubble sort
    {
        for (i=0; i< len_p1-1; i++)
        {
            if (p1[i] > p1[i+1])
            {
                temp = p1[i];
                p1[i] = p1[i+1];
                p1[i+1] = temp;
            }
        }
    }
}

int anagramma (char *p1, char *p2)
{
    char *p1_ord = strdup(p1); //così duplico una stringa
    char *p2_ord = strdup(p2);
    
    ordina(p1_ord);
    ordina(p2_ord);
    if (strcmp(p1_ord,p2_ord)==0) // così mi chiedo se sono uguali, se sono uguali strcmp tornerà 0 quindi se strcmp == 0 allora le due stringhe sono uguali e torno 1 se no 0
        return 1;
    return 0;
}

int main (int argc, char** argv) //argc mi dice quanti parametri passo, mentre argv è un'array che contiene tutti i parametri
{
    char *parole1 = {"abc"};
    char *parole2 = {"bsa"};
    
    printf ("%d\n", anagramma(parole1,parole2));//se una è l'anagramma dell'altra 1 se no 0
}