// Code for Group 1
#include <stdio.h>
int binarySearch(int arr[], int beg, int end, int x,int *flag) {
    if (arr == NULL) {
        return -1; 
    }
    if (beg == end) {
        if (arr[beg] == x) {
            return beg; 
        }
        else {
            return -1; 
        }
    }
    while (beg <= end) {
    	(*flag)++;
        int mid = beg + (end - beg) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            beg = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1; 
}
int main() {
    int c = 0;
    int arr[] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150};
    int n = sizeof(arr) / sizeof(arr[0]);
    int y = 30;
    int flag=0;
    int result = binarySearch(arr, 0, n - 1, y,&flag);
    if (result == -1) {
        printf("Element is not present in array");
    }
    else {
        printf("Element is present at index %d\n", result);
        printf("No. of steps:%d",flag);
    }
    return 0;
}