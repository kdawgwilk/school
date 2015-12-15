# Create a container class for storing unordered unique Students.
# It should support the methods: Exists, Insert, Traverse, Delete, Retrieve, and Size.
# Implement the methods using a Program 7 - LinkedList.
# Repeat the previous assignment using your new Program 7 - LinkedList container class,
# and compare the Insert, Traverse, Delete, and Retrieve times to the pythonList.
# Verify that the average ages and the error messages are the same.
# Note that your main function should be much simpler than it was when you used a python list,
# because your Program 7 - LinkedList class automatically enforces uniqueness.

# NOTE: You many want to create smaller versions of the Insert, Delete, and Retrieve lists that have, say,
# only 10 or 20 items.

from Student import Student

from Data.UUC import UUC

total_ages = 0


def add_ages(item):
    global total_ages
    total_ages += item.get_age()
    return


def main():
    all_students = UUC()
    fin = open("InsertNames.txt", "rt")
    for line in fin:
        words = line.split()
        student = Student(words[0], words[1], words[2], words[3], words[4])
        all_students.insert(student)
    # Traverse
    # total_ages = 0
    all_students.traverse(add_ages)
    print("Average age is %s" % float(total_ages / all_students.size()))
    return

main()