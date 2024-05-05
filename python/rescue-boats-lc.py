def numRescueBoats(people, limit: int) -> int:
    people.sort()
    res = 0
    l, r = 0, len(people) - 1
    while l <= r:
        res += 1
        if people[l] + people[r] <= limit:
            l += 1
        r -= 1
    return res

people = [5,1,4,2]
print(numRescueBoats(people, 6))