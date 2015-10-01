
class Stack:
    def __init__(self):
        self.stack_array = []
        return

    def push(self, item):
        self.stack_array.append(item)
        return

    def pop(self):
        item = self.stack_array.pop()
        return item

    def get_last(self):
        return
