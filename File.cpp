/*#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    bool read(char name[])
    {
        return fscanf(fptr, "%[^,],", name) == 1;
    }
    bool read(int& sNo)
    {
        return fscanf(fptr, "%d,", sNo) == 1;
    }
    bool read(char& g)
    {
        return fscanf(fptr, "%c\n", g) == 1;
    }

}*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {

    FILE* fptr;

    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool read(char* name)
    {
        return fscanf(fptr, "%[^,],", name) == 1;
    }

    bool read(int& m_number)
    {
        return fscanf(fptr, "%d,", &m_number) == 1;
    }

    bool read(char& m_grade)
    {
        return fscanf(fptr, "%c\n", &m_grade) == 1;

    }
}