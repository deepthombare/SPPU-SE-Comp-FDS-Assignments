# Author : Deep Thombare
# Assignment no. : 3
'''Write a python program to compute following computation on matrix:
a) Addition of two matrices
b) Subtraction of two matrices
 c) Multiplication of two matrices
d) Transpose of a matrix
'''
m = int(input("ENter number of rows"))
n = int(input("ENter number of columns"))
a = [[0 for j in range(n)] for i in range(m)]
b = [[0 for j in range(n)] for i in range(m)]
add = [[0 for j in range(n)] for i in range(m)]
sub = [[0 for j in range(n)] for i in range(m)]
mul = [[0 for j in range(n)] for i in range(m)]

print("Enter elements for first matrix")
for i in range(m):
    for j in range(n):
        print("Enter the element ",i+1,j+1," : ")
        x = int(input())
        a[i][j] = x
print(a)
print("For second matrix")
for i in range(m):
    for j in range(n):
        print("Enter the element ",i+1,j+1," : ")
        x = int(input())
        b[i][j] = x
print(b)
#addition
for i in range (len(a)):
    for j in range(len(a[0])):
       add[i][j] = a[i][j] + b[i][j]
print("Addition of matrices is ",add)
#Subtraction
for i in range (len(a)):
    for j in range(len(a[0])):
        sub[i][j] = a[i][j] - b[i][j]
print("Subtraction of matrices is ",sub)
#Multiplication
for i in range(m):
    for j in range(n):
        for k in range(n):
            mul[i][j] += a[i][k] * b[k][j]
print("Multiplication of matrices is ",mul)
#Transpose
trans = [[a[j][i] for j in range(m)] for i in range(n)]
print("Transpose of matrices A is ",trans)
trans = [[b[j][i] for j in range(m)] for i in range(n)]
print("Transpose of matrices B is ",trans)

