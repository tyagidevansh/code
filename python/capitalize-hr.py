def solve(s):
    result = []
    for i in range(len(s)):
        if (i == 0 or s[i-1] == ' ') and s[i].isalpha():
            result.append(s[i].upper())
        else:
            result.append(s[i])
    return ''.join(result)

s = input("Enter a string: ")
print(solve(s))
