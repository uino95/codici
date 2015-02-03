#include <stdio.h>

int getSize(float array[20]);

int main( void )
{
    float array[20];
    
    printf ("il numero di byte nell'array è: %lu\nIl numero di byte occupati da un float è: %d\n", sizeof(array), getSize(array));
    return 0;
}

int getSize(float array[20]){
    float array2[20];
    printf ("array2 byte: %d\n", sizeof( array2 ));
    printf ("array byte: %d\n", sizeof( array ));
    return sizeof (*array);
}