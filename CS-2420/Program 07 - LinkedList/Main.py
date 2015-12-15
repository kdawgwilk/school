# Create a container class for storing unordered unique Students.
# It should support the methods: Exists, Insert, Traverse, Delete, Retrieve, and Size.
# Implement the methods using a Program 07 - LinkedList.
# Repeat the previous assignment using your new Program 07 - LinkedList container class,
# and compare the Insert, Traverse, Delete, and Retrieve times to the pythonList.
# Verify that the average ages and the error messages are the same.
# Note that your main function should be much simpler than it was when you used a python list,
# because your Program 07 - LinkedList class automatically enforces uniqueness.

# NOTE: You many want to create smaller versions of the Insert, Delete, and Retrieve lists that have, say,
# only 10 or 20 items.

from Student import Student
from UUC import UUC

total_ages = 0


def add_ages(student):
    global total_ages
    total_ages += student.get_age()
    return


def main():
    global total_ages
    all_students = UUC()
    fin = open("../txts/InsertNames.txt", "rt")
    print "============= Start Insert ============="
    for line in fin:
        words = line.split()
        student = Student(words[2], words[0], words[1], words[3], int(words[4]))
        inserted = all_students.insert(student)
        if not inserted:
            print "Duplicate SSN found: %s!!" % student.get_ssn()
    print "============== End Insert =============="
    fin.close()

    print "========== Start Average Age ==========="
    all_students.traverse(add_ages)
    print "Average age is %s" % (float(total_ages) / float(all_students.size()))
    print "=========== End Average Age ============"

    fin = open("../txts/DeleteNames.txt", "rt")
    print "============= Start Delete ============="
    for line in fin:
        words = line.split()
        student = Student(words[0])
        deleted = all_students.delete(student)
        if not deleted:
            print "Student with SSN: %s didn't exist!!" % student.get_ssn()
    print "============== End Delete =============="
    fin.close()

    total_ages = 0

    fin = open("../txts/RetrieveNames.txt", "rt")
    print "====== Start Retrieved Average Age ======"
    for line in fin:
        words = line.split()
        student = Student(words[0])
        found = all_students.retrieve(student)
        if found:
            add_ages(found)
        else:
            print "Student with SSN: %s didn't exist!!" % student.get_ssn()
    print "======= End Retrieved Average Age ======="
    fin.close()

    return

main()

