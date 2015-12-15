
class Stack:
    def __init__(self):
        self.stack_array = []
        self.length = 0
        return

    def push(self, item):
        self.stack_array.append(item)
        self.length += 1
        return

    def pop(self):
        if self.empty():
            print("List is empty")
        item = self.top()
        self.stack_array = self.stack_array[:self.length - 1]
        self.length -= 1
        return item

    def top(self):
        if self.empty():
            print("List is empty")
        return self.stack_array[self.length - 1]

    def empty(self):
        if self.length > 0:
            return False
        return True
