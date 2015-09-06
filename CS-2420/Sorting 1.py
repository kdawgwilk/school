# CS-2420 - Assignment - Sorting 1

import random

ARRAY_SIZE = 1000
DEBUG = False


def create_random_list(size):
    random_list = []
    for i in range(size):
        random_num = random.randrange(size)
        random_list.append(random_num)
    return random_list


def create_random_unique_list(size):
    unique_list = []
    for i in range(size):
        unique_list.append(i)
    for i in range(size):
        j = random.randrange(size)
        unique_list[i], unique_list[j] = unique_list[j], unique_list[i]
    return unique_list


def bubble_sort(array):
    length = len(array)
    flag = True
    while flag:
        flag = False
        for i in range(length - 1):
            if array[i] > array[i + 1]:
                array[i], array[i + 1] = array[i + 1], array[i]
                flag = True
        length -= 1


def shaker_sort(array):
    length = len(array) - 1
    flag = True
    while flag:
        flag = False
        for i in range(length):
            if array[i] > array[i + 1]:
                array[i], array[i + 1] = array[i + 1], array[i]
                flag = True
        if not flag:
            break
        for i in range(length - 1, -1, -1):
            if array[i] > array[i + 1]:
                array[i], array[i + 1] = array[i + 1], array[i]
                flag = True
        length -= 1


def selection_sort(array):
    length = len(array)
    for i in range(length):
        smallest_index = i
        for j in range(i, length):
            if array[smallest_index] > array[j]:
                smallest_index = j
        array[i], array[smallest_index] = array[smallest_index], array[i]


def main():
    main_list = create_random_list(ARRAY_SIZE)
    bubble_sort_copy = main_list[:]
    shaker_sort_copy = main_list[:]
    selection_sort_copy = main_list[:]

    bubble_sort(bubble_sort_copy)
    shaker_sort(shaker_sort_copy)
    selection_sort(selection_sort_copy)
    main_list.sort()

    if DEBUG:
        print("Python Sorted:")
        print(main_list)
        print("Bubble Sorted:")
        print(bubble_sort_copy)
        print("Shaker Sorted:")
        print(shaker_sort_copy)
        print("Selection Sorted:")
        print(selection_sort_copy)

    if main_list == bubble_sort_copy:
        print("Bubble Sort Passed")
    if main_list == shaker_sort_copy:
        print("Shaker Sort Passed")
    if main_list == selection_sort_copy:
        print("Selection Sort Passed")

main()
