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


total_ages = 0


def add_ages(student):
    global total_ages
    total_ages += student.get_age()
    return


def insert_students_from_file(students, fin):
    t1 = time.time()
    for line in fin:
        duplicate = False
        words = line.split()
        s = Student(words[2], words[0], words[1], words[3], int(words[4]))
        for student in students:
            if s.get_ssn() == student.get_ssn():
                duplicate = True
        if duplicate:
            print "Duplicate SSN found: %s!!" % s.get_ssn()
        else:
            students.append(s)
    t2 = time.time()
    print "Insert time:", (t2 - t1)


def average_student_age(students, callback):
    global total_ages
    t1 = time.time()
    for student in students:
        callback(student)
    average = float(total_ages) / float(len(students))
    t2 = time.time()
    print "Average age:", average
    print "Average age time:", (t2 - t1)


def delete_students_from_file(students, fin):
    t1 = time.time()
    for line in fin:
        found = False
        words = line.split()
        s = Student(words[0])
        for student in students:
            if s.get_ssn() == student.get_ssn():
                found = True
                del student
        if not found:
            print "Student with SSN: %s didn't exist!!" % s.get_ssn()
    t2 = time.time()
    print "Delete time:", (t2 - t1)


def average_retrieved_age(students, fin, callback):
    t1 = time.time()
    count = 0
    for line in fin:
        found = False
        words = line.split()
        s = Student(words[0])
        for student in students:
            if s.get_ssn() == student.get_ssn():
                found = True
                count += 1
                callback(student)
        if not found:
            print "Student with SSN: %s didn't exist!!" % s.get_ssn()
    average = float(total_ages) / float(count)
    t2 = time.time()
    print "Average retrieved age:", average
    print "Average retrieved time:", (t2 - t1)


def main():
    global total_ages
    all_students = []
    fin = open("../txts/InsertNames.txt", "rt")
    print "============= Start Insert ============="
    insert_students_from_file(all_students, fin)
    print "============== End Insert =============="
    fin.close()

    print "========== Start Average Age ==========="
    average_student_age(all_students, add_ages)
    print "=========== End Average Age ============"

    fin = open("../txts/DeleteNames.txt", "rt")
    print "============= Start Delete ============="
    delete_students_from_file(all_students, fin)
    print "============== End Delete =============="
    fin.close()

    total_ages = 0

    fin = open("../txts/RetrieveNames.txt", "rt")
    print "====== Start Retrieved Average Age ======"
    average_retrieved_age(all_students, fin, add_ages)
    print "======= End Retrieved Average Age ======="
    fin.close()

    return


main()


# "/Users/kwilkinson/Sources/school/CS-2420/Program 05 - DeleteRetrieve/Main.py"
# ============= Start Insert =============
# Duplicate SSN found: 001-82-8856!!
# Insert time: 125.497006893
# ============== End Insert ==============
# ========== Start Average Age ===========
# Average age: 42.9299309977
# Average age time: 0.00694012641907
# =========== End Average Age ============
# ============= Start Delete =============
# Student with SSN: 010-16-5079 didn't exist!!
# Delete time: 83.2975549698
# ============== End Delete ==============
# ====== Start Retrieved Average Age ======
# Student with SSN: 015-15-2536 didn't exist!!
# Student with SSN: 998-14-3873 didn't exist!!
# Average retrieved age: 49.5376141326
# Average retrieved time: 85.3650279045
# ======= End Retrieved Average Age =======
#
# Process finished with exit code 0
