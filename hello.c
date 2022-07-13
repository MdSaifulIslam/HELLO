#include<stdio.h>

//this is the coding test

int main()
{
    static int a = 5;

    if(--a){
        main();
        printf("%d ", a);
    }
}
