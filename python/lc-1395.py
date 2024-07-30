def numTeams(rating) -> int:
  res = 0
  for i in range(len(rating)):
      n = 1
      comparator = rating[i]
      for j in range(i, len(rating)):
          if comparator < rating[j]:
              comparator = rating[j]
              n += 1
      if n >= 3:
          res += 3 - n + 1

      n = 1
      comparator = rating[i]
      for j in range(i, len(rating)):
          if comparator > rating[j]:
              comparator = rating[j]
              n += 1
      if n >= 3:
          res += 3 - n + 1

  return res

rating = [2,5,3,4,1]
numTeams(rating)