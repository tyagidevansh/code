start = time.time()

# iterative sum
total = 0
# iterating through 1.5 Million numbers
for item in range(0, 1500000):
    total = total + item

print('sum is:' + str(total))
end = time.time()
print(end - start)