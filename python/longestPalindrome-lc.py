from typing import Counter

def longestPalindrome(s: str) -> int:
  counts = {}

  for char in s:
      counts[char] = counts.get(char, 0) + 1


  res = 0

  for n in counts.keys():
      if counts[n] % 2 == 0:
          res += counts[n]
      elif res == 0 or res % 2 == 0:
          res += counts[n]

  return res

s = "bananas"

print(longestPalindrome(s))