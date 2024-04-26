def minFallingPathSum(matrix) -> int:
        # def rec(i, j):
        #     if i == r:
        #         return 0
        #     if j < 0 or j >= c:
        #         return float('inf')
        #     if dp[i][j] != float('inf'):
        #         return dp[i][j]

        #     dp[i][j] = matrix[i][j] + min(rec(i + 1, j - 1), min(rec(i + 1, j), rec(i + 1, j + 1)))
        #     return dp[i][j]
        
        # r = len(matrix)
        # c = len(matrix[0])
        # ans = float('inf')

        # dp = [[float('inf') for _ in range(r)] for _ in range(c)]

        # for i in range(c):
        #     ans = min(ans, rec(0, i))
        # return ans
        
        # n = len(matrix)
        # if n == 1:
        #     return min(matrix[0])
        # minCost = [matrix[0]]
        # for i in range(1, n):
        #     curr = [0] * n
        #     for j in range(n):
        #         if j == 0:
        #             curr[j] = matrix[i][j] + min(minCost[i-1][j], minCost[i-1][j+1])
        #         elif j == n - 1:
        #             curr[j] = matrix[i][j] + min(minCost[i-1][j], minCost[i-1][j-1])
        #         else:
        #             curr[j] = matrix[i][j] + min(minCost[i-1][j], minCost[i-1][j+1], minCost[i-1][j-1])
        #     minCost.append(curr)
        # return min(minCost[-1])    
        
        def rec(i, j):
            if i == r:
                return 0
            if j < 0 or j >= c:
                return float('inf')
            if dp[i][j] != float('inf'):
                return dp[i][j]
            
            temp = []
            for n in range(len(matrix[0])):
                if n == j:
                    continue
                temp.append(rec(i + 1, n))

            dp[i][j] = matrix[i][j] + min(temp)
            return dp[i][j]
        
        r = len(matrix)
        c = len(matrix[0])
        ans = float('inf')

        dp = [[float('inf') for _ in range(r)] for _ in range(c)]

        temp = []

        for i in range(c):
            ans = min(ans, rec(0, i))
            temp = []
        return ans  

matrix = [[2,1,3],[6,5,4],[7,8,9]]

print(minFallingPathSum(matrix))