#include<stdio.h>

int main(){

    int n, q, x, y, i, j, flag=0;
    scanf("%d", &n);
    int arr[n+1];
    for ( i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &q);
    while(q--){
        scanf("%d %d", &x, &y);
        flag = 0;
        for ( i = x+1; i <= y; i++)
        {

            if(arr[i] == 0){
                flag = 1;
                break;
            }
        }

        if(flag){
            printf("Odd\n");
        }
        else{
            if(arr[x]%2 == 1){
                printf("Odd\n");
            }
            else{
                printf("Even\n");
            }
        }
    }
    
}