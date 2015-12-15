
class Node:
    def __init__(self, item):
        self.mItem = item
        self.mLeft = None
        self.mRight = None
        return


class BST:
    def __init__(self):
        self.mRoot = None
        self.mSize = 0
        self.mTrueSize = 0
        return

    def exists(self, item):  # dummy item with only the key
        # override == operator
        # current_item = self.mFirst
        # while current_item:
        #     if current_item.mItem == item:
        #         return True
        #     else:
        #         current_item = current_item.mNext
        return False

    def insert(self, item):
        if self.exists(item):
            return False
        n = Node(item)
        self.mRoot = self.__insert_recursive(n, self.mRoot)
        self.mSize += 1
        return True

    def __insert_recursive(self, node, current):
        if current is None:
            current = node
        elif node.mItem < current.mItem:
            current.mLeft = self.__insert_recursive(node, current.mLeft)
        else:
            current.mRight = self.__insert_recursive(node, current.mRight)
        return current

    def delete(self, item):
        if not self.exists(item):
            return False
        self.mRoot = self.__delete_recursive(item, self.mRoot)
        self.mSize -= 1
        return True

    def __delete_recursive(self, item, current):
        if item < current.mItem:
            current.mLeft = self.__delete_recursive(item, current.mLeft)
        elif item > current.mItem:
            current.mRight = self.__delete_recursive(item, current.mRight)
        else:  # Delete current
            if not current.mLeft and not current.mRight:  # Leaf node/ No children
                current = None
            elif not current.mRight:  # One left child
                current = current.mLeft
            elif not current.mLeft:  # One Right child
                current = current.mRight
            else:  # Two children
                successor = current.mRight
                while successor.mLeft:
                    successor = successor.mLeft
                current.mItem = successor.mItem
                current.mRight = self.__delete_recursive(successor.Item, current.mRight)
        return current

    def retrieve(self, item):  # dummy item with only the key
        # current_item = self.mFirst
        # while current_item:
        #     if current_item.mItem == item:
        #         return current_item.mItem
        #     else:
        #         current_item = current_item.mNext
        return None

    def size(self):
        return self.mSize

    def true_size(self):
        self.mTrueSize = 0
        self.traverse(self.inc_true_size)
        return self.mTrueSize

    def inc_true_size(self, item):
        self.mTrueSize += 1
        return

    def traverse(self, callback):
        self.__traverse_recursive(self.mRoot, callback)
        return

    def __traverse_recursive(self, current, callback):
        if current:
            self.__traverse_recursive(current.mLeft, callback)
            callback(current.mItem)
            self.__traverse_recursive(current.mRight, callback)
        return
