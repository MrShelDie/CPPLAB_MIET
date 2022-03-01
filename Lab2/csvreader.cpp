#include "csvreader.h"

CSVReader::CSVReader(const std::string &fileName)
{
	fin.open(fileName);
}

CSVReader::~CSVReader()
{
	fin.close();
}

std::vector<std::string> CSVReader::split(const std::string &str, char delim)
{
	std::vector<std::string>	tokens;
	size_t						start;
	size_t						end;

	if (str.empty())
		return (tokens);
	start = 0;
	end = str.find(delim, start);
	while (end != std::string::npos)
	{
		tokens.push_back(str.substr(start, end - start));
		start = end + 1;
		end = str.find(delim, start);
	}
	tokens.push_back(str.substr(start, str.length() - start));
	return (tokens);
}

Employee CSVReader::parseLine(const std::string &line)
{
	std::vector<std::string>	tokens;

	tokens = split(line, ';');
	if (tokens.size() != 4)
		return (Employee());

	Employee result = Employee
	(
		static_cast<unsigned int>(std::stoi(tokens[0])),
		static_cast<unsigned int>(std::stoi(tokens[2])),
		tokens[1],
		static_cast<e_sex>(std::stoi(tokens[3]))
	);

	return (result);
}

std::vector<Employee> CSVReader::readAll()
{
	std::vector<Employee>	result;
	std::string				line;

	std::getline(fin, line);
	while(!fin.eof())
	{
		Employee employee = parseLine(line);
		if (employee.isEmpty())
		{
			result.clear();
			return (result);
		}
		result.push_back(employee);
		std::getline(fin, line);
	}
	return (result);
}
