class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        closestSum = math.inf
        distance = math.inf
        nums.sort()

        for i in range(len(nums)):
            l, r = i + 1, len(nums) - 1

            while (l < r):
                sum = nums[i] + nums[l] + nums[r]

                if sum == target:
                    return sum
                elif abs(sum - target) < distance:
                    closestSum = sum
                    distance = abs(sum - target)

                if sum < target:
                    l += 1
                else:
                    r -= 1
        return closestSum
