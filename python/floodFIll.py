def floodFill(image: list[list[int]], sr: int, sc: int, color: int) -> list[list[int]]:
        if not image:
            return

        target = image[sr][sc]
    
        def dfs(r, c):
            if r < 0 or r >= len(image) or c < 0 or c >= len(image[0]) or image[r][c] != target:
                return
            
            image[r][c] = color

            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)
        
        dfs(sr, sc)

        return image

image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1 
sc = 1
color = 2

floodFill(image, sr, sc, color)
print(image)