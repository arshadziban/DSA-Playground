def selection_sort():
    # Take user input
    user_input = input("Enter numbers separated by spaces: ")
    arr = list(map(int, user_input.split()))
    print("Unsorted array:", arr)
    
    # Traverse through all array elements
    for i in range(len(arr)):
        # Find the minimum element in remaining unsorted array
        min= i
        for j in range(i+1, len(arr)):
            if arr[min] > arr[j]:
                min = j
        
        # Swap the found minimum element with the first element
        arr[i], arr[min] = arr[min], arr[i]
    
    # Print the sorted array
    print("Sorted array:", arr)

# Call the function
selection_sort()
