#include <stdio.h>

int main( void )
{
    float array[20];
    
    printf ("il numero di byte nell'array è: %lu\nIl numero di byte occupati da un float è: %lu\n", sizeof(array), sizeof(*array));
    return 0;
}