import time

def print_rangoli(size):
    for i in range(size):
        s = "-".join(chr(ord('a')+n-j-1) for j in range(i+1))
        time.sleep(0.1)
        print((s+s[::-1][1:]).center(n*4-3, '-'))
    
    for i in range(size-2,-1,-1):
        s = "-".join(chr(ord('a')+n-j-1) for j in range(i+1))
        time.sleep(0.1)
        print((s+s[::-1][1::]).center(n*4-3, '-'))
        
if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)