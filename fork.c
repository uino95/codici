#include <stdio.h>
#include <unistd.h>

int main()
{
    int a;
    printf("ciao!! sono un processo!\n");
    
    a = fork();//il progaramma si clona
    if (a==0)//seleziono solo il processo che ha come valore 0 e non l'altro che invece ritorna un valore diverso da 0
        
        printf("hello\n");
    else
        printf("world\n");
    //printf("il valore ritornato da fork è %i\n", a);
    
}