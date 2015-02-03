#include <stdio.h>
#define DIM 10
int main()
{
    int i;
    int array[DIM]={0};
    
    printf ("inserisci dei numeri:\n");
    for (i=0; i<DIM;i++){
        scanf ("%d", &array[i]); 
    }
    
    printf ("l'array è questo: \n" );
    for (i=0; i<DIM;i++){
        printf("%2d\n", array[i]);
    }
    return 0;   
}
