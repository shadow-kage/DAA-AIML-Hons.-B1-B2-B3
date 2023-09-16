def InsertionSort(list,n):
    for i in range(n-1):
        key = list[i]
        j = i - 1
        while(j>=0 and list[j] > key):
            list[j+1] = list[j]
            j-=1
        list[j+1] = key

list = [2,4,3,9,1,4,8,7,5,6]
n = len(list)
print("Unsorted list...\n")
print(list)
InsertionSort(list,n)
print("Sorted list...\n")
print(list)
