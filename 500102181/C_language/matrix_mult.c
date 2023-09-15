#include <stdio.h>
int main()
{
    int n, m, p, q, i, j, k; // n,m are rows and columns of matrix 1 and p,q are rows and columns of matrix 2 & i,j,k are looping contraints
    printf("Enter number of rows and coloumn in matrix 1 : ");
    scanf("%d %d", &n, &m);
    printf("Enter number of rows and coloumn in matrix 2 : ");
    scanf("%d %d", &p, &q);
    int a[n][m], b[p][q], mul[n][q]; // Created matrix 1 and 2 and and multiplication matrix with n rows & q columns
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

        for (i = 0; i < n; i++) // for rows
        {
            for (j = 0; j < q; j++) // for columns
            {
                mul[i][j] = 0; // reseting values
                for (k = 0; k < m; k++) // for multiplication
                {
                    mul[i][j] = mul[i][j] + a[i][k] * b[k][j];
                }
            }
        }

        printf("Multiplied matrix is:\n"); // Printing multiplied matrix
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
