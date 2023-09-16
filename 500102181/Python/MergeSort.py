def Merge(list,low,high,mid):
    i=k=low
    j=mid+1
    temp = []
    while(i<=mid and j<=high):
        if(list[i]<list[j]):
            temp.append(list[i])
            i+=1
        else:
            temp.append(list[j])
            j+=1
    while(i<=mid):
        temp.append(list[i])
        i+=1
    while(j<=high):
        temp.append(list[j])
        j+=1
    for i in range(low,high + 1):
       list[i] =  temp[i - low]

def MergeSort(list,low,high):
    if(low<high):
        mid = (low+high)//2
        MergeSort(list,low,mid)
        MergeSort(list,mid+1,high)
        Merge(list,low,high,mid)

list = [2,4,3,9,1,4,8,7,5,6]
n = len(list)
print("Unsorted list...\n")
print(list)
MergeSort(list,0,n-1)
print("Sorted list...\n")
print(list)
