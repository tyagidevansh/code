class Solution:
    def simplifyPath(self, path: str) -> str:
        if len(path) == 0:
            return ""

        stack = []
        path_list = path.split('/')
        
        for a in path_list:
            if a == '' or a == '.':
                continue
            if a == '..':
                if len(stack) >= 1:
                    stack.pop()
            else:
                stack.append(a)
        
        res = '/'
        for a in stack:
            res += a
            res += '/'
            
        return res[:-1] if len(res) > 1 else res