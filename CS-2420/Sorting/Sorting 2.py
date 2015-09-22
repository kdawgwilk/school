# CS-2420 - Assignment - Sorting 2

import random

ARRAY_SIZE = 100
DEBUG = True


def create_random_list(size):
    random_list = []
    for i in range(size):
        random_num = random.randrange(size)
        random_list.append(random_num)
    return random_list


def merge_sort(array):
    length = len(array)
    if length <= 1:
        return
    mid = length // 2
    left_half = array[:mid]
    right_half = array[mid:]

    merge_sort(left_half)
    merge_sort(right_half)

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


def quick_sort_recursive(array, low, high, modified):
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

    quick_sort_recursive(array, low, pivot - 1, modified)
    quick_sort_recursive(array, pivot + 1, high, modified)
    return


def quick_sort(array):
    quick_sort_recursive(array, 0, len(array) - 1, False)
    return


def mod_quick_sort(array):
    quick_sort_recursive(array, 0, len(array) - 1, True)
    return


def hash_sort(array):
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


def main():
    main_list = create_random_list(ARRAY_SIZE)
    merge_sort_copy = main_list[:]
    quick_sort_copy = main_list[:]
    mod_quick_sort_copy = main_list[:]
    hash_sort_copy = main_list[:]

    merge_sort(merge_sort_copy)
    quick_sort(quick_sort_copy)
    mod_quick_sort(mod_quick_sort_copy)
    hash_sort(hash_sort_copy)
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
        print("Hash Sorted:")
        print(hash_sort_copy)

    if main_list == merge_sort_copy:
        print("Merge Sort Passed")
    if main_list == quick_sort_copy:
        print("Quick Sort Passed")
    if main_list == mod_quick_sort_copy:
        print("Mod Quick Sort Passed")
    if main_list == hash_sort_copy:
        print("Hash Sort Passed")
    return

main()
