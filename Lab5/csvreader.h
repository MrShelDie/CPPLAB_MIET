#ifndef CSVREADER_H
#define CSVREADER_H

#include <QString>

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

#include "abstract_reader.h"
#include "university_man.h"

class CSVReader : public AbstractReader
{
private:
	std::ifstream	fin;

private:
	UniversityMan parseLine(const std::string& line);
	std::vector<std::string> split(const std::string& str, char delim);

public:
    CSVReader(const QString &file_name);
	CSVReader(const CSVReader&) = delete;
	CSVReader(CSVReader&& other);
	~CSVReader();

    CSVReader& operator=(const CSVReader&) = delete;
    CSVReader operator=(CSVReader&& other);

    virtual bool isOpen() const override { return fin.is_open(); };
    virtual std::vector<UniversityMan> readAll() override;
};

#endif // CSVREADER_H
