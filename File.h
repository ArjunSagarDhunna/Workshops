/*
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	bool read(char name[]);
	bool read(int& sNo);
	bool read(char& g);
}
#endif // !SDDS_FILE_H_
*/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {

	bool openFile(const char filename[]);

	void closeFile();

	int noOfRecords();

	bool read(char* name);

	bool read(int& m_number);

	bool read(char& m_grade);

}
#endif
