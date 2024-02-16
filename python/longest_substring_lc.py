# class Solution(object):
#     def lengthOfLongestSubstring(self, s):
#         charSet = set()
#         l = 0
#         res = 0

#         for r in range(len(s)):
#             while s[r] in charSet:
#                 charSet.remove(s[l])
#                 l += 1
#             charSet.add(s[r])
#             res = max(res, r - l + 1)
    
#         return res

def lengthOfLongestSubstring(s: str) -> int:
        seen = []
        res, start = 0, 0

        for i in range(len(s)):
            if s[i] not in seen:
                seen.append(s[i])
                res = max(res, i - start + 1)
            else:
                while s[start] != s[i]:
                    start += 1
                    seen.pop(0)
                start += 1

        return res

s = "aabaab!bb"
lengthOfLongestSubstring(s)