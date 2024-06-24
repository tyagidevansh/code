def numberOfSubarrays(nums, k: int) -> int:
  for i in range(len(nums)):
    nums[i] %= 2
    
    prefix_count = [0] * (len(nums) + 1)
    prefix_count[0] = 1
    s = 0
    ans = 0

    for num in nums:
        s += num
        if s >= k:
            ans += prefix_count[s - k]
        prefix_count[s] += 1
    
    return ans

nums = [1,1,2,1,1]
k = 3

numberOfSubarrays(nums, k)