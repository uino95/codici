#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
        if (!isdigit(stringa[i])){
            totale+= stringa[i]=='+' ? numero : numero*(-1);
            numero=0;
            esponente=0;}
        else{
            numero += (stringa[i]-'0') * (potenza(10,esponente));
            esponente++;}
        cifre--;
        i--;
    }
    totale+=numero;
    return totale;
}

int converti(int base, int numero)
{
    int risultato=0, c=0;
    while(numero!=0){
        risultato += (numero%10) * potenza(base,c);
        c++;
        numero/=10;
    }
    return risultato;
}

int trasforma_in_lista(char *stringa)//trasformo la stringa in una lista
{
    int i, l=strlen(stringa), c=0, numeroC=0, base=0, numero=0, numero1=0, risultato=0, temp = 0;
    
    for (i=0; i < l+1; i++)
    {
        if (isdigit(stringa[i]) && stringa[i] != '\0')
        {
            c++;
        }
    
        else
        {

            if (!isdigit(stringa[i]) || stringa[i] == '\0')
            {
                if (stringa[i] == '#')
                {
                    base = inserisci(stringa, c , i-1);
                }
                else
                {
                    if (stringa[i-(c+1)]== '#')
                    {
                        numero1 = inserisci(stringa, c , i-1);
                        numeroC = converti(base, numero1);
                    }
                    else
                    {
                        numero = inserisci(stringa, c , i-1);
                    }
                    
                    if (risultato == 0)
                    {
                        risultato+= numero+numeroC;
                        numero=0;
                        numeroC=0;
                    }
                    if (temp == 1)
                    {
                        risultato+= numero+numeroC;
                        numero=0;
                        numeroC=0;
                    }
                    
                    if (temp == -1)
                    {
                        risultato-= numero+numeroC;
                        numero=0;
                        numeroC=0;
                    
                    }
                    
                    if (stringa[i] == '+')
                    {
                        temp=1;
                    }
                    
                    if (stringa[i] == '-')
                    {
                        temp=-1;
                    }
                    printf("risultato è: %i\n", risultato);
                }
            }
            c=0;
        }
        
    }
    
    return risultato;
}

int main()
{
    printf ("il risultato è %d\n", trasforma_in_lista("10#34-5-5#14+3#20-10#45"));
}