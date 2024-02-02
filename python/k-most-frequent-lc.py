class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = {}
        res = []

        for i in nums:
            if i in mp:
                mp[i]+=1
            else:
                mp[i] = 1
        
        slis = sorted(mp.items(), key=lambda item : item[1], reverse = True)
        
        for i in range(k):
            res.append(slis[i][0])
        
        return res