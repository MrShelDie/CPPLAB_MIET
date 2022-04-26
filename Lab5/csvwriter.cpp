#include "csvwriter.h"

CSVWriter::CSVWriter(const QString& file_name)
{
    fout.open(file_name.toStdString(), std::ios::out | std::ios::trunc);
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

CSVWriter CSVWriter::operator=(CSVWriter &&other)
{
    return std::move(other);
}

void CSVWriter::write(const std::vector<UniversityMan>& employees)
{
	for (const auto &employee : employees)
		fout << employee.getId() << ';' << employee.getFullName() << ';'
			 << employee.getBirthYear() << ';' << employee.getSex() << std::endl;
}
