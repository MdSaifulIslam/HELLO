#include <stdio.h>

int sum = 0;

int rev(int x)
{
    if (x >= 10)
    {
        rev(x%10);
         rev(x / 10);
    }
    
    sum = sum*10 + x;
    return sum;
}

int main(void)
{
    printf("%d", rev(100009));
    return 0;
}