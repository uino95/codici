#include <stdio.h>
#include <stdlib.h>

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

int main (){
    char *stringa = malloc (sizeof(char));
    int x,y,risultato=0;

    //printf ("la stringa è: %s\n", stringa);
    printf("inserisci un numero\n");
    scanf("%d", &x);
    printf("inserisci un altro numero\n");
    scanf("%d", &y);
    risultato = x+y;
    printf ("la somma è %s+%s\n",itoa(x), itoa(y) );
    printf ("il risultato è %s\n", itoa(risultato));
    return 0;
}