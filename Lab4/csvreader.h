#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

#include "university_man.h"

class CSVReader
{
private:
	std::ifstream	fin;
	bool			parse_error;

private:
	UniversityMan parseLine(const std::string& line);
	std::vector<std::string> split(const std::string& str, char delim);

public:
	CSVReader(const std::string &file_name);
	CSVReader(const CSVReader&) = delete;
	CSVReader(CSVReader&& other);
	~CSVReader();

	CSVReader& operator=(const CSVReader&) = delete;
	CSVReader& operator=(CSVReader&& other);

	bool isOpen() const { return fin.is_open(); };
	bool isParseError() const { return parse_error; };
	std::vector<UniversityMan> readAll();
};

#endif // CSVREADER_H
