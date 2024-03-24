def findWordsHelper(board, word):
    ROWS, COLS = len(board), len(board[0])
    visited = set()

    def dfs(r, c, i):
        if len(word) == i:
            return True
        
        if (r < 0 or c < 0 or r >= ROWS or c >= ROWS or word[i] != board[r][c] or (r, c) in visited):
            return False
        
        visited.add((r,c))
        res = (dfs(r+1, c, i + 1) or dfs(r - 1, c, i + 1) or dfs(r, c + 1, i + 1) or dfs(r, c - 1, i + 1))
        visited.remove((r,c))
        return res
    
    for i in range(ROWS):
        for j in range(COLS):
            if dfs(i, j, 0):
                return True
    return False


def findWords(board, words):
    res = []
    for word in words:
        if findWordsHelper(board, word):
            res.append(word)
    return res

board = [["a","a"]]
words = ["aa"]
findWords(board, words)