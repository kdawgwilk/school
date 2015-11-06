
from Sorter import Sorter


class Bubble(Sorter):
    def __init__(self, size=100, debug=False, unique=False):
        Sorter.__init__(self, size, debug, unique)

        return

    def sort(self):
        # print "Array Before: ", self.array
        length = self.size
        flag = True
        while flag:
            flag = False
            for i in range(length - 1):

                self.compares += 1
                if self.array[i] > self.array[i + 1]:
                    self.array[i], self.array[i + 1] = self.array[i + 1], self.array[i]
                    self.swaps += 1
                    flag = True
            length -= 1
