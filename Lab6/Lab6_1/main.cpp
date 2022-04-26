/*
 * Author:			Ivchenko Nikolay
 * Group:			IVT-21
 * Creation date:	07.02.2022
 * Variant:	2
 *
 * The program receives two arguments as input - the name of the file to read and the file to write.
 * This implementation assumes that the entries in the CSV file are separated
 * by the ";" symbol. It is also assumed that the entries in the file are in
 * the same order in which they were presented in the task.
 * Function calls are not protected by the try-catch block.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

enum e_sex
{
	MALE,
	FEMALE
};

struct s_employee
{
	unsigned int	nb;
	unsigned int	birth_year;
	std::string		full_name;
	e_sex			sex;

	friend bool operator<(s_employee lhs, s_employee rhs);
	friend std::ostream& operator<<(std::ostream& lhs, const s_employee &rhs);
};

bool operator<(const s_employee &lhs, const s_employee &rhs)
{
	return lhs.birth_year < rhs.birth_year;
}

std::ostream& operator<<(std::ostream& lhs, const s_employee &rhs)
{
	lhs << "{ " << rhs.nb << ", " << rhs.full_name << ", "
		<< rhs.birth_year << ", " << rhs.sex << " }" << std::endl;
	return lhs;
}

bool checkArgs(int argc)
{
	if (argc != 3)
	{
		std::cout << "The number of arguments is not equal to 2" << std::endl
				  << "usage: Lab1 [file_input] [file_output]" << std::endl;
		return (false);
	}
	return (true);
}

std::vector<std::string> split(const std::string &str, char delim)
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

s_employee *parseLine(const std::string &line)
{
	std::vector<std::string>	tokens;

	tokens = split(line, ';');
	if (tokens.size() != 4)
		return (NULL);

	s_employee *employee = new s_employee
	{
		static_cast<unsigned int>(std::stoi(tokens[0])),
		static_cast<unsigned int>(std::stoi(tokens[2])),
		tokens[1],
		static_cast<e_sex>(std::stoi(tokens[3]))
	};

	return (employee);
}

std::vector<s_employee> parseFile(const std::string &file_path)
{
	std::string					line;
	std::ifstream				file;
	std::vector<s_employee>		employees;

	file.open(file_path);
	if (!file.is_open())
	{
		std::cout << "Can not open file: " << file_path << std::endl;
		return (employees);
	}

	std::getline(file, line);
	while (!file.eof())
	{
		s_employee *employee = parseLine(line);
		if (!employee)
		{
			std::cout << "Invalid data in the file" << std::endl;
			file.close();
			employees.clear();
			return (employees);
		}
		employees.push_back(*employee);
		delete (employee);
		std::getline(file, line);
	}

	file.close();
	return (employees);
}

void writeVectorToStdout(const std::vector<s_employee> &employees)
{
	for (const auto &empoloyee : employees)
		std::cout << empoloyee;
}

bool writeVectorToFile(const std::vector<s_employee> &employees, const std::string &file_path)
{
	std::ofstream	file;

	file.open(file_path, std::ios::out | std::ios::trunc);
	if (!file.is_open())
	{
		std::cout << "Can not open file: " << file_path << std::endl;
		return (false);
	}

	for (const auto &employee : employees)
		file << employee.nb << ';' << employee.full_name << ';'
			 << employee.birth_year << ';' << employee.sex << std::endl;

	file.close();
	return (true);
}

int main(int argc, char **argv)
{
	std::vector<s_employee>		employees;

	if (!checkArgs(argc))
		return (0);
	employees = parseFile(argv[1]);
	if (employees.empty())
		return (0);
	writeVectorToStdout(employees);
	std::sort(employees.begin(), employees.end(), operator<);
	writeVectorToFile(employees, argv[2]);
	return (0);
}
