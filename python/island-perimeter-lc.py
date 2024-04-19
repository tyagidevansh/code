def islandPerimeter(grid) -> int:
        perimeter = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    perimeter += helper(grid, i, j)
        return perimeter
    
def helper(grid, i, j):
    a = [-1,0,1]
    perimeter = 4

    for n in a:
        for m in a:
            if abs(n) == abs(m):
                continue
            ni = i + n
            nj = j + m
            
            if ni >= 0 and ni < len(grid) and nj >= 0 and nj < len(grid[0]):
                if grid[ni][nj] == 1:
                    perimeter -= 1
    
    return perimeter

grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
print(islandPerimeter(grid))