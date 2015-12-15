
import random
import math
import numpy as np


class Sorter:
    def __init__(self, size=100, debug=False, mostly_sorted=False):
        self.size = size
        self.DEBUG = debug
        self.array = []
        self.sorted_array = []

        self.compares = 0
        self.swaps = 0

        if mostly_sorted:
            self.mostly_sorted_list()
        else:
            self.random_list()
        self.sorted_array = self.array[:]
        self.sorted_array.sort()
        return

    def random_list(self):
        # self.array = [4, 7, 5, 2, 10, 3, 8, 1, 6, 9]
        # return
        del self.array[:]
        for i in range(self.size):
            random_num = random.randrange(self.size)
            self.array.append(random_num)
        return

    def random_unique_list(self):
        del self.array[:]
        for i in range(self.size):
            self.array.append(i)
        for i in range(self.size):
            j = random.randrange(self.size)
            self.array[i], self.array[j] = self.array[j], self.array[i]
        return

    def mostly_sorted_list(self):
        del self.array[:]
        self.random_list()
        self.array.sort()
        self.array[0], self.array[self.size - 1] = self.array[self.size - 1], self.array[0]
        return

    def sort(self):
        class_name = self.__class__.__name__
        print("Sort method for %s Sort not implemented!" % class_name)

    def print_list(self):
        print(self.array)
        return

    def print_data(self, i):
        # x = "%5.2f" % x
        precision = 2
        if i == 0:
            if self.compares > 0:
                print np.round(math.log(self.compares, 2), precision),
            else:
                print(0),
        else:
            if self.swaps > 0:
                print np.round(math.log(self.swaps, 2), precision),
            else:
                print(0),
        return

    def is_sorted(self):
        if self.array == self.sorted_array:
            class_name = self.__class__.__name__
            if self.DEBUG:
                print("%s Sort Passed" % class_name)
            return True
        return False


