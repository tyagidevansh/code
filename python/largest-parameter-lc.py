def largestPerimeter(nums: list[int]) -> int:
        nums.sort()
        _sum = sum(nums)
        
        for i in range(len(nums) - 1, 1, -1):
            _sum -= nums[i]
            if _sum > nums[i]:
                return _sum + nums[i]
        
        return -1
    
nums = [1,12,1,2,5,50,3]
largestPerimeter(nums)