#include <stdio.h>
int main()
{
    int n, m, p, q, i, j, k;
    printf("Enter number of rows and coloumn in matrix 1 : ");
    scanf("%d %d", &n, &m);
    printf("Enter number of rows and coloumn in matrix 2 : ");
    scanf("%d %d", &p, &q);
    int a[n][m], b[p][q], mul[n][q];
    if (m == p)
    {
        printf("Enter elements of first matrix:\n");
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                scanf("%d", &a[i][j]);

        printf("Enter elements of second matrix:\n");
        for (i = 0; i < p; i++)
            for (j = 0; j < q; j++)
                scanf("%d", &b[i][j]);

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < q; j++)
            {
                mul[i][j] = 0;
                for (k = 0; k < m; k++)
                {
                    mul[i][j] = mul[i][j] + a[i][k] * b[k][j];
                }
            }
        }

        printf("Multiplied matrix is:\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < q; j++)
            {
                printf("%d\t", mul[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("Matrix can't be multiplied");
    return 0;
}
