def findTheWinner(n: int, k: int) -> int:
  nums = [i for i in range(1, n + 1)]

  i = 0

  while len(nums) > 1:
      j = i + k - 1
      if j >= len(nums):
          j = j - len(nums)
      nums.pop(j)
      i = j
  
  return nums[0]

findTheWinner(6, 5);