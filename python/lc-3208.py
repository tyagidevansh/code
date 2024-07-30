def numberOfAlternatingGroups(colors: int, k: int) -> int:
  colors += colors[: k - 1]

  res = 0

  for i in range(1, len(colors)):
    j = i
    valid = True
    while j - i < k  and j < len(colors):
      if colors[j] == colors[j - 1]:
          valid = False
          break
      j += 1
    
    if valid:
      res += 1

colors = [1,1,0,1]
k = 4

print(numberOfAlternatingGroups(colors, k))