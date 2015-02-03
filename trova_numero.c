#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *arrayVal, *arrayPos;

void crea1()
{
    arrayVal = malloc(sizeof(int));
}
void crea2()
{
    arrayPos = 10000+(malloc(sizeof(int)));
}

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
        
        if (stringa[i] == ' ' || stringa[i] == '\0')
        {
            array[j] = inserisci(stringa, c, i-1);
            c = 0;
            printf("%d\t", array[j]);
            j++;  
            *lungh+=1;
        }
    }
    return array;
}

void stampa(int *array, int lungh)
{
    int i;
    for (i=0; i<lungh; i++) {
        printf("%d ", array[i]);
    }
}

int eval(char * val, char * pos) 
{
    int l1=0;
    int l2=0;
    int j;
    crea1();
    crea2();
    arrayVal = trasforma_in_array(val, &l1, arrayVal);
    printf("\n");
    arrayPos = trasforma_in_array(pos, &l2, arrayPos);
    printf("\n");
    int tmp=0, i;
    
    for (i=0; i < l2; i++)
    {
        if(arrayPos[i] >= l1 || arrayPos[i] < 0);
            //printf("tmp è: %d\n", tmp);
        
        else
        {
            if (tmp == 0){
                tmp = arrayVal[arrayPos[i]];
                //printf("tmp è: %d\n", tmp);
                //printf("arrayVal[%d]] è: %d\n", arrayPos[i], arrayVal[arrayPos[i]] );
            }
            
            else
            {
                if (arrayVal[arrayPos[i]] < tmp)
                {
                    tmp = arrayVal[arrayPos[i]];
                } //printf("tmp è: %d\n", tmp); printf("arrayVal[%d]] è: %d\n", arrayPos[i], arrayVal[arrayPos[i]] );}
            }   
        }
    }
    //stampa(arrayVal, l1);
    //printf("tmp è: %d\n", tmp);
    return tmp;
}

int main()
{
    printf("il numero è: %d\n", eval("7220 71 42 78 78 63 25 272 53", "2 4 1 6 0"));
}
    
