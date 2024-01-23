def sum_of_evens(lst):
    return sum(num for num in lst if num % 2 == 0)

lst = [1,2,3,4,5]
print(sum_of_evens(lst))