def calcSums(nums, n):
    possibleSums = nums.copy()
    l = len(nums)
    for i in range(l):
        for j in range(l):
            if i != j:
                possibleSums.append(nums[i] + nums[j])
    print(possibleSums)

    for i in range(1,n+1):
        if i not in possibleSums:
            return i
    
    return -1

def minPatches(nums, n):
    val = 0
    res = 0
    while val != -1:
      val = calcSums(nums, n)
      if val != -1:
        nums.append(val)
        res += 1
    return res
  
nums = [1,5,10]
n = 20

print(minPatches(nums, n))