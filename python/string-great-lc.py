def makeGood(s: str) -> str:
        ls = list(s)
        isChanged = True
        while isChanged == True:
            i = 0
            isChanged = False
            while i < len(ls)-1:
                if ls[i+1] == ls[i].upper() or ls[i+1].upper() == ls[i]:
                    isChanged = True
                    ls.pop(i)
                    ls.pop(i)
                else:
                    i += 1
        return ''.join(ls)

s = "Pp"
print(makeGood(s))