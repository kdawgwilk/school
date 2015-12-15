
class Node:
    def __init__(self, item, next_item):
        self.mItem = item
        self.mNext = next_item
        return


class UUC:
    def __init__(self):
        self.mFirst = None
        self.mCount = 0
        return

    def exists(self, item):  # dummy item with only the key
        # override == operator
        current_item = self.mFirst
        while current_item:
            if current_item.mItem == item:
                return True
            else:
                current_item = current_item.mNext
        return False

    def insert(self, item):
        if self.exists(item):
            return False
        n = Node(item, self.mFirst)
        self.mFirst = n
        self.mCount += 1
        return True

    def delete(self, item):
        if not self.exists(item):
            return False
        current = self.mFirst
        prev = None
        while current.mItem != item:
            prev = current
            current = current.mNext
        prev.mNext = current.mNext
        self.mCount -= 1
        return True

    def retrieve(self, item):  # dummy item with only the key
        current_item = self.mFirst
        while current_item:
            if current_item.mItem == item:
                return current_item.mItem
            else:
                current_item = current_item.mNext
        return None

    def size(self):
        return self.mCount

    def traverse(self, callback):
        current = self.mFirst
        while current:
            callback(current.mItem)
            current = current.mNext
        return
