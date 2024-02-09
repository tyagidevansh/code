def numSquares(n: int) -> int:
        squares = [1]
        i, si = 1, 1
        while si < n:
            i += 1
            si = i*i
            squares.append(si)

        dp = [n + 1] * (n + 1)
        dp[0] = 0

        for a in range(1, n + 1):
            for s in squares: 
                if a - s >= 0:
                    dp[a] = min(dp[a], 1 + dp[a-s])
        
        return dp[n] if dp[n] != n + 1 else -1
    
print(numSquares(1))