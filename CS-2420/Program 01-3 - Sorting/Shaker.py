
from Sorter import Sorter


class Shaker(Sorter):
    def __init__(self, size=100, debug=False, unique=False):
        Sorter.__init__(self, size, debug, unique)

        return

    def sort(self):
        # start = 0
        # stop = len(A) - 1
        length = len(self.array) - 1
        flag = True
        while flag:
            flag = False
            for i in range(length):  # (start, stop)
                self.compares += 1
                if self.array[i] > self.array[i + 1]:
                    self.swaps += 1
                    self.array[i], self.array[i + 1] = self.array[i + 1], self.array[i]
                    flag = True
            if not flag:
                break
            # stop -= 1
            # flag = False
            for i in range(length - 1, -1, -1):  # (stop, start - 1, -1)
                self.compares += 1
                if self.array[i] > self.array[i + 1]:
                    self.swaps += 1
                    self.array[i], self.array[i + 1] = self.array[i + 1], self.array[i]
                    flag = True
            length -= 1
            # start += 1
