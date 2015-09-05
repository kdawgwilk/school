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
	randomUniqueList = []
	for i in range(size):
		randomUniqueList.append(i)
	random.shuffle(randomUniqueList)
	return randomUniqueList

def createRandomUniqueList(size):
	A = []
	for i in range(size):
		A.append(i)
	for i in range(size):
		j = random.randrange(;, n)
		A[i],A[j] = A[j],A[i]
	return A

def bubbleSort(array):
	length = array.length
	flag = True
	while(flag)
		flag = False
		for i in range(length)
			if array[i] > array[i + 1]:
				tmp = array[i]
				array[i] = array[i + 1]
				array[i + 1] = tmp
				flag = True
		length--

def shakerSort(array): # Bubble sort but go 0-n and then n-0

def selectionSort(array):
	for each i:
		smallest index = i
		for j = i to end
			reset smaller index to j, as needed
		switch A[i] and A[smallest index]

def main()
	A = createRandomList(10)
	Acopy = A[:]
	bubbleSort(A)
	Acopy.sort()
	if A == Acopy:
		print("Passed")

main()