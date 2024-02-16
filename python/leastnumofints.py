class Solution:
    def findLeastNumOfUniqueInts(arr: list[int], k: int) -> int:
        counts = {}

        for i in range(len(arr)):
            if arr[i] in counts:
                counts[arr[i]] += 1
            else:
                counts[arr[i]] = 1
        
        counts_sorted = sorted(counts.items(), key = lambda x : x[1])

        res = len(counts.keys())

        for elements in counts_sorted:
            if elements[1] <= k:
                res -= 1
                k -= elements[1]
            else:
                break
        
        return res