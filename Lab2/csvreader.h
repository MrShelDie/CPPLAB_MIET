#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

#include "employee.h"

class CSVReader
{
private:
	std::ifstream	fin;

private:
	Employee parseLine(const std::string &line);
	std::vector<std::string> split(const std::string &str, char delim);

public:
	CSVReader(const std::string &fileName);
	~CSVReader();

	bool isOpen() const { return fin.is_open(); };
	std::vector<Employee> readAll();
};

#endif // CSVREADER_H
