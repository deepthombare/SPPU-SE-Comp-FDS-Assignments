#Author : Deep Thombare
#Assignment no. : 1

'''In second year computer engineering class, group A student’s play cricket, group B students play badminton and group C students play football.
Write a Python program using functions to compute following: -
a) List of students who play both cricket and badminton
b) List of students who play either cricket or badminton but not both
c) Number of students who play neither cricket nor badminton
d) Number of students who play cricket and football but not badminton.
(Note- While realizing the group, duplicate entries should be avoided, Do not use SET built-in functions) '''

u=[]
n=int(input("Enter Number of  students: "))
for i in range(n):
    x=int(input('Enter Roll Number '))
    u.append(x)
a=[]
n=int(input("Enter Number of students playing Cricket   : "))
for i in range(n):
    x=int(input('Enter Roll Number '))
    a.append(x)
b=[]
m=int(input("Enter Number of students playing Badminton  : "))
for i in range(m):
    x=int(input('Enter Roll Number '))
    b.append(x)
c=[]
o=int(input("Enter Number of students playing Football   : "))
for i in range(o):
    x=int(input('Enter Roll Number '))
    c.append(x)
#) List of students who play both cricket and badminton
def intsec(a,b):
    com=[]
    for word in u:
        if(word in a and word in b):
            com.append(word)
    return(com)
#List of students who play either cricket or badminton but not both
def enb(a,b):
    enb=[]
    for word in u:
        if(word not in b and word in a):
            enb.append(word)
        if(word not in a and word in b):
            enb.append(word)
    return(enb)

#Number of students who play neither cricket nor badminton
def func(a,b,c):
    k=[]
    for word in u:
        if(word not in a and word not in b):
            k.append(word)
    return(len(k))
#Number of students who play cricket and football but not badminton
def func2(a,b,c):
    k=[]
    for word in u:
        if(word in a or word in b):
            if word not in c:
                k.append(word)
    return(len(k))

print('Roll number of students playing both Cricket and Badminton is : ',intsec(a,b))
print('Roll number of students playing either Cricket or Badminton but not both is : ',enb(a,b))
print('Number of students playing neither cricket nor badminton is : ',func(a,b,c))
print('Number of students playing either Cricket or Football but not Badminton is : ',func2(a,c,b))
