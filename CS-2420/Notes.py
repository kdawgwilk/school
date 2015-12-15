# Big-O
# Categories

# Tractable (Polynomial)

# 1                     : Array Lookup/Hash Tables
# logN                  : Binary Search
# N                     : Hash Sort
# N * logN              : Quick, ModQuick, Merge
# N^2                   : Multiplying, Bubble, Selection
# N^3                   :

# Non Deterministic Polynomials = NP

# 10^(N/2) = 10^sqrt(N) : Factoring
# 2^N                   : Satisfiable Expression (NP-Complete)
# N!                    : Traveling Salesman

# Intractable (Exponential)

# 2^N                   : Towers of Hanoi
# 10^N                  :
# N^N                   :

# Unsolvable

#                       : Halting Problem


# Does P == NP
# Nobody can prove yes or no




# Midterm Test Study
# 1. what is the log2 of this number (130 000 000) = 27
# 2. what is the log4 of 1000 = 5 (4^what = 1000)
# 3. story problem with exponents
# 4. What is Big O analysis                                                                                                             = Categorizing algorithms to show work increase as size increases
# 5. When is Big O analysis not important                                                                                               = When the data really small and we know its going to stay small
# 6. Which Big O category does this code use?
# for N
#   for N
#       for N
#           Do N^2 work
#       for N
#   for N
# for N
#   for N
# Answer = N^5 (Drop Constants
# 7. List 5 Big O Categories and an algorithm that uses it
# 8. Given this set of 8 numbers what will the data look like after 1 pass
# 9. know best, expected, worse case scenario for all algorithms (7 algorithms) could ask about swaps
# 10. If you have inefficient code/bottleneck where should you look first to fix it = Wherever the worst big O is
# 11. What happens to the speed of execution if you make all the code that is
#        NOT the bottleneck code go a 1000 times faster = Nothing
# 12. Why is it more likely that factoring can become P over SAT = its not NP Complete
# 13. Big table of 7 algorithms
# 14. convert this infix exp to postfix
# 15. given postfix string eval this expression
# 16. write code for bubble sort
# 17. write pop code (could be any code from)






def breadth_first_search(start, to):
    # mNeighbors = [
    #   [1, 3]
    #   [0, 2, 4]
    #   [1, 4]
    #   [0, 4]
    # ]
    # distance = [-1, -1, 0, -1, -1]
    from_array = [-1] * len(mNeighbors) # [-1, -1, 2, -1, -1]
    Q = Queue() # PriorityQueue()
    Q.enque(start) # Q.enque(start, 0)
    from_array[start] = start
    while not Q.empty():
        c = Q.dequeu
        if c == to:
            # build path and return
        for neighbor in mNeighbors: # for all neighbors of c that we havent already visited:
            Q.enque(n)
            from_array[n] = c
    return None

import bsgraph

def main():
    fin = open("graphdata.txt")
    line = fin.readline()
    num_vertices = int(line)
    G = bsgraph.bsgraph(num_vertices)
    num_edges = int(fin.readline())
    for i in range(num_edges):
        line = fin.readline() # "0 1\n"
        words = line.split()
        fromm = int(words[0])
        to = int(words[1])
        G.AddEdge(fromm, to)
    num_tests = int(fin.readline())
    for i in range(num_tests):
        line = fin.readline() # "0 1\n"
        words = line.split()
        fromm = int(words[0])
        to = int(words[1])
        print "Going from", fromm, "to", to
        print G.depth_first_search(fromm, to)
        print G.breadth_first_search(fromm, to)


# Final Test Study








