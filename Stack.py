maxTop = 6
stack = [0] * maxTop
top = -1
def push(data):
    global top
    if top == maxTop - 1:
        print("Overflow")
    else:
        top += 1
        stack[top] = data

def pop():
    global top
    if top == -1:
        print("Underflow")
    else:
        print("Popped:", stack[top])
        top -= 1

def show():
    if top == -1:
        print("No item to show")
    else:
        print("Stack :", end=" ")
        for i in range(top, -1, -1):
            print(stack[i], end=" ")
        print()

while True:
    print("\n1. push\n2. pop\n3. show")
    op = int(input("Enter your choice: "))

    if op == 1:
        item = int(input("Enter item to push: "))
        push(item)
    elif op == 2:
        pop()
    elif op == 3:
        show()
    else:
        print("Invalid Choice")
