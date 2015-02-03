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
    char *res = malloc (sizeof(char)*len+1);
    for (i=len-1; i>=0; i--){
        res[i] = (x%10 + 48);
        x=x/10;
    }
    res[len] = '\0';    
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