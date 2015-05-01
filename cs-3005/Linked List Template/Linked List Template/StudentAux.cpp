
#include "StudentAux.h"


int ReadStudentFile(const std::string &filename, StudentLinkedList &students)
{
    int c = 0;
    std::ifstream fin(filename);
    bool exists;
    
    if(!fin)
    {
        std::cerr << "Could not open " << filename << std::endl;
    }
    while(fin)
    {
        if(fin)
        {
            Student *student = new Student();
            fin >> *student;
            //            std::cout << *student << "\n";
            exists = students.Insert(*student);
            if (!exists) {
                //                std::cout << "Exists" <<"\n";
                c++;
            }
        }
    }
    fin.close();
    //    std::cout << "Value of C: " << c << "\n";
    return c;
}

int RemoveStudents(const std::string &filename, StudentLinkedList &students)
{
    int c = 0;
    std::ifstream fin(filename);
    bool exists;
    
    if(!fin)
    {
        std::cerr << "Could not open " << filename << std::endl;
    }
    while(fin)
    {
        if(fin)
        {
            char social[12];
            fin >> social;
            Student *student = new Student();
            student->setSsn(social);
            exists = students.Delete(*student);
            if (!exists) {
                c++;
            }
            delete student;
        }
    }
    fin.close();
    //    std::cout << "Value of C: " << c << "\n";
    c--;
    return c;
}

double AverageAgeStudents(const std::string &filename, StudentLinkedList &students)
{
    double avg;
    double c = 0;
    double total = 0;
    std::ifstream fin(filename);
    
    if(!fin)
    {
        std::cerr << "Could not open " << filename << std::endl;
    }
    while(fin)
    {
        if(fin)
        {
            char social[12];
            fin >> social;
            Student *student = new Student();
            student->setSsn(social);
            Student rstudent = students.Retrieve(*student);
            if (rstudent.getAge() != 0) {
                total += rstudent.getAge();
                c++;
            }
            delete student;
        }
    }
    fin.close();
    std::cout << "Value of C: " << c << "\n";
    std::cout << "Value of total: " << total << "\n";
    avg = total / c;
    std::cout << "Value of avg: " << avg << "\n";
    return avg;
}