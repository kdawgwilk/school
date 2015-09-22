# CS-2420 - Assignment - Sorting 2

from Merge import Merge
from Quick import Quick
from Hash import Hash


SIZE = 100
DEBUG = True


def main(size, debug):

    merge = Merge(size, debug)
    merge.sort()
    merge.is_sorted()

    quick = Quick(size, debug)
    quick.sort()
    quick.is_sorted()

    mod_quick = Quick(size, debug, True)
    mod_quick.sort()
    mod_quick.is_sorted()

    hashed = Hash(size, debug)
    hashed.sort()
    hashed.is_sorted()


main(SIZE, DEBUG)
