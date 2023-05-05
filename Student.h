#ifndef SDDS_STUDENTS_H_
#define SDDS_STUDENTS_H_

#define DATAFILE "simpsons.csv"

namespace sdds {

    struct Student {
        char* m_name;
        int m_studentNumber;
        char m_grade;
    };

    void sort();

    bool load(Student& st);

    bool load(const char[]);

    void display(const Student& student);

    void display();

    void deallocateMemory();
}
#endif 