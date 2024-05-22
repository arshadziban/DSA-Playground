import random
def insertionSort():
    array = []
    for i in range(10):
        array.append(random.randint(100,1000))
    print("Random Array:",array)

    for i in range (1,len(array)):
        key= array[i]
        j=i-1
        while j>=0 and key< array[j]:
           array[j+1]=array[j]
           j-=1 
        array[j+1]=key
    print("Sorted Array;",array)

insertionSort()
    