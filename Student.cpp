#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"
#include "File.h"
#include <cstring>

using namespace std;

namespace sdds
{
    int noOfStudents;

    Student* students;

    void sort() {
        int i, j;
        Student temp;
        for (i = noOfStudents - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (students[j].m_grade > students[j + 1].m_grade) {
                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
    }


    bool load(Student& st)
    {
        bool yes = false;
        char name[128];



        if (read(name)) {

            int nlenght = strlen(name);
            st.m_name = new char[nlenght + 1];

            strcpy(st.m_name, name);

            yes = read(st.m_studentNumber);
            read(st.m_grade);

            if (yes)
            {
                yes = true;
            }
        }
        return yes;
    }


    bool load(const char[13])
    {
        bool yes = false;
        int nlenght = 0;
        if (openFile(DATAFILE))
        {

            noOfStudents = noOfRecords();

            students = new Student[noOfStudents];

            for (int i = 0; i < noOfStudents; i++)
            {
                load(students[i]);
                nlenght++;
            }

            if (nlenght != noOfStudents)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
            }
            else
            {
                yes = true;
            }

            closeFile();
        }

        else
        {
            cout << "Data file" << DATAFILE << "not found!" << endl;
        }

        return yes;
    }

    void display(const Student& student)
    {
        cout << student.m_name << ", " << student.m_studentNumber << ": " << student.m_grade << endl;
    }

    void display()
    {
        sort();
        for (int i = 0; i < noOfStudents; i++)
        {
            cout << i + 1 << ": ";
            display(students[i]);
        }
    }

    void deallocateMemory()
    {
        for (int i = 0; i < noOfStudents; i++)
        {
            delete[] students[i].m_name;
        }
        delete[] students;
    }
}