# CS-2420

import random



def createRandomList(size):
	randomList = []
	for i in range(size):
		randomNum = random.randrange(size)
		randomList.append(randomNum)
	return randomList

def createRandomUniqueList(size):
	# write by next class

def bubbleSort(array):
	length = array.length
	flag = true
	while(flag)
		flag = false
		for i in range(length)
			if array[i] > array[i + 1]:
				tmp = array[i]
				array[i] = array[i + 1]
				array[i + 1] = tmp
				flag = true
		length--

def main()
	A = createRandomList(10)
	Acopy = A[:]
	bubbleSort(A)
	Acopy.sort()
	if A == Acopy:
		print("Passed")