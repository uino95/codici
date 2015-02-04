#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define DIM 4

int riga_corretta(int m[DIM][DIM], int riga)//controlla la riga che gli viene data in ingresso: se almeno un numero si ripete ritorna 0 se no 1 
{
    int i,j;
    for (i=0; i<DIM-1; i++){
        for (j=i+1; j<DIM; j++){
            if( m[riga][i] == m[riga][j] && m[riga][i] > 0 )
                return 0;
        }
    }
    return 1;
}

int colonna_corretta(int m[DIM][DIM], int colonna) //controlla la colonna che gli viene data in ingresso: se almeno un numero si ripete ritorna 0 se no 1 
{
    int i,j;
    for (i=0; i<DIM-1; i++){
        for (j=i+1; j<DIM; j++){
            if ( m[i][colonna] == m[j][colonna] && m[i][colonna] > 0 )
                return 0;
        }
    }
    return 1;
}

int controlla_array (int m[DIM][DIM], int riga, int colonna)//trasfroma il quadro in un array e poi se almeno un numero si ripete ritorna 0 se no 1 
{
    int i,j,k=0;
    int array[DIM]={0};
    
    //printf ("il quadro è:\n");
    for (i=riga; i< riga + sqrt(DIM); i++){
        for (j=colonna; j< colonna + sqrt(DIM); j++){
            array[k] = m[i][j];
            //printf("%d\t", array[k]);
            k++;
        }
    }
    //printf("\n");
    for (i=0; i<DIM-1; i++){
        for (j=i+1; j<DIM; j++){
            if( array[i] == array[j] && array[i] > 0 )
                return 0;
        }
    }
    return 1;
}
   
int quadrotto_corretto(int m[DIM][DIM]) //seleziona il primo elemento di ogni quadro e poi richiama la funzione definita sopra, che se mi da 0 allora la funzione da 0 se no 1
{
    int qr,qc;
    
    for (qr=0; qr<DIM; qr+=sqrt(DIM)){
        for (qc=0; qc<DIM; qc+=sqrt(DIM)){
            if (controlla_array (m,qr,qc) == 0) 
                return 0;
        }
    }
    return 1;
}

int corretta(int m[DIM][DIM] )//seleziona ogni riga e colonna e richiama le funzioni per il controllo delle righe e delle colonne, mentre per i quadri richiama solamente la funzione definita sopra. In ogni caso se almeno una delle tre funzioni chiamate da 0 torna 0 altrimenti 1
{
    int i;
    for (i=0; i<DIM; i++)
    {
        if (riga_corretta(m,i)==0)
            return 0;
        if (colonna_corretta(m,i)==0)
            return 0;
    }
    if (quadrotto_corretto(m)==0)
        return 0;

    return 1;
}

int completa(int m[DIM][DIM])//0 il sudoku non è ancora completo, 1 il sudoku è completo
{
    int i,j;
    for (i=0; i<DIM; i++){
        for (j=0; j<DIM; j++){
            if (m[i][j]==0){
                return 0;
            }   
        }
    }
    return 1;
}

int risolvi(int m[DIM][DIM])
{
    int i,j,v;
    if (corretta(m)==0)
        return 0;
    for (i=0; i<DIM; i++){
        for (j=0; j<DIM; j++){
            if (m[i][j]==0){
                for (v=1; v<=DIM; v++){
                    m[i][j] = v;
                    if (risolvi(m))//provo a risolverlo mettendo in una casella vuota ogni valore possibile e ricontrollo ogni volta
                        return 1;
                }
                m[i][j] = 0;//se non va bene nessun valore devo cancellare la casella e dire che il sudoku non è risolvibile
                return 0;
            }
        }
    }
    return 1;
}

void stampa(int m[DIM][DIM])//mi stampa il sudoku
{
    int i,j,c=0,c1=0;
    printf("lo schema seguente:\n\n");
    printf (" ");
    for (c=0; c<DIM; c++){
        printf ("%4d", c);
    }
    printf ("\n");
    for (i=0; i<DIM; i++){
        printf ("%d",c1);
        printf (" ");
        for (j=0; j<DIM; j++){
            printf ("|%2d",m[i][j]);
            printf(" ");
        }
        c1++;
        printf("|\n");      
    }
    printf("\n");  
}

int* inizializza_sudoku(int m[DIM][DIM], int valore)//mi inizializza un sudoku con un valore a piacimento (0 o valore casuale)
{
    int i,j;
    for (i=0; i<DIM; i++){
        for (j=0; j<DIM; j++){
            m[i][j] = valore;
        }
    }
    return *m;
}

int* inizializza_sudoku_random (int m[DIM][DIM],int valore)
{
    int i,j;
    srand (time (NULL));
    for (i=0; i<DIM; i++){
        for (j=0; j<DIM; j++){
            m[i][j] = valore + rand()%DIM;
        }
    }
    return *m;
}

