
from Sorter import Sorter


class Selection(Sorter):
    def __init__(self, size=100, debug=False, unique=False):
        Sorter.__init__(self, size, debug, unique)

        return

    def sort(self):
        length = len(self.array)
        for i in range(length):
            smallest_index = i
            for j in range(i, length):  # range(i + 1, length):
                self.compares += 1
                if self.array[smallest_index] > self.array[j]:
                    smallest_index = j
            self.swaps += 1
            self.array[i], self.array[smallest_index] = self.array[smallest_index], self.array[i]
