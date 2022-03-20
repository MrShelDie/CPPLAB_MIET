#include "csvwriter.h"

CSVWriter::CSVWriter(const std::string& file_name)
{
	fout.open(file_name, std::ios::out | std::ios::trunc);
}

CSVWriter::CSVWriter(CSVWriter&& other)
	: fout(std::move(other.fout))
{

}

CSVWriter::~CSVWriter()
{
	if (fout.is_open())
		fout.close();
}

CSVWriter& CSVWriter::operator=(CSVWriter &&other)
{
	fout = std::move(other.fout);
	return *this;
}

void CSVWriter::write(const std::vector<UniversityMan>& employees)
{
	for (const auto &employee : employees)
		fout << employee.getId() << ';' << employee.getFullName() << ';'
			 << employee.getBirthYear() << ';' << employee.getSex() << std::endl;
}
