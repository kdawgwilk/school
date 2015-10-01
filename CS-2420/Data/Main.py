# Create a class called Student.
# The class should contain all the fields found in the list of students at:
# InsertNames.txt
#
# Write code to read all the data from InsertNames.txt into a python list of student objects.
# Detect any duplicate objects. That is, if a student has the same SSN as a previous student, do not add that student.
# Instead, print an error message.
# Time how long that takes, and have your code print that.
# NOTE of clarification: You should not be changing the input files, or making any output file,
# and you should have only 1 python list in memory.


import time
from Student import Student


def main():
    all_students = []
    fin = open("InsertNames.txt", "rt")
    t1 = time.time()
    for line in fin:
        duplicate = False
        words = line.split()
        s = Student(words[0], words[1], words[2], words[3], words[4])
        for student in all_students:
            if s.get_ssn() == student.get_ssn():
                duplicate = True
        if duplicate:
            print("Duplicate SSN found: %s!!" % s.get_ssn())
        else:
            all_students.append(s)
    t2 = time.time()
    print(t2 - t1)
    return


main()


# /usr/bin/python /Users/kwilkinson/Sources/school/CS-2420/Data/Main.py
# Duplicate SSN found: 001-82-8856!!
# 203.26374197
#
# Process finished with exit code 0