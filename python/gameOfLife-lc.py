def gameOfLife(board: list[list[int]]) -> None:
        buffer = [row[:] for row in board]
        def isAlive(i, j) -> bool:
            numberAlive = 0
            neighbours = (-1, 0, 1)

            for dx in neighbours:
                for dy in neighbours:
                    if dx == 0 and dy == 0:
                        continue
                    
                    ni = i + dx
                    nj = j + dy

                    if ni >= 0 and ni < len(board) and nj >= 0 and nj < len(board[0]):
                        numberAlive += board[ni][nj]
            if board[i][j]:
                return numberAlive == 2 or numberAlive == 3
            else:
                return numberAlive == 3

        for i in range(len(board)):
            for j in range(len(board[0])):
                if isAlive(i, j) == True:
                    buffer[i][j] = 1
                else:
                    buffer[i][j] = 0
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                board[i][j] = buffer[i][j]

board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
gameOfLife(board)