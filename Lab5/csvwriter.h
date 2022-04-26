#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <QString>

#include <fstream>
#include <vector>

#include "university_man.h"

class CSVWriter
{
private:
	std::ofstream fout;

public:
    CSVWriter(const QString &file_name);
	CSVWriter(const CSVWriter&) = delete;
	CSVWriter(CSVWriter&& other);
	~CSVWriter();

    CSVWriter& operator=(const CSVWriter&) = delete;
    CSVWriter operator=(CSVWriter&& other);

	bool isOpen() const { return fout.is_open(); };
	void write(const std::vector<UniversityMan> &employees);
};

#endif // CSVWRITER_H
