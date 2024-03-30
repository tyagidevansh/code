class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        counts = defaultdict(int)
        fl, nl,res = 0,0,0

        for r in range(len(nums)):
            counts[nums[r]] += 1

            while len(counts) > k:
                counts[nums[nl]] -= 1
                if counts[nums[nl]] == 0:
                    counts.pop(nums[nl])
                nl += 1
                fl = nl

            while counts[nums[nl]] > 1:
                counts[nums[nl]] -= 1
                nl += 1

            if len(counts) == k:
                res += nl - fl + 1
        return res
