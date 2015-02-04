#include <stdio.h>

typedef struct user{
    char *ID;
    int punteggio;
    int numero;
} utente;

void inserisci_ID(utente *u, char *ID){
    int i;
    for (i=0; ID[i] != '\0'; i++){
        u->ID[i]=ID[i];
    }
    
}

void inserisci_punteggio(utente *u, int punteggio){
    u->punteggio=punteggio;
}

void inserisci_numero(utente *u, int numero){
    
    u->numero = numero;
}

void inserisci_numero_hachero(int *n, int numero){
    *(n-1)=30;     //così modifico il punteggio, che sta prima nella memoria, senza dover usare la funzione inserisci punteggio (ho hackerato il sistema)
    
    *n=numero;
}

void stampa(utente u){
    printf("ID:         %s\nPunteggio:  %d\nNumero:     %d\n", u.ID, u.punteggio, u.numero);
}
int main(){
    utente u1;
    int punteggio=1, numero=7;
    char *ID;
    ID = "Matteo Sinico";
    //printf("ID 1 = %c\n", ID[1]);
    
    inserisci_ID(&u1, ID);
    inserisci_punteggio(&u1, punteggio);
    inserisci_numero (&u1, numero);
    //inserisci_numero_hachero(&(u1.numero), numero);   //così posso accedere alla memoria e modificare i dati che stanno prima in memoria
    stampa(u1);
}