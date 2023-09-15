#include <stdio.h>
// Sorting P/W array in decreasing order and sorting profit and weight array corresponding to it
void sort(float *N, float *P, float *W, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int temp = i, k = i;
        float swap;
        int m;
        for (int j = i; j < n - 1; j++)
        {
            if (N[k] < N[j + 1])
            {
                k = j + 1;
            }
        }
        swap = N[i];
        N[i] = N[k];
        N[k] = swap;
        swap = P[i];
        P[i] = P[k];
        P[k] = swap;
        swap = W[i];
        W[i] = W[k];
        W[k] = swap;
    }
}
// Greedy function
void greedy(float *P, float *W, float *N, int n, float C)
{
    float profit = 0, weight = C, totalWeight = 0;
    for (int i = 0; i < n; i++)
    {
        if (weight == 0)
            break;

        else if (W[i] <= weight)
        {
            weight -= W[i];
            profit += P[i];
            totalWeight += W[i];
            printf("1 Added weight %f and profit %f : \n", W[i], P[i]);
            printf("\n=======================================================\n");
        }
        else
        {
            profit += N[i] * weight;
            totalWeight += weight;
            weight = 0;
            printf("2 Added weight %f and profit %f : \n", W[i], P[i]);
            printf("\n=======================================================\n");
        }
    }
    printf("Total profit = %f\n", profit);
    printf("Total weight = %f\n", totalWeight);
}

int main()
{
    float C;
    int n;
    printf("Enter container weight : "); // Entering size of container
    scanf("%f", &C);
    printf("Enter number of objects you have : ");
    scanf("%d", &n);
    float P[n], W[n], N[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Profit with object %d : ", i + 1);
        scanf("%f", &P[i]);
    }
    printf("\n=======================================================\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter Weight of object %d : ", i + 1);
        scanf("%f", &W[i]);
    }
    printf("\n=======================================================\n");
    for (int i = 0; i < n; i++)
    {
        N[i] = P[i] / W[i];
    }
    printf("\n=============================================================================================================================\n");
    sort(N, P, W, n); // Calling sort() function to sort my arrays
    printf("Profit/Weight in descending order..\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f\t", N[i]);
    }
    printf("\n=============================================================================================================================\n");
    printf("Profit corresponding to Profit per unit Weight in descending order..\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f\t", P[i]);
    }
    printf("\n=============================================================================================================================\n");
    printf("Weight corresponding to Profit per unit Weight in descending order..\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f\t", W[i]);
    }
    printf("\n=============================================================================================================================\n");
    greedy(P, W, N, n, C);
    return 0;
}