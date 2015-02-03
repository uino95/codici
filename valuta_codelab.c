#include <stdio.h>
#include <stdlib.h>

int eval(char *espressione)
{
    int risultato = 0, numero = 0, cifre = 0, esponente = 0, contatore = 0;
    while(*espressione != '\0'){
        if ((*espressione) != '+' || (*espressione) != '-' ){
            cifre++;
            contatore++;
        }
        espressione ++;
       
        if (contatore == cifre && ((*espressione) == '+' || (*espressione) == '-' || (*espressione) == '\0'))//mi somma solamente il primo numero a 0
        {
            risultato = addizione(espressione, cifre, esponente, numero, risultato);
            cifre=0;
            espressione ++;
        }
        
        if ((*(espressione-(cifre+1)) == '+') && ((*espressione) == '+' || (*espressione) == '-' || (*espressione) == '\0'))
        {
            risultato = addizione(espressione, cifre, esponente, numero, risultato);
            cifre=0;
            espressione ++;
        }
        if ((*(espressione-(cifre+1)) == '-') && ((*espressione) == '+' || (*espressione) == '-' || (*espressione) == '*' || (*espressione) == '/' 
            || (*espressione) == '\0'))
        {
            risultato = sottrazione(espressione, cifre, esponente, numero, risultato);
            cifre=0;
            espressione ++;  
            
        }
    }
    return risultato;
}

int potenza (int base,int esponente)
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