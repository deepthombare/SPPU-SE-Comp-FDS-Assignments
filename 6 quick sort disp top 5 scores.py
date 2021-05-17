# Author : Deep Thombare
# Assignment no. : 6

'''Write a python program to store first year percentage of students in array.
 Write function for sorting array of floating point numbers in ascending order
 using quick sort and display top five scores. '''


def partition(array,start, end ):
    pivot_index = start
    pivot = array[pivot_index]
    while start < end:
        while start < len(array) and array[start] <= pivot:
            start += 1
        while array[end] > pivot:
            end -= 1
        if (start < end):
            array[start], array[end] = array[end], array[start]
    array[end], array[pivot_index] = array[pivot_index], array[end]
    return end


def quickSort(array, low, high):
    if low < high:
        pi = partition(array, low, high)
        quickSort(array, low, pi - 1)
        quickSort(array, pi + 1, high)
    return array


n = int(input("Number of Students : "))
arr = []
for i in range(n):
    arr.append(float(input("Enter Percentage of student  : ")))

print("\nYour Entered array is :", arr)

sortedPerc = quickSort(arr, 0, len(arr) - 1)
print("\nSorted array is :", sortedPerc)
i = 1
print("Percentages of top 5 students are : ")
while i <= 5:
    print(sortedPerc[-i], "%")
    i += 1
