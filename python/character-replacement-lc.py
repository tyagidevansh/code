def characterReplacement(s: str, k: int) -> int:
        counts = {}
        l, r = 0, 0
        res = 0

        for r in range(len(s)):
            counts[s[r]] = 1 + counts.get(s[r], 0)
            if s[r] in counts:
                if (r - l + 1) - max(counts.values()) > k:
                    counts[s[l]] -= 1
                    l += 1
                else:
                    res = max(res, (r - l + 1))
        return res

characterReplacement("ABCDE", 1)