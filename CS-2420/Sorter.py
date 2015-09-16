
import random


class Sorter:
    def __init__(self, size=100, unique=False, debug=False):
        self.size = size
        self.unique = unique
        self.DEBUG = debug

        return

    def create_random_list(self, size):
        random_list = []
        for i in range(size):
            random_num = random.randrange(size)
            random_list.append(random_num)
        return random_list

    def create_random_unique_list(self, size):
        unique_list = []
        for i in range(size):
            unique_list.append(i)
        for i in range(size):
            j = random.randrange(size)
            unique_list[i], unique_list[j] = unique_list[j], unique_list[i]
        return unique_list

    def bubble_sort(self, array, counts):
        length = len(array)
        flag = True
        while flag:
            flag = False
            for i in range(length - 1):
                counts[0] += 1
                if array[i] > array[i + 1]:
                    array[i], array[i + 1] = array[i + 1], array[i]
                    flag = True
                    counts[1] += 1
            length -= 1

    def shaker_sort(self, array, counts):
        # start = 0
        # stop = len(A) - 1
        length = len(array) - 1
        flag = True
        while flag:
            flag = False
            for i in range(length):  # (start, stop)
                if array[i] > array[i + 1]:
                    array[i], array[i + 1] = array[i + 1], array[i]
                    flag = True
            if not flag:
                break
            # stop -= 1
            # flag = False
            for i in range(length - 1, -1, -1):  # (stop, start - 1, -1)
                if array[i] > array[i + 1]:
                    array[i], array[i + 1] = array[i + 1], array[i]
                    flag = True
            length -= 1
            # start += 1

    def selection_sort(self, array, counts):
        length = len(array)
        for i in range(length):
            smallest_index = i
            for j in range(i, length):  # range(i + 1, length):
                if array[smallest_index] > array[j]:
                    smallest_index = j
            array[i], array[smallest_index] = array[smallest_index], array[i]

    def merge_sort(self, array, counts):
        length = len(array)
        if length <= 1:
            return
        mid = length // 2
        left_half = array[:mid]
        right_half = array[mid:]

        self.merge_sort(left_half, counts)
        self.merge_sort(right_half, counts)

        i = 0
        j = 0
        k = 0
        length_left_half = len(left_half)
        length_right_half = len(right_half)
        while i < length_left_half and j < length_right_half:
            if left_half[i] < right_half[j]:
                array[k] = left_half[i]
                i += 1
            else:
                array[k] = right_half[j]
                j += 1
            k += 1

        while i < length_left_half:
            array[k] = left_half[i]
            i += 1
            k += 1

        while j < length_right_half:
            array[k] = right_half[j]
            j += 1
            k += 1

    def quick_sort_recursive(self, array, low, high, modified, counts):
        if high - low <= 0:  # abs(high - low) <= 0:
            return
        if modified:
            middle = (low + high) / 2
            array[low], array[middle] = array[middle], array[low]
        pivot = low
        left_big = low + 1
        for i in range(low + 1, high + 1):
            if array[i] < array[pivot]:
                array[i], array[left_big] = array[left_big], array[i]
                left_big += 1
        pivot = left_big - 1
        array[low], array[pivot] = array[pivot], array[low]

        self.quick_sort_recursive(array, low, pivot - 1, modified, counts)
        self.quick_sort_recursive(array, pivot + 1, high, modified, counts)
        return

    def quick_sort(self, array, counts):
        self.quick_sort_recursive(array, 0, len(array) - 1, False, counts)
        return

    def mod_quick_sort(self, array, counts):
        self.quick_sort_recursive(array, 0, len(array) - 1, True, counts)
        return

    def hash_sort(self, array, counts):
        length = len(array)
        frequency_array = [0] * length
        for i in range(length):
            frequency_array[array[i]] += 1

        k = 0
        for i in range(length):
            number = frequency_array[i]
            for j in range(number):
                array[k] = i
                k += 1

        return
