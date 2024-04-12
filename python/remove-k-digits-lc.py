def removeKdigits(num: str, k: int) -> str:
        res = ""
        i = 0
        while i < len(num):
            n = num[i]
            for j in range(i+1,i+k+1):
                if j >= len(num):
                    break
                if num[j] < n:
                    n = num[j]
                    if k == 1:
                        k = 0
                        res += num[j:-1]
                        break
                    k = i + (j - i)
                    i = j
            res += n
            if k == 0:
                break
            i += 1
        return res.lstrip('0')

num = "10200"
k = 1
print(removeKdigits(num, k))