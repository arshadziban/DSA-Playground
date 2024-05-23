def partition(arr, low, high):
  pivot = arr[high]
  i = low - 1

  for j in range(low, high):
    if arr[j] <= pivot:
      i += 1
      arr[i], arr[j] = arr[j], arr[i]

  arr[i + 1], arr[high] = arr[high], arr[i + 1]
  return i + 1

def quick_sort(arr, low, high):

  if low < high:
    # pi is partitioning index, arr[pi] is now at its sorted position
    pi = partition(arr, low, high)

    # Recursively sort elements before and after partition
    quick_sort(arr, low, pi - 1)
    quick_sort(arr, pi + 1, high)

# Get user input
arr = list(map(int, input("Enter the list of numbers separated by space: ").split()))

# Sort the array
quick_sort(arr, 0, len(arr) - 1)

# Print the sorted array
print("Sorted array:", arr)
