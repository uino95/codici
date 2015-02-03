#include <stdio.h>

char maiuscolo (char c)
{
    if (c<='z' && c>='a') {
        return c-'a'+'A';
    }
    return c;
    
}

char trasforma(char c, char precedente)
{
    if (precedente == ' ') {
        return maiuscolo(c);
    }
    return c;
}

int main (int argc, char **argv)
{
    FILE* in;
    FILE* out;
    char c,precedente=' ';
    
    in = fopen(argv[1],"r");
    out = fopen(argv[2],"w");
    
    fread(&c, sizeof(char), 1, in);
    
    while (!feof(in)){
        
        c = trasforma(c,precedente);
        precedente = c;
        fwrite (&c, sizeof(char), 1, out);
        fread (&c, sizeof(char), 1, in);
    }
    
    fclose(in);
    fclose(out);
}