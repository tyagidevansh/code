def minRemoveToMakeValid(s: str) -> str:
        # stack = []
        # ls = list(s)
        # i = 0
        # while i < len(ls):
        #     if ls[i] == ')':
        #         if len(stack) > 0 and stack[-1] == '(':
        #             stack.pop()
        #             i += 1
        #         else:
        #             ls.pop(i) 
        #     elif ls[i] == '(':
        #         stack.append('(')
        #         i += 1
        #     else:
        #         i += 1

        # i = len(ls) - 1
        # stack = []

        # while i >= 0:
        #     if ls[i] == '(':
        #         if len(stack) > 0 and stack[-1] == ')':
        #             stack.pop()
        #         else:
        #             ls.pop(i)
        #     elif ls[i] == ')':
        #         stack.append(')')
        #     i -= 1
        
        # return ''.join(ls)
        stack = []
        s = list(s)

        for char, idx in enumerate(s):
            if char == '(':
                stack.append(char)
            elif char == ')':
                if stack:
                    stack.pop()
                else:
                    s[idx] = ''
        
        for char in stack:
            s[char] = ''
        
        return ''.join(s)

s = "lee(t(c)o)de)"
print(minRemoveToMakeValid(s))