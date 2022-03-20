#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <fstream>
#include <vector>

#include "employee.h"

class CSVWriter
{
private:
	std::ofstream fout;

public:
	CSVWriter(const std::string &file_name);
	~CSVWriter();

	bool isOpen() const { return fout.is_open(); };
	void write(const std::vector<Employee> &employees);
};

#endif // CSVWRITER_H
