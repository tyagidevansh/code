import collections
# def maxSlidingWindow(nums: list[int], k: int) -> list[int]:
#     deque = collections.deque()
#     res = []
#     l = r = 0
    
#     while r < len(nums):
#         while deque and nums[deque[-1]] < nums[r]:
#             deque.pop()
#         deque.append(r)

#         if l > deque[0]:
#             deque.popleft()
        
#         if (r + 1) >= k:
#             res.append(nums[deque[0]])
#             l += 1
#         r += 1

#     return res

def maxSlidingWindow(nums: list[int], k : int) -> list[int]:
    d = collections.deque()
    res = []
    n = len(nums)
    
    for i in range(k):
        while d and nums[d[-1]] <= nums[i]:
            d.pop()
        d.append(i)
    res.append(nums[d[0]])
        
    for i in range(k, n):
        if i - d[0] >= k:
            d.popleft()
        while d and nums[d[-1]] <= nums[i]:
            d.pop()
        d.append(i)
        res.append(nums[d[0]])

    return res
        
nums = [1,3,-1,-3,5,3,6,7]
k = 3

print(maxSlidingWindow(nums, k))