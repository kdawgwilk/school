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


def merge_sort(array):
    if len(array) <= 1:
        return
    m1 = array[]  # Slice array and return first half
    m2 = array[]  # Slice array and return second half
    merge_sort(m1)
    merge_sort(m2)
    # merge m1, m2
    m1i = 0
    m2i = 0
    arrayi = 0
    while array.len >= arrayi:
        if m1[m1i] <= m2[m2i]:
            array[]
    return


def quick_sort_recursive(array, low, high):
    if high - low <= 0: # abs(high - low) <= 0:
        return
    # do 1 pass
    pivot = 0

    quick_sort_recursive(array, low, pivot - 1)
    quick_sort_recursive(array, pivot + 1, high)


def quick_sort(array):
    quick_sort_recursive(array, 0, len(array) - 1)

def mod_quick_sort(array):
    length = len(array)


def main():
    main_list = create_random_list(ARRAY_SIZE)
    merge_sort_copy = main_list[:]
    quick_sort_copy = main_list[:]
    mod_quick_sort_copy = main_list[:]

    merge_sort(merge_sort_copy)
    quick_sort(quick_sort_copy)
    mod_quick_sort(mod_quick_sort_copy)
    main_list.sort()

    if DEBUG:
        print("Python Sorted:")
        print(main_list)
        print("Merge Sorted:")
        print(merge_sort_copy)
        print("Quick Sorted:")
        print(quick_sort_copy)
        print("Mod Quick Sorted:")
        print(mod_quick_sort_copy)

    if main_list == merge_sort_copy:
        print("Merge Sort Passed")
    if main_list == quick_sort_copy:
        print("Quick Sort Passed")
    if main_list == mod_quick_sort_copy:
        print("Mod Quick Sort Passed")

main()
