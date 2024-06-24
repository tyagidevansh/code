def maxSatisfied(customers, grumpy, minutes: int) -> int:
  initial = 0

  grumpy_compl = [1 if grumpy[i] == 0 else 0 for i in range(len(grumpy))]
  for i in range(len(customers)):
      initial += customers[i] * grumpy_compl[i]
  
  
  i, j = 0, 0
  pos_dif = 0
  temp = 0

  while j < len(customers):
      temp += customers[j] * grumpy[j]
      pos_dif = max(pos_dif, temp)

      j += 1

      if j - i == minutes:
          temp -= customers[i] * grumpy[i]
          i += 1
      

  return initial + pos_dif

customers = [2,6,6,9]
grumpy = [0,0,1,1]
minutes = 1

maxSatisfied(customers, grumpy, minutes)