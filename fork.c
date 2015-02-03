#include <stdio.h>
#include <unistd.h>

int main()
{
    int a;
    printf("ciao!! sono un processo!\n");
    
    a = fork();
    if (a==0)
        
        printf("hello\n");
    else
        printf("world\n");
    //printf("il valore ritornato da fork è %i\n", a);
    
}