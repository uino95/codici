#include <string.h>
#include <stdio.h>

int eval(char *andrea) {
    int tmp=0;
    int potenza=1;
    int i;
    int l=strlen(andrea);
    int totale=0;
    for (i=l-1; i>=0;i--)
    {
        if (andrea[i] == '+')
        {
            totale+=tmp;
            potenza=1;
            tmp=0;
        }
        else 
        {
            if (andrea[i] == '-')
            {
                totale-=tmp;
                potenza=1;
                tmp=0;
            }
            else
            {
                tmp += potenza*(andrea[i]-'0');
                potenza*= 10;
                printf ("andrea dice che tmp é: %d\n", tmp);
            }
        }  
    }
    totale += tmp;
    return totale;
}

int main()
{
    printf("andrea dice che 123+124 fa: %d\n", eval("123+124"));
    
}