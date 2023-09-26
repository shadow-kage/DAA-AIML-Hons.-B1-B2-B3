#include <stdio.h>

void sort(float *N, float *W, float *P, int n) //To sort elements in descending order according to profit/weight
{
    for (int i = 0; i < n - 1; i++)
    {
        int max = i; // Making first element of array as max for further comparisons
        float temp;
        for (int j = i + 1; j < n; j++)
        {
            if (N[j] > N[max]) // if another element is greater than our current maximum element
            {
                max = j; // Updating maximum element
            }
        }
        temp = N[i]; 
        N[i] = N[max];
        N[max] = temp; // Putting maximum element at the first postion of profit/weight array
        temp = P[i];
        P[i] = P[max];
        P[max] = temp; // Sorted profit according to profit/weight
        temp = W[i];
        W[i] = W[max];
        W[max] = temp; // Sorted weight according to profit/weight
    }
}

void Knapsack(float *N, float *W, float *P, int n, float C) // Knapsack Function which uses Greedy Algorithm
{
    float profit = 0, weight = C, totalWeight = 0; // initializing values for calculating total profit and weight
    for (int i = 0; i < n; i++)
    {
        if (weight == 0)
            break;
        else if (W[i] <= weight)
        {
            weight -= W[i]; // Updating Remaining weight
            profit += P[i]; // Updating profit gained
            totalWeight += W[i]; // Updating weight gained
            printf("1 Added weight %f and profit %f : \n", W[i], P[i]); //Checking every step of updation of profit and weight
            printf("\n=======================================================\n");
        }
        else // For remaining fractional part
        {
            profit += N[i]*weight; // Adding profit of fractional part
            totalWeight += weight;
            weight = 0; // Setting weight to 0 because in fractional Knapsack final capacity remaining is always 0
            printf("2 Added weight %f and profit %f : \n", W[i], P[i]);
            printf("\n=======================================================\n"); //Checking every step of updation of profit and weight
        }
    }
    printf("Total profit = %f\n", profit);
    printf("Total weight = %f\n", totalWeight);
}

int main()
{
    float C; //Size of container
    int n; //Number objects
    printf("Enter the number of items : ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack : ");
    scanf("%f", &C);
    float P[n], W[n], N[n]; //P[n] = Profit array | W[n] = Weight Array | N[n] = Profit/Weight array
    printf("Enter the profit and weight of each item : \n");
    for (int i = 0; i < n; i++)
    {
        printf("Profit of item %d : ", i + 1);
        scanf("%f", &P[i]);
        printf("Weight of item %d : ", i + 1);
        scanf("%f", &W[i]);
        N[i] = P[i] / W[i]; //Profit/Weight
    }
    sort(N, W, P, n); //Calling sort function
    printf("Profit/Weight after sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f\t",N[i]);
    }
    printf("Profit after sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f\t",P[i]);
    }
    printf("Weight after sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f\t",W[i]);
    }
    
    Knapsack(N, W, P, n, C); // Calling Knapsack function
    return 0;
}