//
//  main.c
//  tris
//
//  Created by Matteo Sinico on 08/01/15.
//  Copyright (c) 2015 Matteo Sinico. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define SIZE 3

int riga_corretta(int m[SIZE][SIZE], int riga)//controlla la riga che gli viene data in ingresso: se almeno un numero si ripete ritorna 0 se no 1
{
    int i,j;
    for (i=0; i<SIZE-1; i++){
        for (j=i+1; j<SIZE; j++){
            if (m[riga][i] == 0)
                return 0;
            if( m[riga][i] != m[riga][j])
                return 0;
        }
    }
    return m[riga][i];
}

int colonna_corretta(int m[SIZE][SIZE], int colonna) //controlla la colonna che gli viene data in ingresso: se almeno un numero si ripete ritorna 0 se no 1
{
    int i,j;
    for (i=0; i<SIZE-1; i++){
        for (j=i+1; j<SIZE; j++){
            if (m[i][colonna] == 0)
                return 0;
            if ( m[i][colonna] != m[j][colonna])
                return 0;
        }
    }
    return m[i][colonna];
}

int uguale (int array[SIZE])
{
    int i;
    for (i=0; i<SIZE; i++) {
        if (array[i] == 0)
            return 0;
        if (array[i] != array[i+1])
            return 0;
    }
    return 1;
}

void stampaArray(int array[SIZE])
{
    int i=0;
    for (i=0; i<SIZE; i++) {
        printf("%2d", array[i]);
    }
    printf("\n");
}

int diagonale_corretta(int partita[SIZE][SIZE])//controlla le diagonali: se almeno un numero si ripete ritorna 0 se no 1
{
    int i=0,j,k=0;
    int diagonale1[SIZE] = {0};
    int diagonale2[SIZE] = {0};
    
    for (j=0; j<SIZE; j++) {
        diagonale1[k] = partita[i][j];
        i++;
        k++;
    }
    //stampaArray(diagonale1);
    
    if (uguale(diagonale1)==1)
        return diagonale1[0];//così mi ritorna il numero del giocatore in teoria
    
    i=0;
    for (j=2; j>=0; j--) {
        diagonale2[k] = partita[i][j];
        i++;
        k++;
    }
    //stampaArray(diagonale2);
    if (uguale(diagonale2)==1)
        return diagonale2[0];
    
    return 0;
}

int arbitro(int partita[SIZE][SIZE],int giocatore)
{
    int i;
    for (i=0; i<SIZE; i++)
    {
        //printf("riga n° %d dice %d\n", i, riga_corretta(partita, i));
        if (riga_corretta(partita,i)==giocatore)
            return giocatore;
        if (colonna_corretta(partita,i)==giocatore)
            return giocatore;
    }
    if (diagonale_corretta(partita)==giocatore)
        return giocatore;

    return 0;
}

void stampa(int partita[SIZE][SIZE])//mi stampa la partita
{
    int i,j,c=0,c1=0;
    printf("Stato della partita:\n\n");
    printf (" ");
    for (c=0; c<SIZE; c++){
        printf ("%4d", c);
    }
    printf ("\n");
    for (i=0; i<SIZE; i++){
        printf ("%d",c1);
        printf (" ");
        for (j=0; j<SIZE; j++){
            printf ("|%2d",partita[i][j]);
            printf(" ");
        }
        c1++;
        printf("|\n");
    }
    printf("\n");
}

int* inizializza_tris(int partita[SIZE][SIZE], int valore)//mi inizializza un sudoku con un valore a piacimento (0 o valore casuale)
{
    int i,j;
    for (i=0; i<SIZE; i++){
        for (j=0; j<SIZE; j++){
            partita[i][j] = valore;
        }
    }
    return *partita;
}


int controlloZeri(int partita[SIZE][SIZE]){//controlla se ci sono degli zeri cioè se la partita è finita o meno: se è incompleta ritorna 1 se no 0
    int i,j;
    
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++){
            if (partita[i][j] == 0)
                return 1; //TRUE
        }
    }
    return 0; //FALSE
}


int multigiocatore (void)
{
    int mossa=1, riga, colonna;
    int partita[SIZE][SIZE];
    
    printf("Giocatore 1 = 1\nGiocatore 2 = 2\n");
    
    inizializza_tris(partita, 0);
    
    printf("Quando è il tuo turno inserisci le coordinate per selezionare la casella (ad esempio 0,1)\n");
    
    stampa(partita);

    while (controlloZeri(partita)==1) {
        
        
        if (mossa % 2 != 0){//se è dispari tocca al giocatore 1
            printf("È il turno del giocatore 1, seleziona una casella\n\n");
            scanf("%d,%d", &riga, &colonna);
            if (partita[riga][colonna] != 0){
                printf("casella gia occupata, selezionare un'altra casella\n");
            }
            else{
                partita[riga][colonna] = 1;
                stampa(partita);
                mossa++;
            }
            
        }
        
        else//se è pari tocca al giocatore 2
        {
            printf("È il turno del giocatore 2,seleziona una casella\n\n");
            scanf("%d,%d", &riga, &colonna);
            if (partita[riga][colonna] != 0){
                printf("casella gia occupata, selezionare un'altra casella\n");
            }
            else{
            partita[riga][colonna] = 2;
            stampa(partita);
            mossa++;}
        }
        
        //printf("arbitro dice: %d\n", arbitro(partita,1));
        //printf("arbitro dice: %d\n", arbitro(partita,2));
        
        if (arbitro(partita, 1)==1){
            //printf("sono qui all'1\n");
            return 1;
        }

        if (arbitro(partita,2)==2){
            //printf ("sono qui al 2\n");
            return 2;
        }
    }
    return 0;
}

int main (void)
{
    int modo;
    
    printf("Selezionare una modalità di gioco:\n1 = multigiocatore\n2 = utente vs computer\n");
    scanf("%d", &modo);
    if (modo == 1){
        printf("Partita finita: vince il giocatore %d\n", multigiocatore());
    }
    else
        return 0;//"Ancora da programmare";
}