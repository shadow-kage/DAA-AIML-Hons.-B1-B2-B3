def Partition(lst, low, high):
    pivot = lst[low]
    i = low + 1
    j = high

    while True:
        while i <= j and lst[i] <= pivot:
            i += 1
        while i <= j and lst[j] >= pivot:
            j -= 1
        if i <= j:
            lst[i], lst[j] = lst[j], lst[i]
        else:
            break

    lst[low], lst[j] = lst[j], lst[low]
    return j

def QuickSort(lst, low, high):
    if low < high:
        partitionIndex = Partition(lst, low, high)
        QuickSort(lst, low, partitionIndex - 1)
        QuickSort(lst, partitionIndex + 1, high)

list = [2, 4, 3, 9, 1, 4, 8, 7, 5, 6]
n = len(list)
print("Unsorted list...\n")
print(list)
QuickSort(list, 0, n - 1)
print("Sorted list...\n")
print(list)
