#include <stdio.h>

int main()
{

    long long arr[100];
    arr[0] = 0;
    arr[1] = 1;
    int i = 51, t, k, found=0, j;
    long long num = 0;
    for (j = 2; j <= i; j++)
    {
        arr[j] = arr[j - 1] + arr[j - 2];
    }

    scanf("%d", &t);
    while (t--)
    {
        found = 0;
        scanf("%lld", &num);
        k = 51;
        for (i = 0; i < k; i++)
        {
            if (arr[i] == num)
            {
                found = 1;
                break;
            }
        }
        if (found == 1)
        {
            printf("IsFibo\n");
        }
        else
        {
            printf("IsNotFibo\n");
        }
    }
}