
ARRAY_SIZE = 1000

# A = [20, 14, 13, 27, 84]

def create_random_list(size):
    random_list = []
    for i in range(size):
        random_num = random.randrange(size)
        random_list.append(random_num)
    return random_list

# Return index
def FindSmallestIndex(A):
	smallest_index = 0
	for i in range(len(A)):
		if A[i] < A[smallest_index]:
			smallest_index = i
	return smallest_index


# Find the item and return the index or -1 if not found
def FindItem(A, num):
	for i in range(len(A)):
		if A[i] == num:
			return i
	return -1



def main():
	A = create_random_list(ARRAY_SIZE)



main()