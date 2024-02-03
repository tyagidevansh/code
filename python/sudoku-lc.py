class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        numbers=['1','2','3','4','5','6','7','8','9']
        present = []

        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    if board[i][j] in present:
                        print(i,j)
                        return False
                    else:
                        present.append(board[i][j])
            present.clear()

            for k in range(9):
                if board[k][i] != '.':
                    if board[k][i] in present:
                        print(k,i)
                        return False
                    else:
                        present.append(board[k][i])
            present.clear()

        for i in range(0,9,3):
            for j in range(0,9,3):
                for k in range(3):
                    for l in range(3):
                        if board[i+k][j+l] != '.':
                            if board[i+k][j+l] in present:
                                return False
                            else:
                                present.append(board[i+k][j+l])
                present.clear()
        
        return True