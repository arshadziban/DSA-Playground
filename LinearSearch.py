import random
array = []
for i in range(10):
  array.append(random.randint(1, 100))
array.sort()
print(array)
item=int(input("Enter the Item: "))
for i in range(len(array)):
    if (array[i]==item):
       position=array.index(array[i])
       print(f"Element {item} found at position {position}.")
       exit()
print("search is unsuccessful")