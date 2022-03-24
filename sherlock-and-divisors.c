#include <stdio.h>
#include <math.h>

int main(void)
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int sqrt_n = (floor(sqrt(n)));
        int i, temp, count = 0;
        for (i = 1; i <= sqrt_n; i++)
        {
            if (n % i == 0)
            {
                temp = n / i;
                printf("::::%d : %d::::\n", i, temp);
                
                if (i % 2 == 0)
                {
                    count++;
                    printf("-%d ", i);
                }
                if (temp % 2 == 0)
                {
                    count++;
                    printf("-%d \n", temp);
                }
            }
        }

        printf("%d\n", count);
    }
}