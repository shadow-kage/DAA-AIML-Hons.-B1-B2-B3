def SelectionSort(list,n):
    for i in range(n-1):
        min = i
        for j in range(i+1,n):
            if list[j] < list[min]:
                min = j
        temp = list[i]
        list[i] = list[min]
        list[min] = temp

list = [2,4,3,9,1,4,8,7,5,6]
n = len(list)
print("Unsorted list...\n")
print(list)
SelectionSort(list,n)
print("Sorted list...\n")
print(list)
