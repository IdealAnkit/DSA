def bubble_sort(arr):
    n = len(arr)
    
    for i in range(n):
        # Flag to check if any swapping happens
        swapped = False

        # Last i elements are already in place
        for j in range(0, n - i - 1):

            # Swap if the element found is greater than the next element
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        
        # If no two elements were swapped in the inner loop, break early
        if not swapped:
            break

# Example usage
arr = [64, 34, 25, 12, 22, 11, 90]
print("Original array:", arr)

bubble_sort(arr)

print("Sorted array:  ", arr)
