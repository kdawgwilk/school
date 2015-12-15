

class ADT:
    def __init__(self, num_vertices):
        return

    def add_edge(self):
        return

    def breadth_first_search(self):
        path = []
        # Python Deck for Queue
        # q = deque()
        # q.append(item)
        # item = q.popleft()
        #    0   1   2   3   4   5
        # [ -1, -1, -1, -1, -1, -1 ] # Array starts like this
        # [ Array of visited and how we got there ] Current item < Queue >
        # [  0, -1, -1, -1, -1, -1 ] 0 < 0 >
        # [  0,  0, -1,  0, -1, -1 ] 0 < 1, 3 >
        # [  0,  0,  1,  0,  1, -1 ] 1 < 3, 2, 4 >
        return path

    def depth_first_search(self):
        return

    def is_connected(self):
        return

    def has_edge(self):
        return

    def find_adjacent_vertices(self):
        return