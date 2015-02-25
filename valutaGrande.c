#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int potenza (int base,int esponente)//eleva la base all'esponente desiderato
{
    int risultato=0;
    
    if (esponente == 0)
        return 1;    
    
    risultato = base * potenza(base, esponente-1);
    return risultato;
}

int nlen (int n)//mi da la linghezza di un numero
{
    if (n<10) return 1;
    return 1 + nlen(n/10);
}

char * itoa (int x)//da un intero ad una stringa
{
    int i;
    int len = nlen(x);
    char *res = malloc (sizeof(char)*len+1);//+1 perchè alla fine della stringa ci va sempre il terminatore
    for (i=len-1; i>=0; i--){//scorro al contrario fino a 0, perche ricorda che la stringa è un vettore di caratteri quindi la prima posizione è lo 0 mentre l'ultima è len-1
        res[i] = (x%10 + '0');
        x=x/10;
    }
    res[len] = '\0';//poi inserisco il terminatore
    return res;
}

char* inverti (char* risultato)
{
    int j, i, len=strlen(risultato);
    char hold;
    //printf("il risultato prima di essere invertito è %s\n", risultato);
    for (j=len; j>0; j--)
    {
        for (i=0; i<j-1; i++)
        {
            hold = risultato[i];
            risultato[i] = risultato [i+1];
            risultato[i+1] = hold;
        }
    }
    //printf("il risultato invertito è %s\n", risultato);
    return risultato;
}
char * prima(char *espressione, int cifre, char *risultato)
{
    int i=0;
    espressione--;
    while (cifre!=0)
    {
        //printf("il risultato parziale è %s\n", risultato);
        risultato[i] = (*espressione);
        i++;
        cifre--;
        espressione--;
        //printf("il risultato parziale è %s\n", risultato);
    }
    printf("il risultato parziale prima è %s\n", risultato);
    return risultato;
}

char *sottrazione(char *espressione, int cifre, char  *risultato)
{
    int n1=0, n2=0, riporto=0, tmp=0, esponente=0, indice = 0;
    char *pot = malloc(sizeof(char)*strlen(espressione));
    
    *pot = '0';
    //char *parziale = risultato
    espressione--; 
    while (cifre!=0){
        printf("sono ancora dentro il while\n");
        n1 = (risultato[indice]-'0');
        n2 = (*espressione-'0');
        printf ("n1 è: %d\n", n1);
        printf ("n2 è: %d\n", n2);
        n1 -= riporto;
        if ((n1-n2)<0)
        {
            n1+=10;
            riporto = 1;
            tmp = n1-n2;
        }
        else
        {
            tmp = n1 - n2;
            riporto=0;
        }
        //tmp = tmp%10;
        printf("tmp è: %i\n", tmp);
        printf("cifre é %d\n", cifre);
        pot[indice] = potenza(10,esponente)%10 + '0';
        printf("pot è: %s\n", pot);
        risultato[indice] = tmp + '0';
        //printf("indice è %d\n", indice);
        //printf ("il parziale è %s\n", risultato);
        cifre--;
        espressione--;
        indice+= 1;
        esponente ++;
        //if (riporto !=0 && cifre==0)
        //{
         //   risultato = sottrazione (risultato, esponente, pot);
        //}
    }
    
    printf("il risultato parziale è %s\n", risultato);
    return risultato;
}
    
char * addizione(char *espressione, int cifre, char  *risultato)
{
    int n1=0, n2=0, riporto=0, tmp=0, esponente=0, indice = 0;
    //char *parziale = risultato
    espressione--; 
    while (cifre!=0){
        n1 = (*espressione-'0');
        n2 = (risultato[indice]-'0');
        //printf ("n1 è: %d\n", n1);
        //printf ("n2 è: %d\n", n2);
        tmp = n1 + n2 + riporto;
        riporto = tmp/10;
        tmp = tmp%10;
        //printf("tmp è: %i\n", tmp);
        risultato[indice] = tmp + '0';
        //printf("indice è %d\n", indice);
        //printf ("il parziale è %s\n", risultato);
        cifre--;
        espressione--;
        indice+= 1;
    }
    
    printf("il risultato parziale è %s\n", risultato);
    return risultato;
}
    
char *eval(char *espressione)//valuta un espressione data sottoforma di stringa
{
    int cifre = 0, contatore = 0;
    char *risultato = malloc(sizeof(char)*strlen(espressione));
    
    *risultato = '0';
    
    while(*espressione != '\0')
    {
        if ((*espressione) != '+' || (*espressione) != '-' || (*espressione) != '*' || (*espressione) != '/')
        {
            cifre++;
            contatore++;
        }
        espressione ++;
       
        if ((*espressione) == '+' || (*espressione) == '-' || (*espressione) == '*' || (*espressione) == '/'|| (*espressione) =='\0')//mi somma solamente il primo numero a 0
        {
            if (contatore == cifre)
            {
                risultato = prima(espressione, cifre, risultato);
                cifre=0;
                espressione ++;
                //printf("espressione vale: %s\n", espressione);
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
                    printf ("il risultato temporaneo è: %s\n", risultato);
                }
                cifre=0;//tutte le volte devo reinizializzare le cifre a 0 ed impostare l'espressione avanti di uno per poter partire subito col numero dopo e non con l'operatore
            }
        }
    }
    risultato = inverti(risultato);
    //risultato[strlen(espressione)] = '\0';
    return risultato;
}

int main()
{
    char *espressione = malloc (sizeof(char));
    
    printf ("inserisci il testo dell'espressione che vuoi valutare: \n");
    scanf ("%s", espressione);
    printf("il risultato di: %s è: %s\n", espressione, eval(espressione));
}