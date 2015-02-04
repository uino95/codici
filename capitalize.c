#include <stdio.h>

char maiuscolo (char c)//prende in ingresso un carattere e se minuscolo viene trasformato in maiuscolo
{
    if (c<='z' && c>='a') {
        return c-'a'+'A';
    }
    return c;
    
}

char trasforma(char c, char precedente)//se il carattere precedente è uno spazio allora chiama maiuscolo(c) se no non fa niente
{
    if (precedente == ' ') {
        return maiuscolo(c);
    }
    return c;
}

int main (int argc, char **argv)//argc numero di parametri che posso inserire, argv stringa che contiene i paramentri
{
    FILE* in;
    FILE* out;
    char c,precedente=' ';//imposto precedente subito come uno spazio così mi mette in maiuscolo anche la prima lettera

    in = fopen(argv[1],"r");//apro in lettura il file in ingresso e in scrittura il file in uscita
    out = fopen(argv[2],"w");
    
    fread(&c, sizeof(char), 1, in);//leggo un carattere dal file in entrata
    
    while (!feof(in)){//scorro fino alla fine del file
        
        c = trasforma(c,precedente);//guardo se devo capitalizzare
        precedente = c;//vado avanti di un carattere
        fwrite (&c, sizeof(char), 1, out);//scrivo nel file il carattere, sia se è stato trasformao oppure no
        fread (&c, sizeof(char), 1, in);//leggo il carattere successivo dal file
    }
    
    fclose(in);
    fclose(out);
}