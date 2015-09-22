# CS-2420 - Assignment - Sorting 1

from Bubble import Bubble
from Shaker import Shaker
from Selection import Selection

SIZE = 1000
DEBUG = True


def main(size, debug):

    bubble = Bubble(size, debug)
    bubble.sort()
    bubble.is_sorted()

    shaker = Shaker(size, debug)
    shaker.sort()
    shaker.is_sorted()

    selection = Selection(size, debug)
    selection.sort()
    selection.is_sorted()

main(SIZE, DEBUG)
