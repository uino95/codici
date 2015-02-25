#include <stdio.h>

int potenza (int base,int esponente)
{
    int risultato=0;
    
    if (esponente == 0)
        return 1;    
    
    risultato = base * potenza(base, esponente-1);
    return risultato;
}

long int sommaRiporto (long int n1, long int n2)
{
    int risultato=0, riporto=0, tmp=0,esponente=0;
    while (n1>0 || n2>0)
    {
        tmp = n1%10 + n2%10 + riporto;
        riporto = tmp/10;
        tmp = tmp%10;
        //printf("tmp è: %i\n", tmp);
        risultato += tmp*potenza(10,esponente);
        esponente ++;
        tmp=0;
        n1/=10;
        n2/=10;
    }
    return risultato;
}

int main()
{
    long int n1, n2;
    printf("inserisci i due numeri che vuoi sommare\n");
    scanf("%li", &n1);
    scanf("%li", &n2);
    printf("\nil risultato di %li + %li è %li\n", n1, n2,sommaRiporto(n1,n2));
    printf("mentre con la somma normale fa %li\n", n1+n2);
    return 0;
}