def BubbleSort(list,n):
    for i in range(n-1):
        for j in range(n-i-1):
            if list[j]>list[j+1]:
                list[j] = list[j]^list[j+1]
                list[j+1] = list[j]^list[j+1]
                list[j] = list[j]^list[j+1]


list = [5,4,8,1,4,9,4,3,7,5]
n = len(list)
print("Unsorted list...\n")
print(list)
BubbleSort(list,n)
print("Sorted list...\n")
print(list)

