class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        res = ""
        while columnNumber > 0:
            n = (columnNumber - 1) % 26
            columnNumber = (columnNumber - 1)// 26
            res = chr(n + ord('A')) + res
        
        return res