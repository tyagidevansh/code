class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for a in tokens:
            if len(a) > 1 or a.isdigit():
                stack.append(int(a))
            else:
                if a == '+':
                    stack[-2] += stack[-1]
                elif a == '-':
                    stack[-2] -= stack[-1]
                elif a == '*':
                    stack[-2] *= stack[-1]
                elif a == '/':
                    stack[-2] = int(float(stack[-2]/stack[-1]))
                stack.pop()
        
        return stack[0]