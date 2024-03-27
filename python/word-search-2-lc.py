# def findWordsHelper(board, word):
#     ROWS, COLS = len(board), len(board[0])
#     visited = set()

#     def dfs(r, c, i):
#         if len(word) == i:
#             return True
        
#         if (r < 0 or c < 0 or r >= ROWS or c >= COLS or word[i] != board[r][c] or (r, c) in visited):
#             return False
        
#         visited.add((r,c))
#         res = (dfs(r+1, c, i + 1) or dfs(r - 1, c, i + 1) or dfs(r, c + 1, i + 1) or dfs(r, c - 1, i + 1))
#         visited.remove((r,c))
#         return res
    
#     for i in range(ROWS):
#         for j in range(COLS):
#             if dfs(i, j, 0):
#                 return True
#     return False


# def findWords(board, words):
#     res = []
#     for word in words:
#         if findWordsHelper(board, word):
#             res.append(word)
#     return res

# board = [["a","a"]]
# words = ["aa"]
# findWords(board, words)

class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False

    def insert(self, word):
        cur = self
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
        cur.endOfWord = True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        for word in words:
            root.insert(word)
        
        ROWS, COLS = len(board), len(board[0])
        res, visit = set(), set()

        def dfs(r, c, node, word):
            if (r < 0 or c < 0 or r >= ROWS or c >= COLS 
                or board[r][c] not in node.children
                or (r,c) in visit):
                return
            
            visit.add((r,c))
            node = node.children[board[r][c]]
            word += board[r][c]
            if node.endOfWord:
                res.add(word)
            
            dfs(r + 1, c, node, word)
            dfs(r - 1, c, node, word)
            dfs(r, c + 1, node, word)
            dfs(r, c - 1, node, word)
            visit.remove((r,c))

        for r in range(ROWS):
            for c in range(COLS):  
                dfs(r, c, root, "")
        
        return list(res)    