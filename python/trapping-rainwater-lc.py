def trap(height: list[int]) -> int:
    l,r = 0, len(height) - 1
    left_max = height[l]
    right_max = height[r]
    res = 0
    while l < r:
        if left_max < right_max:
            l+=1
            left_max = max(left_max, height[l])
            res += left_max - height[l]
        else:
            r -= 1
            right_max = max(right_max, height[r])
            res += right_max - height[r]
    return res