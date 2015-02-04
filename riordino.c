#include <stdio.h>
#define SIZE 10

int main (void)//mi ordina un array in modo crescente o decrescente
{
    long int array[SIZE] = {29,45,21,34,67,31,35,6,41,35};
    int j,i,temp=0,modo=0;
    printf ("I valori prima del riordino sono questi:\n");
    for (i=0;i<SIZE;i++){
        printf("%3ld", array[i]);}
    printf ("\nIn che modo vuoi riordinare gli elementi dell'array?\ncrescente=1\ndecrescente=2\n");
    scanf ("%d", &modo);
    if (modo != 1 && modo != 2) {
        printf ("Errore: Valore non valido\n");
    }
    if (modo == 1){
        for (j=1; j<SIZE; j++){
            for (i=0; i<SIZE-1; i++){
                if (array[i] > array[i+1]){//bubble sort
                    temp = array[i];
                    array[i] = array[i+1];
                    array[i+1] = temp;
                }
            }
        }
    }
    if (modo==2){
        for (j=1; j<SIZE; j++){
            for (i=0; i<SIZE-1; i++){
                if (array[i] < array[i+1]){//bubble sort
                    temp = array[i];
                    array[i] = array[i+1];
                    array[i+1] = temp;
                }
            }
        }
    }
    
    printf ("I valori dopo del riordino sono questi:\n");
    for (i=0;i<SIZE;i++){
        printf("%3ld", array[i]);}
        printf("\n");
}

