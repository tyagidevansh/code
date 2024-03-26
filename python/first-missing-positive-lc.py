def firstMissingPositive(nums: list[int]) -> int:
        n = len(nums)
        for i in range(len(nums)):
            if nums[i] > n or nums[i] < 1:
                nums[i] = n + 1
            
        for i in range(len(nums)):
            num = abs(nums[i])
            if num > n:
                continue
            num -= 1
            if nums[num] > 0:
                nums[num] *= -1
        
        for i in range(len(nums)):
            if nums[i] >= 0:
                return i + 1
        
        return n + 1

nums = [3,4,-1,1]
firstMissingPositive(nums)