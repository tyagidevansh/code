def findMax(nums, i, j):
  max_ = 0 
  for a in range(i, j):
      if nums[a] > max_:
          max_ = nums[a]
  return max_

def findMin(nums, i, j):
  min_ = 1000000000
  for a in range(i, j):
      if nums[a] < min_:
          min_ = nums[a]
  return min_

def longestSubarray(nums, limit: int) -> int:
  res = 1
  l,r = 0, 0
  max_, min_ = nums[0], nums[0]

  for r in range(1, len(nums)):
      if l == r:
          continue
      max_ = max(max_, nums[r])
      min_ = min(min_, nums[r])

      if abs(max_ - min_) <= limit:
          res = max(res, r - l)
      else:
          l += 1
          if max_ == nums[l - 1]:
              max_ = findMax(nums, l, r)
          elif min_ == nums[l - 1]:
              min_ = findMin(nums, l, r)
  return res