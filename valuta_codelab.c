#include <stdio.h>
#include <stdlib.h>


int potenza (int base,int esponente)
{
    int risultato=0;
    
    if (esponente == 0)
        return 1;    
    
    risultato = base * potenza(base, esponente-1);
    return risultato;
}

int addizione(char *espressione, int cifre, int risultato)
{
    int esponente = 0, numero = 0;
    espressione--; 
    while (cifre!=0){
        numero += (*espressione-'0') * (potenza(10,esponente));
        cifre--;
        esponente++;
        espressione--;
    }
    risultato += numero; 
    return risultato;
}

int sottrazione (char *espressione, int cifre, int risultato)
{
    int esponente=0, numero = 0;
    espressione--; 
    while (cifre!=0){
        numero += (*espressione-'0') * (potenza(10,esponente));
        cifre--;
        esponente++;
        espressione--;
    }
    risultato -= numero;
    return risultato;
}  

int eval(char *espressione)
{
    int risultato = 0, numero = 0, cifre = 0, esponente = 0, contatore = 0;
    while(*espressione != '\0')
    {
        if ((*espressione) != '+' || (*espressione) != '-' )
        {
            cifre++;
            contatore++;
        }
        espressione ++;
        
        if ((*espressione) == '+' || (*espressione) == '-' || (*espressione) =='\0')
        {
            if (contatore == cifre)
            {
                risultato = addizione(espressione, cifre, risultato);
                cifre=0;
                espressione ++;
            }
            else
            {
                if (*(espressione-(cifre+1)) == '+')//se quello che c'era prima del numero era un + questa mi fa l'addizione
                {
                    risultato = addizione(espressione, cifre, risultato);
                    espressione ++;
                }
                if (*(espressione-(cifre+1)) == '-')
                {
                    risultato = sottrazione(espressione, cifre, risultato);
                    espressione ++;  
                    //printf ("il risultato temporaneo è: %s\n", risultato);
                }
                cifre=0;//tutte le volte devo reinizializzare le cifre a 0 ed impostare l'espressione avanti di uno per poter partire subito col numero dopo e non con l'operatore
            }
        }
    }
    return risultato;
}


int main()
{
    char *espressione = malloc (sizeof(char));
    
    printf ("inserisci il testo dell'espressione che vuoi valutare: \n");
    scanf ("%s", espressione);
    printf("il risultato di: %s è: %d\n", espressione, eval(espressione));
}

