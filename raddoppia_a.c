#include <stdio.h>

char maiuscolo(char c){
    if(c<='z' && c>='a')
        return c-'a'+'A';
    return c;
}

char trasforma(char c, char precedente){
    if(precedente==' ')
        return maiuscolo(c);
    return c;
}

int main(int argc, char **argv){
    FILE* in;
    FILE* out;
    int i;
    int volte=0;
    char c, precedente=' ';

    printf("Quante volte vuoi raddoppiare la a?\n");
    scanf("%d",&volte);
    printf("Ok, la copio %d volte", volte);

    //for(i=0;i<argc;i++)
    //    printf("Parametro %d: %s\n", i, argv[i]);

    in=fopen(argv[1], "r");
    out=fopen(argv[2], "w");

    fread(&c, sizeof(char), 1, in);

    while(!feof(in)){
        
        c=trasforma(c,precedente);

        precedente=c;
        if(c=='a'||c=='A')
            for(i=0;i<volte-1;i++)
                fwrite(&c, sizeof(char), 1, out);
        fwrite(&c, sizeof(char), 1, out);
        fread(&c, sizeof(char), 1, in);
    }

    fclose(in);
    fclose(out);
}