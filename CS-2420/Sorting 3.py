# CS-2420 - Assignment - Sorting 3

# Measure all 7 sorting algorithms by counting the number of compares and the number of swaps.
# Test on data ranging from size 8 to size 4k, by powers of 2.
# Test on random data and on mostly sorted data.
# (Make a new function to create mostly sorted data. Have it first call the MakeRandomData function,
#   have Python sort it, then swap the first and last elements.)
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

# Click on the link below for help preparing 1 of your 4 spreadsheets using Excel.
# Comparisons on Random Data
#
# NOTE: Do NOT use global variables!

# Chart needs these labels and values
# Compares (Unit = log2N)
# N = 3, 4, 5...12 (Unit = log2N)

import random
import sys
import Sorter

ARRAY_SIZE = 100
DEBUG = True


def main():
    starting_size = 8
    ending_size = 1024 * 4
    sys.setrecursionlimit(ending_size + 10)
    return


main()
