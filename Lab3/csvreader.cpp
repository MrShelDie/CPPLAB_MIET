#include "csvreader.h"

CSVReader::CSVReader(const std::string &file_name)
{
	fin.open(file_name);
	parse_error = false;
}

CSVReader::~CSVReader()
{
	if (fin.is_open())
		fin.close();
	parse_error = false;
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
	{
		parse_error = true;
		return (Employee());
	}

	const int			id			= std::stoi(tokens[0]);
	const int			birth_year	= std::stoi(tokens[2]);
	const std::string	full_name	= tokens[1];
	const e_sex			sex			= static_cast<e_sex>(std::stoi(tokens[3]));

	if (id < 0 || birth_year < 0 || static_cast<int>(sex) < 0 || static_cast<int>(sex) > 1)
	{
		parse_error = true;
		return (Employee());
	}

	Employee result(id, birth_year, full_name, sex);

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
