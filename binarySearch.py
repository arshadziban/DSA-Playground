import random
array = []
for i in range(10):
  array.append(random.randint(1, 100))
array.sort()
print(array)
target=int(input("Enter the number: "))
low= 0
high=len(array)-1
mid=(low+high)//2
while low <= high:
        if array[mid] == target:
            print("Index:",mid)
            exit()
        elif array[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
print("ITEM is not found")
array += [target]
array.sort()
print(array)
    