class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        nums = []
        n = len(nums1)
        m = len(nums2)
        a, b = 0, 0

        while True:
            if a >= n or b >= m:
                break

            if nums1[a] < nums2[b]:
                nums.append(nums1[a])
                a += 1
            elif nums1[a] > nums2[b]:
                nums.append(nums2[b])
                b += 1
            else:
                nums.append(nums1[a])
                nums.append(nums2[b])
                a += 1
                b += 1

        nums.extend(nums1[a:])
        nums.extend(nums2[b:])

        if (m+n)%2 != 0:
            median = nums[(m+n)//2]
        else:
            print(nums[(m+n)//2])
            print(nums[(m+n)//2 - 1])
            median = ((nums[(m+n)//2] + nums[(m+n)//2 - 1])/2)

        return median