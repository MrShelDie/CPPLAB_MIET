#include "csvwriter.h"

CSVWriter::CSVWriter(const std::string &file_name)
{
	fout.open(file_name, std::ios::out | std::ios::trunc);
}

CSVWriter::~CSVWriter()
{
	if (fout.is_open())
		fout.close();
}

void CSVWriter::write(const std::vector<Employee> &employees)
{
	for (const auto &employee : employees)
		fout << employee.getId() << ';' << employee.getFullName() << ';'
			 << employee.getBirthYear() << ';' << employee.getSex() << std::endl;
}
