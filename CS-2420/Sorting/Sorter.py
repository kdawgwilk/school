
import random


class Sorter:
    def __init__(self, size=100, unique=False, debug=False):
        self.size = size
        self.unique = unique
        self.DEBUG = debug
        self.array = []
        self.sorted_array = []

        if self.unique:
            self.create_random_unique_list()
        else:
            self.create_random_list()
        return

    def create_random_list(self):
        del self.array[:]
        for i in range(self.size):
            random_num = random.randrange(self.size)
            self.array.append(random_num)
        return

    def create_random_unique_list(self):
        del self.array[:]
        for i in range(self.size):
            self.array.append(i)
        for i in range(self.size):
            j = random.randrange(self.size)
            self.array[i], self.array[j] = self.array[j], self.array[i]
        return

    def is_sorted(self):
        if self.array == self.sorted_array:
            class_name = self.__class__.__name__()
            print("%s Sort Passed" % class_name)
        return


