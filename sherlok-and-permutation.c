#include <stdio.h>
#include <math.h>

int main(void)
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n = 17, m;
        scanf("%d%d", &n, &m);

        m--;

        if (m == 0)
        {
            printf("%d\n", n);
            return 0;
        }

        int upperside[m], lowerside[m], i, j;

        for (i = 1; i <= m; i++)
        {
            upperside[i - 1] = i + n;
            lowerside[i - 1] = i;
        }
        for (i = 0; i < m; i++)
        {
            printf("%d ", upperside[i]);
        }

        for (i = 1; i < m; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (upperside[j] % lowerside[i] == 0)
                {
                    upperside[j] = upperside[j] / lowerside[i];
                    lowerside[i]= 1;
                    break;
                }
            }
        }
        int count = 0;
        for (i = 0; i < m; i++)
        {
            count += lowerside[i];
        }
        
        if (count != m)
        {
            printf("-1\n");
            return 0;
        }

        long long res = 1;

        for (i = 0; i < m; i++)
        {
            res *= upperside[i];

            if (res > 1000000007)
                res %= 1000000007;
        }

        for (i = 0; i < m; i++)
        {
            printf("%d ", upperside[i]);
        }
        for (i = 0; i < m; i++)
        {
            printf("%d ", lowerside[i]);
        }

        printf("\n%lld\n", res);
    }
}