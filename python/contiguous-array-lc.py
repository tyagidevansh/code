def findMaxLength(nums: list[int]) -> int:
        mp = {}
        sum_= 0
        res = 0

        for i, val in enumerate(nums):
            sum_ += 1 if val == 1 else -1
            if sum_ == 0:
                res = i + 1
            elif sum_ in mp:
                res = max(res, i - mp[sum_])
            else:
                mp[sum_] = i
        
        return res

nums = [0,0,1,0,0,0,1,1]
findMaxLength(nums)