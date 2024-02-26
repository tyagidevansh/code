# def checkInclusion(s1: str, s2: str) -> bool:
#         n = len(s1)
#         counts1 = {}
#         for c in s1:
#             if c in counts1:
#                 counts1[c] += 1
#             else:
#                 counts1[c] = 1

#         counts2 = {}

#         letters = "abcdefghijklmnopqrstuvwxyz"
#         for i in range(26):
#             counts2[letters[i]] = 0

#         i, j = 0, 0
#         while True:
#             if i == len(s2) - len(s1):
#                 return False
        
#             c = s2[j]
#             counts2[c] += 1
            
#             if j - i == n:
#                 if counts1 == counts2:
#                     return True
#                 else:
#                     counts2[s2[i]] -= 1
#                 j += 1
#                 i += 1
#             else:
#                 j += 1

# def checkInclusions(s1: str, s2:str) -> bool:
#     n = len(s1)
#     counts1 = Counter(s1)
#     counts2 = Counter()
    
#     i, j = 0, 0
    
#     while j < len(s2):
#         counts2[s2[j]] += 1
#         if j - i + 1 == n:
#             if counts1 == counts2:
#                 return True
#             counts2[s2[i]] -= 1
#             if counts2[s2[i]] == 0:
#                 del counts2[s2[i]]
#             i += 1
#         j += 1
#     return False

def checkInclusions(s1: str, s2: str) -> bool:
    n = len(s1)
    counts1 = {}
    counts2 = {}
    
    for c in s1:
        counts1[c] = counts1.get(c, 0) + 1
    
    i, j = 0, 0
    
    while j < len(s2):
        counts2[s2[j]] = counts2.get(s2[j], 0) + 1
        if j - i + 1 == n:
            if counts1 == counts2:
                return True
            counts2[s2[i]] -= 1
            if counts2[s2[i]] == 0:
                del counts2[s2[i]]
            i += 1
        j += 1
    
    return False
s1 = "ab"
s2 = "eidbaooo"

checkInclusion(s1, s2)