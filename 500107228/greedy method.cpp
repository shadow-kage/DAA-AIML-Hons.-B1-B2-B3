#include<stdio.h>
void greedyapproach(int n){
	int weight[100],i;
	float profit[100],ratio[100];
	printf("Enter the number of objects:",n);
	for(i=0;i<n;i++) //for entering object details
	{ 
		printf("\nProfit for object %d:",i+1);
		scanf("%f",&profit[i]);
		printf("\nWeight of object %d:",i+1);
		scanf("%d",&weight[i]);
	}
	for(i=0;i<n;i++) //for printing object details
	{
		printf("\nobject %d:",i+1);
		printf("\nprofit: %f",profit[i]);
		printf("\nweight:%d",weight[i]);
		ratio[i]= profit[i]/weight[i];
		printf("\nprofit/weight: %f",ratio[i]);
    }
    int capacity;
    printf("\nTotal capacity:"); //We take user input for determining the container capacity
    scanf("%d",&capacity);
    int container=0;  //we initialize the capacity of container and max profit
    float MaxProfit=0;
	for(int j=0;j<n;j++) //for traversing all the object details 
	{
		int max=0;
		for(int x=1;x<n;x++)  //for finding object with max ratio i.e p/w
     	{
		    if(ratio[x]>ratio[max]) 
		    {
		    max=x; //since ratio at address x is greater than 1st element, we make it the max value
            }
                else if(ratio[x]==ratio[max])
	    	    {
                    if(weight[x]>weight[max]) //we compare the weight of object in case of equal ratios
		                {
		 	            max=x;
			            }    
	         	    }
		        if(ratio[max]==0)   
		            {
		    	    break;
		            }
		    else
		    {
		    if(container+weight[max]>capacity)
            {      // This for fractional part
                int fractional_weight=capacity-container;
                MaxProfit+=fractional_weight*ratio[max];
                container=capacity;
                break;
            }
            else
            {        // Adding object which has max Profit/weight
                container+=weight[max];  // adding capacity after each insertion
                MaxProfit+=profit[max];  // Profit earned after each insertion
                ratio[max]=0;
                weight[max]=0;
                profit[max]=0;
            }      
        }
    }
}

    printf("Total Profit = %f\n",MaxProfit);
    printf("Container weight = %d\n",container);
}
int main(){
	greedyapproach(7);
	return 0;
}