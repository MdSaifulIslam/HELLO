#include<stdio.h>

int main(void){
    int n=5;
    int a [n], i=0, temp;

    for(i=0; i<n; i++){
        a[i]= i+1;
    }
    
    for(i=0; i<n; i++){
        temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }

    for(i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}