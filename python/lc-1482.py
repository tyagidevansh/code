def check(blooms, m, k):
  temp = 0
  for i in range(len(blooms)):
      if blooms[i] == 'x':
          temp += 1
      else:
        if temp == k:
          temp = 0
          m -= 1
          if m == 0:
              return True
  return False

def minDays(bloomDay, m: int, k: int) -> int:
  if m*k > len(bloomDay):
      return -1
  
  max_ = max(bloomDay)
  min_ = min(bloomDay)

  res = 10000000000

  while min_ <= max_:
      blooms = ['_'] * len(bloomDay)
      mid = (max_ + min_) // 2

      for i in range(len(bloomDay)):
          if bloomDay[i] <= mid:
              blooms[i] = 'x'
      
      if check(blooms, m, k) == True:
          res = min(res, mid)
          max_ = mid - 1
      else:
          min_ = mid + 1
  
  if res == 10000000000:
      return -1
  else:
      return res
    
bloomDay = [7,7,7,7,12,7,7]

minDays(bloomDay, 2, 3)