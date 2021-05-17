# Author : Deep Thombare
# Assignment no. : 5
'''Write a python program to store second year percentage of students in array.
 Write function for sorting array of floating-point numbers in ascending order using
a) Insertion sort
b) Shell Sort and display top five scores '''

class sorting:
    def __init__(self):
        self.marks = []
        print("Enter list of students percentage in a line ")
        self.marks = list(map(int, input().split()))
    def insertion_sort(self):
        n = len(self.marks)
        for i in range(1,n):
            val = self.marks[i]
            ptr = i-1
            while(ptr >= 0 and val<self.marks[ptr]):
                self.marks[ptr+1] = self.marks[ptr]
                ptr -= 1
            self.marks[ptr+1] = val
        print("Sorted list is ")
        print(self.marks)
    def shell_sort(self):
        n = len(self.marks)
        gap = n//2
        while(gap>0):
            for i in range(gap,n):
                t = self.marks[i]
                j = i
                while j >= gap and self.marks[j-gap] > t:
                    self.marks[j] = self.marks[j-gap]
                    j -= gap
                self.marks[j] = t
            gap = gap//2
        print("Sorted list is ")
        print(self.marks)
    def display(self):
        n = len(self.marks)
        print("Top Five percentage are:-")
        for i in range(len(self.marks) - 1, len(self.marks) - 6, -1):
            print(self.marks[i])

#------------------------------MENU-----------------------------------------------------------
obj = sorting()
while(True):
    print("Enter sorting you want to perform"
          "\n1.Insertion Sort"
          "\n2.Shell Sort"
          "\n3.Display top 5 Scores.")
    i = int(input())
    if (i == 1):
        obj.insertion_sort()
    elif (i == 2):
        obj.shell_sort()
    else:
        obj.display();
        exit()



