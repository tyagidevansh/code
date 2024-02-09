def trap(height: list[int]) -> int:
        i, j = 0, 1
        temp = []
        res = 0
        while j < len(height) - 1:
            diff = abs(height[j] - height[i])
            if diff != 0:
                while j > i:
                    area = abs(height[i+1] - height[i])
                    res += area
                    i+=1     
                j += 1   
            else:
                i+=1
        
        return res

h = [0,1,0,2,1,0,1,3,2,1,2,1]

print(trap(h))