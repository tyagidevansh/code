def maxSubarrayLength(nums: list[int], k: int) -> int:
    counts = {}
    l, r, res = 0, 0, 0

    while r < len(nums):
        counts[nums[r]] = counts.get(nums[r], 0) + 1
        while counts[nums[r]] > k:
            counts[nums[l]] -= 1
            l += 1
        res = max((1 + r - l), res)
        r += 1
    return res

nums = [1,2,3,1,2,3,1,2]
k = 2
maxSubarrayLength(nums, 2)