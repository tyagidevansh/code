
def removeDuplicates(nums: list[int]) -> int:
    i, j = 0,1
    for j in range(1, len(nums)):
        if nums[j] != nums[i]:
            i+=1
            nums[i] = nums[j]
        j+=1
            
    return i+1
    
nums = [0,0,1,1,1,2,2,3,3,4]
n = removeDuplicates(nums)

for i in range(n):
    print(nums[i], end = "")