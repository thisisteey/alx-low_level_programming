#!/usr/bin/python3
# finds palindrome made from the product of two 3-digit numbers
# using def getpalindrome(x) prototype

def getpalindrome(x):
    st = str(x)
    return st == st[::-1]
arr = []
for num in range(999, 99, -1):
    for dig in range (num, 99, -1):
        if getpalindrome(num * dig):
            arr.append(num * dig)
print(max(arr))
