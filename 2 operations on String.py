#Author : Deep Thombare
#Assignment no. : 2
'''
Write a Python program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string
'''
class string :

    def __init__(self):
        s = ''
    def gets(self):
        print("Enter a string")
        self.s = input()
    def longest_word(self):
        print("Enter no. of words in list. to find longest word.")
        n = int(input())
        print ("Enter words")
        str = []
        l = 0
        for i in range(n):
            a = input()
            str.append(a)
            if l<len(a):
                lw = a
                l = len(a)
        print("The longest word is ",lw)
    def freq_occurence(self):
        print("Enter the string to find the frequency of appereance of a character.")
        str = input()
        print("Enter the character ")
        c = input()
        k = 0
        for i in str:
            if c == i:
                k = k + 1
        print ("The occurence of ",c," in string ",str," is ",k)
    def palindrome(self):
        print("Enter the string to find palindrome. ")
        str = input()
        ex = str[::-1]
        if ex == str:
            print("The string is Palnidrome ")
        else:
            print("The string is not palindrome ")
    def fisrtocc(self):
        print("Enter the sentence to find first occ of substring ")
        s1 = input()
        print ("Enter The substring to find ")
        s2 = input()
        l2 = len(s2)
        for i in range(len(s1)):
            if s1[i] == s2[0]:
                end = i + l2
                sub1 = s1[i:end]
                if s2 == sub1:
                    print("The index of substring is ",i)
                    break
        else:
            print("Substring not found")

    def occ_of_word(self):
        dictionary = {}
        print("Enter the sentence to find occurence if each word. ")
        str = input()
        lst = str.split()
        for elements in lst:
            if elements[-1] == '.':
                elements = elements[0:len(elements) - 1]

            if elements in dictionary:
                dictionary[elements] += 1

            else:
                dictionary.update({elements: 1})

        for i in dictionary:
            print("Frequency of ", i, end=" ")
            print(":", end=" ")
            print(dictionary[i], end=" ")
            print()


obj = string()
obj.longest_word()
obj.freq_occurence()
obj.palindrome()
obj.fisrtocc()
obj.occ_of_word()





