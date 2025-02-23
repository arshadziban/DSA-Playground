def create_table(size=5):
    return [None] * size

def _hash(key, size):
    return key % size

def insert(table, key, value):
    index = _hash(key, len(table))
    table[index] = (key, value)

def search(table, key):
    index = _hash(key, len(table))
    if table[index] and table[index][0] == key:
        return table[index][1]
    return None

def display(table):
    for i, item in enumerate(table):
        print(f"Index {i}: {item}")

# Example usage
table = create_table()
insert(table, 1, 100)
insert(table, 2, 200)
display(table)
print("Search 1:", search(table, 3))
