def numSubarrayProductLessThanK(nums: list[int], k: int) -> int:
        if k <= 1:
            return 0
        l, r, res = 0, 0, 0
        product = 1
        
        while r < len(nums):
            product *= nums[r]
            while product >= k and l < len(nums):
                product //= nums[l]
                l += 1
            res += (1 + r - l)
            r += 1
        
        return res

nums = [10,5,2,6]
print(numSubarrayProductLessThanK(nums, 100))