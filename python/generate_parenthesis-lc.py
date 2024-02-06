class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack = []
        res = []

        def backtrack(openN, closeN):
            #if the number of open and closed braces is equal to n, we are done
            if openN == closeN == n:
                res.append("".join(stack))
                return
            
            #if number of open braces is less than n, we can add open or close braces
            if openN < n:
                stack.append("(")
                backtrack(openN + 1, closeN)
                stack.pop()
            
            
            #if number of close braces is less than open braces, we can add close braces
            if closeN < openN:
                stack.append(")")
                backtrack(openN, closeN + 1)
                stack.pop()

        backtrack(0,0)
        return res 