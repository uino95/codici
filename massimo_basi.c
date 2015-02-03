#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int* trasforma_in_array(char *stringa, int *lungh, int *array)
{
    int i, j=0, l=strlen(stringa), c=0;
    
    for (i=0; i<l+1; i++)
    {
        if (stringa[i] != ' ' && stringa[i] != '\0')
            c++;
        
        if ((stringa[i] == ' ' || stringa[i] == '\0') && (stringa[i-1] == ' ' || i == 0));
        
        else
        {
            if (stringa[i] == ' ' || stringa[i] == '\0')
            {
                array[j] = inserisci(stringa, c, i-1);
                c = 0;
                //printf("%d\t", array[j]);
                j++;
                *lungh+=1;
            }
        }
    }
    return array;
}

int converti(int base, int numero)
{
    int risultato=0, c=0;
    while(numero!=0){
        risultato += (numero%10) * potenza(base,c);
        c++;
        numero/=10;
    }
    printf("risultato parziale è %d\n", risultato);
    return risultato;
}

int eval(char *expr) {
    int *array=malloc(sizeof(int));
    int i, l=0, tmp=0, numero=0;
    trasforma_in_array(expr, &l, array);
    printf("\n");
    for(i=0; i<l-1; i+=2)
    {
        numero=converti(array[i],array[i+1]);
        if(numero>tmp)
            tmp = numero;
    }
    return tmp;
}

int main()
{
    printf ("il numero maggiore è %d\n", eval("2 1 4 3 8 3"));
}