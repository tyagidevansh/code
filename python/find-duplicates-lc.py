#super cool trick!!
#due to the constraints of the array every single element is a valid index if you subtract one from it
#so if an element ever appears twice, its def referencing the same index

def findDuplicates(nums: list[int]) -> list[int]:
        ans = []
        n = len(nums)
        for x in nums:
            x = abs(x)
            if nums[x-1] < 0:
                ans.append(x)
            nums[x-1] *= -1
        return ans

nums = [4,3,2,7,8,2,3,1]
findDuplicates(nums)
