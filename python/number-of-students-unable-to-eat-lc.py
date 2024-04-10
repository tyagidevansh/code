def countStudents(students: list[int], sandwiches: list[int]) -> int:
        n = len(students)
        while n >= 0:
            while len(students) > 0 and students[0] == sandwiches[0]:
                students.pop(0)
                sandwiches.pop(0)
                n = len(students)
            
            if len(students) == 0:
                return 0
            
            temp = students[0]
            students.pop(0)
            students.append(temp)
            n -= 1
        return len(students)
students = [1,1,0,0]
sandwiches = [0,1,0,1]
countStudents(students, sandwiches)