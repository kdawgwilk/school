
from Sorter import Sorter


class Quick(Sorter):
    def __init__(self, size=100, debug=False, unique=False):
        Sorter.__init__(self, size, debug, unique)
        self.modified = False
        return

    def sort(self):
        self.sort_recursive(self.array, 0, self.size - 1)

    def sort_recursive(self, array, low, high):
        if high - low <= 0:  # abs(high - low) <= 0:
            return
        if self.modified:
            middle = (low + high) / 2
            self.swaps += 1
            array[low], array[middle] = array[middle], array[low]
        pivot = low
        left_big = low + 1
        for i in range(low + 1, high + 1):
            self.compares += 1
            if array[i] < array[pivot]:
                self.swaps += 1
                array[i], array[left_big] = array[left_big], array[i]
                left_big += 1
        pivot = left_big - 1
        self.swaps += 1
        array[low], array[pivot] = array[pivot], array[low]

        self.sort_recursive(array, low, pivot - 1)
        self.sort_recursive(array, pivot + 1, high)
        return

    def is_modified(self):
        # print(self.modified)
        return self.modified
