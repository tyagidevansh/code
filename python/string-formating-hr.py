def oct(number):
    result = ""
    while number > 0:
        result = str(number%8) + result;
        number //= 8
    if result == "":
        result = "0"
    
    return result  

def hex(number):
    chars = "0123456789ABCDEF"
    result = ""
    
    while number > 0:
        remainder = number % 16
        result = chars[remainder] + result
        number //= 16
    if result == "":
        result = "0"
    
    return result

def bin(number):
    result = ""
    while number > 0:
        result = str(number%2)+result
        number //= 2
    if result == "":
        result = "0"
    
    return result

def print_formatted(number):
    width = len(bin(number))
    for n in range(1, number+1):
        print(f"{n:>{width}} {oct(n):>{width}} {hex(n):>{width}} {bin(n):>{width}}")
        
        
            

if __name__ == '__main__':
    n = int(input())
    print_formatted(n)