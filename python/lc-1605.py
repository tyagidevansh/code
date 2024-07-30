def restoreMatrix( rowSum, colSum):
  res = [[0 for i in range(len(colSum))] for j in range(len(rowSum))]

  n = len(rowSum)
  m = len(colSum)
  
  total = sum(rowSum)
  
  for i in range(len(rowSum)):
    res[i][0] = rowSum[i]
  
  for j in range(len(colSum) - 1):
    deficit = total - colSum[i]
    for i in range(j, len(rowSum)):
      diff = min(rowSum[i], deficit)
      deficit -= diff
      res[j][i] -= diff
      res[j][i + 1] =  diff;
      if deficit == 0:
        break
    
      
    
rowSum = [5,7,10]
colSum = [8,6,8]

print(restoreMatrix(rowSum, colSum))