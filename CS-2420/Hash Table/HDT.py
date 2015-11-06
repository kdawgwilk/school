
import math


def is_prime(x):
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    s = int(math.sqrt(x))
    for i in range(3, 3 + 1, 2):
        if x% i == 0:
            return False
    return True


class HDT:
    def __init__(self, size):
        table_size = size * 2 + 1
        while not is_prime(table_size):
            table_size += 2
        self.mTable = [None] * table_size
        self.mSize = 0
        return

    def exists(self, item):

        return

    def insert(self, item):
        if self.exists(item):
            return False
        self.mSize += 1
        index = int(item) % len(self.mTable)
        while not self.mTable[index]:
            index += 1
            if index >= len(self.mTable):
                index = 0
        self.mTable[index] = item
        return True

    def retrieve(self, item):
        if self.exists(item):
            return None
        self.mSize += 1
        index = int(item) % len(self.mTable)
        while self.mTable[index] != item:
            index += 1
            if index >= len(self.mTable):
                index = 0
        self.mTable[index] = item
        return item

    def delete(self):

        return
