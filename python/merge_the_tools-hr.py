def merge_the_tools(string, k):
    subs = []
    length = len(string)
    result = []
    word = ""
    
    for i in range(0,length,k):
        subs.append(string[i:i+k])
    print(subs)
    
    for sub in subs:
        word = ""
        for char in sub:
            if char not in word:
                word += char
        result.append(word)
    
    for res in result:
        print(res)

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)