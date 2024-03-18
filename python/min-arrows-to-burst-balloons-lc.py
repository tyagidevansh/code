def findMinArrowShots(points) -> int:
        # points.sort()
        # i = 0
        # while i < len(points)-1:
        #     if points[i][0] == points[i+1][0] or points[i][1] < points[i+1][1] and not points[i][1] < points[i+1][0]:
        #         points.insert(0, [points[i+1][0], min(points[i][1], points[i+1][1])])
        #         points.pop(0)
        #         points.pop(0)
        #     i += 1
        # return len(points)
        
        points.sort()

        res = len(points)
        prev = points[0]

        for i in range(1, len(points)):
            curr = points[i]
            if curr[0] <= prev[1]:
                res -= 1
                prev = [curr[0], min(curr[1], prev[1])]
            else:
                prev = curr

        return res

points = [[1,2],[3,4],[5,6],[7,8]]
findMinArrowShots(points)