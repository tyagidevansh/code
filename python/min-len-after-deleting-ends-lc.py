def minimumLength(s: str) -> int:
        # i, j = 0, len(s) - 1
        # s = list(s)
        # while i < j:
        #     if s[i] == s[j]:
        #         c = s[i]
        #         while i < j and s[i] == c:
        #             s.pop(0)
        #             j -= 1
        #             #i += 1
        #         while i < j and s[j] == c:
        #             s.pop(-1)
        #             j -= 1
        #         if len(s) == 1:
        #             if s[i] == c:
        #                 return 0
        #             else:
        #                 return 1
        #     else:
        #         return len(s)
        # return len(s)
        
        left, right = 0, len(s) - 1

        while left < right and s[left] == s[right]:
            char = s[left]
            while left <= right and s[left] == char:
                left += 1
            while right >= left and s[right] == char:
                right -= 1
        
        return right - left + 1

s = "cabaabac"
minimumLength(s)