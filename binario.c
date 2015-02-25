//
//  main.c
//  prende in ingresso due sequenze da tot bit e mi restituisce la somma delle due sequenze

#include <stdio.h>//questa libreria mi serve per usare funzioni come la printf
#include <stdlib.h>
#define LEN 8

void stampa(int * vettore)//non posso utilizzare la printf perchè è un puntatore
{
    int i;
    for (i=0; i<LEN; i++)
        printf("%d", vettore[i]);
    printf("\n");
}


int * decimale_binario (int numero) //prende in ingresso un numero intero e mi restirtuirà un numero binario, che posso memorizzare come un numero intero ancora (però non mi piace perchè non avrei accesso agli elementi del numero binario) allora creo una sequenza di 0 e 1 interi, per questo utilizzo un puntatore in uscita
{
    int i,*vettore,n_loop=numero; //con l'int davanti ho dichiarato una variabile di 8 elementi, adesso posso accedere a tutti gli elementi
    //vettore[0], vettore[1], vettore[2] //così sto accedendo al primo, al secondo, al terzo elemento.
    //*(vettore), *(vettore+1) //oppure posso acccedere anche in questa maniera al primo, al secondo elemento
    vettore=malloc(LEN*sizeof(int)); //malloc : memory allocation, sizeof: la lunghezza di.
    
    for (i = LEN-1; i>=0; i--) //scorro l'array dal primo fino alla fine e trasformo il decimale in binario.
    {
        //if (numero % 2 == 0)
        //vettore[i] = 0;
        //else
        //vettore[i] = 1
        vettore[i] = n_loop % 2;//queste due scritture (questa e quella sopra) sono equivalenti.
        n_loop = n_loop/2;
    }
    return vettore;
    
}

int main() //questa è la funzione main da dove inizio, quindi dichiaro il numero che voglio convertire da decimale a binario e richiamo la funzione che mi fa ciò
{
    int numero=5, *binario;
    binario = decimale_binario(numero);
    printf ("conversione\nDECIMALE: %d\nBINARIO: ",numero);
    stampa(binario);
    return 0;
}
