#include<stdio.h>

int main(void){
    int n=4;
    int i=0;
    int one=1;
    int zero=1;

    for ( i = 1; i < n; i++)
    {
        zero = zero + one;
        one =zero-one;
    }

    printf("%d\n",zero+one);
    
    return 0;
}