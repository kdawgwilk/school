
from Sorter import Sorter


class Merge(Sorter):
    def __init__(self, size=100, debug=False, unique=False):
        Sorter.__init__(self, size, debug, unique)

        return

    def sort(self):
        self.sort_recursive(self.array)

    def sort_recursive(self, array):
        length = len(array)
        self.compares += 1
        if length <= 1:
            return
        mid = length // 2
        left_half = array[:mid]
        right_half = array[mid:]
        self.swaps += length

        self.sort_recursive(left_half)
        self.sort_recursive(right_half)

        i = 0
        j = 0
        k = 0
        length_left_half = len(left_half)
        length_right_half = len(right_half)
        while i < length_left_half and j < length_right_half:
            self.compares += 1  # += 2
            if left_half[i] < right_half[j]:
                self.swaps += 1
                array[k] = left_half[i]
                i += 1
            else:
                self.swaps += 1
                array[k] = right_half[j]
                j += 1
            k += 1
        while i < length_left_half:
            self.compares += 1
            self.swaps += 1
            array[k] = left_half[i]
            i += 1
            k += 1
        while j < length_right_half:
            self.compares += 1
            self.swaps += 1
            array[k] = right_half[j]
            j += 1
            k += 1
        self.swaps /= 3

