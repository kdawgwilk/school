# CS-2420 - Assignment - Sorting 3

# Measure all 7 sorting algorithms by counting the number of compares and the number of swaps.
# Test on data ranging from size 8 to size 4k, by powers of 2.
# Test on random data and on mostly sorted data.
# Print all this data in organized tables, that you can then copy into Excel spreadsheets for making charts.
# You will need to create four data sets, with 1 Excel chart for each.
# The first data set and chart should plot Problem Size versus number of Compares when using Random data.
# The second data set and chart should plot Problem Size versus number of Swaps when using Random data.
# The third and forth charts should be the same as the first two, except using Mostly Sorted data instead of
# Random data.

# To pass off, show me the 4 spreadsheet plots that illustrate swaps and compares for random and mostly sorted data,
#   in all 4 combinations. Be prepared to explain what they mean.

# It is important to make the charts Log/Log. That is, modify your python code to print the Log of the Problem Size and
#   the Log of the number of Comparisons or Swaps. Otherwise it will be really hard to see and interpret the results.
# Also, make an effort to organize your python code to reduce repeating code as much as possible.

# Chart needs these labels and values
# Compares (Unit = log2Compares)
# N = 3, 4, 5...12 (Unit = log2N)


import sys
import math


# NOTE: Do NOT use global variables!
# Is this ok?
DEBUG = False

from Bubble import Bubble
from Shaker import Shaker
from Selection import Selection
from Merge import Merge
from Quick import Quick
from ModQuick import ModQuick
from Hash import Hash


def main(debug):
    # fout = open("data.csv", "wt")
    # fout.write(str(i) + name + "\n"")
    # fout.close()
    starting_size = 8
    ending_size = 1024 * 4
    sys.setrecursionlimit(ending_size + 10)
    sort_types = ["Bubble", "Shaker", "Selection", "Merge", "Quick", "ModQuick", "Hash"]

    for i in range(4):
        print("========================================")
        data = 0
        mostly_sorted = False
        if i == 0:
            print("Compares with Random Data")
        elif i == 1:
            print("Compares with Mostly Sorted Data")
            mostly_sorted = True
        elif i == 2:
            print("Swaps with Random Data")
            data = 1
        else:
            print("Swaps with Mostly Sorted Data")
            mostly_sorted = True
            data = 1
        print("========================================")
        size = starting_size
        print(""),
        for j in range(len(sort_types)):
            print(sort_types[j]),
        print("")
        while size <= ending_size:
            print int(math.log(size, 2)),
            for k in range(len(sort_types)):
                sort_type = eval("%s(size, debug, %s)" % (sort_types[k], mostly_sorted))
                sort_type.sort()
                sort_type.print_data(data)

            print("")
            size *= 2


main(DEBUG)
