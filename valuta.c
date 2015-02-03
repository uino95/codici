#include <stdio.h>
#include <stdlib.h>

int potenza (int base,int esponente)//eleva la base all'esponente desiderato
{
    int risultato=0;
    
    if (esponente == 0)
        return 1;    
    
    risultato = base * potenza(base, esponente-1);
    return risultato;
}

int addizione(char *espressione, int cifre, int esponente, int numero, int risultato)
{
    espressione--; 
    while (cifre!=0){
        numero += (*espressione-48) * (potenza(10,esponente));
        cifre--;
        esponente++;
        espressione--;
    }
    risultato += numero; 
    return risultato;
}

int sottrazione (char *espressione, int cifre, int esponente, int numero, int risultato)
{
    espressione--; 
    while (cifre!=0){
        numero += (*espressione-48) * (potenza(10,esponente));
        cifre--;
        esponente++;
        espressione--;
    }
    risultato -= numero;
    return risultato;
}  

int moltiplicazione (char *espressione, int cifre, int esponente, int numero, int risultato)
{
    espressione--; 
    while (cifre!=0){
        numero += (*espressione-48) * (potenza(10,esponente));
        cifre--;
        esponente++;
        espressione--;
    }
    risultato *= numero;
    return risultato;
}  

int divisione (char *espressione, int cifre, int esponente, int numero, int risultato)
{
    espressione--; 
    while (cifre!=0){
        numero += (*espressione-48) * (potenza(10,esponente));
        cifre--;
        esponente++;
        espressione--;
    }
    risultato /= numero;
    return risultato;
}  
    
int eval(char *espressione)//valuta un espressione data sottoforma di stringa
{
    int risultato = 0, numero = 0, cifre = 0, esponente = 0, contatore = 0;
    while(*espressione != '\0'){
        if ((*espressione) != '+' || (*espressione) != '-' || (*espressione) != '*' || (*espressione) != '/'){
            cifre++;
            contatore++;
        }
        espressione ++;
       
        if (contatore == cifre && ((*espressione) == '+' || (*espressione) == '-' || (*espressione) == '*' || (*espressione) == '/'|| (*espressione) == '\0'))//mi somma solamente il primo numero a 0
        {
            //printf("espressione vale: %s\n", espressione);
            risultato = addizione(espressione, cifre, esponente, numero, risultato);
            cifre=0;
            espressione ++;
            //printf("espressione vale: %s\n", espressione);
        }
        
        if ((*(espressione-(cifre+1)) == '+') && ((*espressione) == '+' || (*espressione) == '-' || (*espressione) == '*' || (*espressione) == '/' 
            || (*espressione) == '\0'))//se quello che c'era prima del numero era un + questa mi fa l'addizione
        {
            risultato = addizione(espressione, cifre, esponente, numero, risultato);
            cifre=0;//tutte le volte devo reinizializzare le cifre a 0 ed impostare l'espressione avanti di uno per poter partire subito col numero dopo e non con l'operatore
            espressione ++;
        }
        if ((*(espressione-(cifre+1)) == '-') && ((*espressione) == '+' || (*espressione) == '-' || (*espressione) == '*' || (*espressione) == '/' 
            || (*espressione) == '\0'))//se no mi fa la sottrazione
        {
            risultato = sottrazione(espressione, cifre, esponente, numero, risultato);
            cifre=0;
            espressione ++;  
            //printf ("il risultato temporaneo è: %d\n", risultato);
        }
        if ((*(espressione-(cifre+1)) == '*') && ((*espressione) == '+' || (*espressione) == '-' || (*espressione) == '*' || (*espressione) == '/'
            || (*espressione) == '\0'))//se no mi fa la moltiplicazione
        {
            risultato = moltiplicazione(espressione, cifre, esponente, numero, risultato);
            cifre=0;
            espressione ++;   
        }
        if ((*(espressione-(cifre+1)) == '/') && ((*espressione) == '+' || (*espressione) == '-' || (*espressione) == '*' || (*espressione) == '/'
            || (*espressione) == '\0'))//se no mi fa la divisione
        {
            risultato = divisione(espressione, cifre, esponente, numero, risultato);
            cifre=0;
            espressione ++;   
        }
    }
    return risultato;
}

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

char* cerca_parentesi(char * espressione)

{
    char *stringa = malloc(sizeof(char));
    int i,inizio=0,fine=0;
    char *parziale;
    while ((*espressione)!='\0') {
        if ((*espressione)=='(')
        {
            for(i=0; (*espressione)!=')'; i++)//mi crea una nuova stringa con l'espressione che c'e tra parentesi
            {
                if (*(espressione+1) != ')'){
                    espressione++;
                    stringa[i] = *espressione;}
                else{
                    stringa[i] = *espressione;
                    espressione++;}
                fine++;
            }
            parziale = itoa(eval(stringa));

            for(i=0; parziale[i] != '\0' ;inizio++, i++){
                espressione[inizio] = parziale[i];
            }
            
        }
        inizio++;
        fine = inizio;
    }
    return espressione;
}

int scorri_espressione(char *espressione)
{
    //cerca_parentesi(espressione);per adesso non funziona
    //cerca_*_or_/
    return eval (espressione);
}

int main()
{
    char *espressione = malloc (sizeof(char));
    
    printf ("inserisci il testo dell'espressione che vuoi valutare: \n");
    scanf ("%s", espressione);
    printf("il risultato di: %s è: %d\n", espressione, scorri_espressione(espressione));
}


//prossima cosa da fare è fare una funzione (all'interno di eval, perchè così lo fa ogni volta che valuta una stringa) che mi scorra tutta la stringa e controlli se ci sono parentesi o moltiplicazioni e divisioni e agisca nel seguente modo: se trova una parentesi deve scorrere fino alla successiva parentesi e valutare solo quel pezzo di stringa e sostituire il risultato nella stringa al posto dell'epressione tra parentesi; mentre se trova delle moltiplicazioni o divisioni deve valutare prima il pezzo di stringa che prima e dopo * o / cioè se la stringa fosse 234+43*2+21 dovrebbe valutare per prima cosa 43*2 e poi ritornare il risultato nella stringa al posto del pezzo di stringa valutato. cosicchè alla fine scorrerò di nuovo la stringa e non trovando niente di strano valuterò l'intera stringa










