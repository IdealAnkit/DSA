matrix = [[x for x in range(3)] for y in range(3)]

count = 0
for row in matrix:
    for element in row:
        if element % 2 != 0:
            count += 1
print(count)

