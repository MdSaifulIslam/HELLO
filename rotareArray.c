#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int gcd = 3, i, j, k, l, m, n = 12, temp;

    for (i = 0; i < gcd; i++)
    {
        temp = arr[i];
        j = i;

        while (1)
        {
            k = j + gcd;
            if (k >= n)
            {
                k = k - n;
            }
            if (k == i)
            {
                break;
            }
            arr[j] = arr[k];
            j = k;
        }

        arr[j] = temp;

        for (l = 0; l < n; l++)
            printf("%d ", arr[l]);
        printf("\n");
    }
}