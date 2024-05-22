import random
array = []
for i in range(10):
 array.append(random.randint(1, 100))
print(array)
for i in range(len(array)):
   for j in range(0, len(array)-1):
            if array[j] > array[j + 1]:
                temp = array[j]
                array[j] = array[j + 1]
                array[j + 1] = temp
print(array)