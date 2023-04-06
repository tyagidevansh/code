#bunch of functions that just compare iteration and recursion

def reversing_Strings():
    s = input("Enter string: ")
    n = 1
    for i in range (len(s)):
        print(s[i+len(s)-(n)], end='')
        n+=2
        
    def reverse_string(s):
        if len(s) == 0:
            return s
        else:
            return reverse_string(s[1:]) + s[0]
    reverse_string("hello")
    
def checking_palindromes():
    def iter_palin(s):
        s = ''.join(c for c in s if c.isalnum()).lower()
        for i in range(len(s)//2):
            if s[i] != s[-i-1]:
                return False
        return True

    s = input(" Enter the string: ")

    if iter_palin(s) == True:
        print("its a palindrome")
    else:
        print("not a palindrome")
        
    def recur_palin(s):
        if len(s) == 0 or len(s) == 1:
            return True
        if s[0] == s[len(s)-1]:
            return recur_palin(s[1:len(s)-1])
        return False

    s = input("Enter a string: ")
    if recur_palin(s) == True:
        print("its a palindrome")
    else:
        print("not a palindrome")
     
def decimal_to_binary():        
    def iter_decibinary():
        n = int(input("Enter the decimal number: "))
        binary = ''
        while n > 0:
            binary = str(n%2) + binary
            n//=2
        print(binary)
        
    iter_decibinary()

    def recur_decibinary(n, binary):
        if n == 0:
            return binary
        binary = str(n%2) + binary
        return recur_decibinary(n//2, binary)

    n = int(input("Enter the decimal: "))
    binary = ""
    print(recur_decibinary(n, binary))

def sum_of_n_natural_numbers():
    def iter_sum():
        n = int(input("Enter the number till which you want your sum: "))
        sum = 0
        for i in range(n+1):
            sum = sum+i
        print(sum)
    iter_sum()

    def recur_sum(n,sum):
        if n <= 0:
            return sum
        sum = n + recur_sum(n-1,sum)
        return sum
        
    n = int(input("Enter the number till which you want your sum: "))
    sum = 0
    print(recur_sum(n,sum))
    
def binary_search():
    a = []
    n = input("Enter all the elements of your list (in order, seperated by a comma without space) ")
    a = n.split(",")
    a = [int(n) for n in a ]
    print(a)
    x = int(input("Which number do you wannt to search for? "))
    left = 0
    right = len(a)-1
    
    def iter_binarysearch(a, x, left, right):
        while left <=right:
            mid = (left+right)//2
            if a[mid] == x:
                print(x, "is at index", mid)
                break
            elif a[mid] < x:
                left = mid +1
            else :
                right = mid -1
                
    def recur_binarysearch(a,x, left, right):
        if left > right:
            return 1
        mid = (left+right)//2
        if x == a[mid]:
            print(x, "is at index", mid)
        if x < a[mid]:
            return recur_binarysearch(a,x,left, mid-1)
        else:
            return recur_binarysearch(a,x,mid+1, right)
    
    iter_binarysearch(a,x, left, right)
    recur_binarysearch(a,x,left,right)
  
def factorial():
    def iter_factorial(n, factorial):
        for i in range(1,n+1):
            factorial = i*factorial
        print(factorial)

    def recur_factorial(n, factorial):    
        if n <= 0:
            return factorial
        factorial = recur_factorial(n-1, factorial)*n
        return factorial

    n = int(input("Enter n: "))    
    factorial = 1

    iter_factorial(n, factorial)
    print(recur_factorial(n, factorial))
    
def fibonacci():
    a = 0
    b = 1
    n = 20
    
    def iter_fibo(a,b,n):
        print(a, b, end = " ")
        for i in range(n-2):
            c = a+b
            a = b
            b = c
            print(c, end = " ")
        print("\n")
    
    def recur_fibo(n):
        global series
        if n <= 0:
            return []
        elif n == 1:
            return [0]
        elif n == 2:
            return [0,1]
        else:
            series = recur_fibo(n-1)
            series.append(series[-1] + series[-2])
            return series
        
    iter_fibo(a,b,n)
    recur_fibo(n)
    for item in series: print(item, end = " ")
    
def mergesort(arr):
    if len(arr)  <=1:
        return arr
    mid = len(arr)//2
    left_arr = arr[:mid]
    right_arr = arr[mid:]
    
    left_arr = mergesort(left_arr)
    right_arr = mergesort(right_arr)
    
    sorted_arr = []
    i = j = 0
    while i < len(left_arr) and j < len(right_arr):
        if left_arr[i] < right_arr[j]:
            sorted_arr.append(left_arr[i])
            i+=1
        else:
            sorted_arr.append(right_arr[j])
            j+=1
    sorted_arr += left_arr[i:]
    sorted_arr += right_arr[j:]
    
    return sorted_arr

arr = [0,1,2,4,6,43,9,10,16,12,22]
print(mergesort(arr))