int* inizializza_sudoku_tu_random(int m[DIM][DIM], int caselle)
{
    int c,riga,colonna;
    srand(time(NULL));
    for(c=1; c<=caselle; c++){
        riga=rand()%DIM;
        colonna=rand()%DIM;
        m[riga][colonna] = 1+rand()%DIM;
    }
    return *m;
}

int* gioca_tu(int m[DIM][DIM])
{
    int c,riga,colonna,numero=0;
    
    while (completa(m)==0){
        stampa(m); //mi stampa lo stato del sudoku con le coordinate di fianco
        printf ("seleziona le coordinate di una casella (in questo modo: 0,1)\n");
        scanf ("%d,%d", &riga,&colonna);
        printf ("seleziona il numero che vuoi inserire (ricorda deve essere tra 1 e %d compresi), se vuoi cancellare una casella inserisci un numero maggiore di %d\n", DIM, DIM);
        scanf ("%d", &numero);
        if (m[riga][colonna]==0)//se non è occupata mettici il numero che hai selezionato
            m[riga][colonna] = numero;
        else 
        {//se la casella è gia occupata me lo dice e non cambia niente
            printf("casella gia occupata: ");
        }
        if (numero > DIM)//se vuoi cancellare una casella messa in precendenza
            m[riga][colonna]=0;
        if (corretta(m)==0){//ogni volta controlla che la mossa sia giusta, nel caso sia sbagliata me lo dice e mi cancella la casella che ho occupato
            printf ("mossa sbagliata, cambia numero ");
            m[riga][colonna] = 0;
        }
        if (numero==-1)//per uscire dal gioco
            break;
    }
    return *m;
}

int* crea_sudoku(int m[DIM][DIM], int difficoltà)
{
    int casellef=(DIM*DIM)/2,casellem=DIM+(((DIM*DIM)/2)-DIM)/2, caselled=DIM;

    if (difficoltà==1) {
        inizializza_sudoku_tu_random(m,casellef);//caselle piene sono tante quante quelle vuote
        return *m;
    }
    if (difficoltà==2) {
        inizializza_sudoku_tu_random(m,casellem);//una metà via tra facile e difficile
        return *m;
    }
    if (difficoltà==3) {
        inizializza_sudoku_tu_random(m,caselled);//caselle piene sono tante quante DIM
        return *m;
    }
    return *m;
}

int main ()//sceglie tra tre modalità 1= crea dei sudoku completi casuali per effettuare dei test, 2 = mi risolve un sudoku vuoto 3 = mi risolve un sudoku inizializzato random in base alla difficoltà da me  scelta.
{
    int modalità,difficoltà=0,c=0;
    int m[DIM][DIM];
    
    printf ("Seleziona la modalità di gioco:\n1=random\n2=riempi\n3=gioca il pc\n4=gioca tu\n");
    scanf ("%d", &modalità);
    
    if (modalità == 1)
    {
        inizializza_sudoku_random (m,1);//così me lo fa completo
        stampa(m);

        printf("1 se il sudoku è corretto, 0 se c'è un errore\n");
        printf("m: %i\n", corretta(m));
    }
    
    if (modalità==2)
    {    
        inizializza_sudoku(m,0);
        stampa(m);
        risolvi(m);
        
        if (risolvi(m)==0)
            printf("il sudoku è irrisolvibile\n");
        else{
            printf("la soluzione è la seguente\n");
            stampa(m);
        }
    }
    
    if (modalità == 3)
    {
        inizializza_sudoku(m,0);
        
        printf("seleziona difficoltà:\n1=facile\n2=medio\n3=difficile\n");
        scanf("%d", &difficoltà);
        
        crea_sudoku(m,difficoltà);
        if (corretta(m)==1){
            printf ("il sudoku da risolvere è ");
            stampa(m);
        }
        while (risolvi(m)==0) {
            inizializza_sudoku(m,0);
            crea_sudoku(m,difficoltà);
            if (corretta(m)==1){
                printf ("il sudoku da risolvere è ");
                stampa(m);
            }
        }
        printf ("la soluzione è ");
        stampa(m);    
    }
    if (modalità == 4)
    {
        inizializza_sudoku(m,0);
        
        printf("seleziona difficoltà:\n1=facile\n2=medio\n3=difficile\n");
        scanf("%d", &difficoltà);
        
        crea_sudoku(m,difficoltà);
        while (corretta(m)==0){
            crea_sudoku(m,difficoltà);
            if (c>10000000){
                printf("ops non ho trovato un sudoku risolvibile, seleziona una modalità più difficile\n");
                return 0;
            }
            c++;
        }
        printf("risolvi ");
        gioca_tu(m);
        printf("sudoku finito ");
        stampa(m);    
    }
}

    

