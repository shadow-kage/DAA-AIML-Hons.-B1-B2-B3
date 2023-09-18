#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//defining the limits of the available objects
#define items 7


void swap(float *, float *);
int partition(float arr[][items], int low, int high);
void sort(float arr[][items], int low, int high);

//printing the values of the array
void print(float arr[2][items],int size){

    //printing the object number
    for(int i=0;i<size;i++){
        printf("%dth \t",i+1);
    }
    printf("\n");

    //
    for(int i=0;i<2;i++){
        for(int j=0;j<size;j++){
            if(i==0){
                printf("%.1f\t",arr[i][j]);
            }
            else{
                printf("%.0f\t",arr[i][j]);
            }
        }
        printf("\n");
    }
}

//greedy algorithm for calculating maximum profit
float greedy_algo(float arr[2][items],int size){

    //declaring and inputting the maximum limit of sack
    float total_weight;
    printf("Enter the maximum limit of the sack\n");
    scanf("%f",&total_weight);
    float total_profit=0.0;

    //Calculating profit/weight
    for(int i=0;i<size;i++){
        arr[0][i]/=arr[1][i];
    }
    
    //soring on basis for profit/weight on decreasing order
    sort(arr,0,size-1);

    //finding optimal solution :
    for(int i=0;i<size;i++){
        if((total_weight>0)&&(arr[1][i]<=total_weight)){
            total_weight=total_weight-arr[1][i];
            total_profit+=(arr[0][i]*arr[1][i]);
        }
        else if(total_weight>0){
            total_profit+=arr[0][i]*total_weight;
            total_weight=0;
        }
        else{
            break;
        }
    }
    
    //returning the total peofit
    return total_profit;
}
int main(){
    int choice;
    srand(time(NULL));

    //declared and initialized sample solution array with 0.
    float array[2][items];   

    //choice to insert
    printf("Enter:\n1:Profits and Weights Filled randomly\n2:Profit and Weight Filled by you\n");
    scanf("%d",&choice);
    switch (choice)
    {

        //generating random numbers for profits and weights
        case 1:{
            for(int i=0;i<2;i++){
                for(int j=0;j<items;j++){
                    if(i==0){
                        array[i][j]=rand()%20;
                    }
                    else{
                        array[i][j]=rand()%10+1;
                    }
                }
            }
            break;
        }

        //taking inputs from users
        case 2:{
            for(int i=0;i<2;i++){
                for(int j=0;j<items;j++){
                    if(i==0){
                        printf("Enter Profits for %d item:\n",j+1);
                    }
                    else{
                        printf("Enter weight for %d items:\n",j+1);
                    }
                    scanf("%f",&array[i][j]);
                }
            }
            break;
        }
    }
    printf("Items with Profits and weights:\n");
    print(array,items);
    printf("Total maximum profit: %f\n",greedy_algo(array,items));
    return 0;
}

//swapping the numbers for quicksort
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

//partition
int partition(float arr[][items], int low, int high) {
    float pivot = arr[0][high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[0][j] > pivot) {
            i++;
            swap(&arr[0][i], &arr[0][j]);
            swap(&arr[1][i], &arr[1][j]);
        }
    }

    swap(&arr[0][i + 1], &arr[0][high]);
    swap(&arr[1][i + 1], &arr[1][high]);
    return i + 1;
}

//quicksort
void sort(float arr[][items], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
}