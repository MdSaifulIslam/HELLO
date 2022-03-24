#include <stdio.h>

int main()
{
    int n, k, i, m, t;
    long long res = 1;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &m, &n);
        m--;

        int i, j;

        int upperside[m];
        int lowerside[m * m];

        for (i = 1; i <= m; i++)
        {
            upperside[i - 1] = i + n;
        }

        j = 0;
        int k = 0, number;
        lowerside[k] = 1;
        if (m > 1)
        {
            lowerside[k++] = 2;
        }
        for (i = 2; i <= m; i++)
        {
            number = i;
            for (j = 2; j < number; j++)
            {
                while (number % j == 0)
                {
                    lowerside[k++] = j;
                    number /= j;
                }
            }
            if (number > 2)
            {
                lowerside[k++] = number;
            }
        }

        for (i = 0; i < k; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (upperside[j] % lowerside[i] == 0)
                {
                    upperside[j] = upperside[j] / lowerside[i];
                    break;
                }
            }
        }

        long long res = 1;

        for (i = 0; i < m; i++)
        {
            res *= upperside[i];

            if (res > 1000000000)
            {
                res %= 1000000000;
            }
        }

        printf("%lld\n", res);
    }

    return 0;
}