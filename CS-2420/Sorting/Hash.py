
from Sorter import Sorter


class Hash(Sorter):
    def __init__(self, size=100, debug=False, unique=False):
        Sorter.__init__(self, size, debug, unique)

        return

    def sort(self):
        length = len(self.array)
        frequency_array = [0] * length
        for i in range(length):
            self.swaps += 1  # Not sure if this is even right
            self.compares += 1
            frequency_array[self.array[i]] += 1
        k = 0
        for i in range(length):
            number = frequency_array[i]
            for j in range(number):
                self.array[k] = i
                k += 1
        return


