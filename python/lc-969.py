def flip(arr, k):
    res = arr[:k][::-1]
    res += arr[k:]
    return res
def pancakeSort(arr):
    res = []
    for i in range(len(arr) - 1, 0, -1):
        for j in range(0, i):
            if arr[j] == i + 1:
                arr = flip(arr, j)
                res.append(j + 1)
                break
        arr = flip(arr, i)
        res.append(i + 1)
  
pancakeSort([3,2,4,1])