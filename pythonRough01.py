n = 5  # You can change the value of n to increase/decrease pattern size

# Pattern 1: Left-aligned right-angle triangle
print("Pattern 1: Left-aligned right-angle triangle")
for i in range(1, n + 1):
    print("*" * i)

print("\nPattern 2: Right-aligned right-angle triangle")
# Pattern 2: Right-aligned right-angle triangle
for i in range(1, n + 1):
    print(" " * (n - i) + "*" * i)

print("\nPattern 3: Pyramid")
# Pattern 3: Pyramid
for i in range(1, n + 1):
    print(" " * (n - i) + "*" * (2 * i - 1))

print("\nPattern 4: Inverted pyramid")
# Pattern 4: Inverted pyramid
for i in range(n, 0, -1):
    print(" " * (n - i) + "*" * (2 * i - 1))

print("\nPattern 5: Diamond")
# Pattern 5: Diamond
# Top half
for i in range(1, n + 1):
    print(" " * (n - i) + "*" * (2 * i - 1))
# Bottom half
for i in range(n - 1, 0, -1):
    print(" " * (n - i) + "*" * (2 * i - 1))
