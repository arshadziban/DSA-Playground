from queue import Queue

queue = Queue()

def enqueue(val):
    queue.put(val)

def dequeue():
    if queue.qsize() == 0:
        print("Queue Underflow")
    else:
        print("The dequeued element is", queue.get())

def display():
    if queue.qsize() == 0:
        print("Queue is empty")
    else:
        print("Queue elements are:", end=" ")
        for item in list(queue.queue):
            print(item, end=" ")
        print()

while True:
    print("1) Enqueue in queue")
    print("2) Dequeue from queue")
    print("3) Display queue")
    print("4) Exit")

    choice = int(input("Enter choice: "))

    if choice == 1:
        val = int(input("Enter value to be enqueued: "))
        enqueue(val)
    elif choice == 2:
        dequeue()
    elif choice == 3:
        display()
    elif choice == 4:
        print("Exit")
        break
    else:
        print("Invalid Choice")
