/*
 * Author:	Ivchenko Nikolay
 * Group:	IVT-21
 * Date:	07.02.2022
 * Variant:	2
 *
 * For all additional information, see the header file
*/

#include "Lab1.h"

void open_files(int argc, char **argv, std::ifstream &in, std::ofstream &out)
{
	if (argc != 3)
	{
		std::cout << "The number of arguments is not equal to 2" << std::endl
				  << "usage: Lab1 [file_input] [file_output]" << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	in.open(argv[1]);
	if (!in.is_open())
	{
		std::cout << "Can not open " << argv[1] << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	out.open(argv[2], std::ios::out | std::ios::trunc);
	if (!out.is_open())
	{
		in.close();
		std::cout << "Can not open " << argv[2] << std::endl;
		std::exit(EXIT_SUCCESS);
	}
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
		/* unprotected function call */
		tokens.push_back(str.substr(start, end - start));
		start = end + 1;
		end = str.find(delim, start);
	}
	tokens.push_back(str.substr(start, str.length() - start));
	return (tokens);
}

void parse_file(std::ifstream &file, std::vector<s_employee> &employees)
{
	std::string					string;
	std::vector<std::string>	tokens;

	while (!file.eof())
	{
		/* unprotected function call */
		std::getline(file, string);
		tokens = split(string, ';');
		if (tokens.empty())
			return ;
		/* unprotected function call */
		employees.push_back(s_employee {
			static_cast<unsigned int>(std::stoi(tokens[0])),
			static_cast<unsigned int>(std::stoi(tokens[2])),
			tokens[1],
			static_cast<e_sex>(std::stoi(tokens[3]))
		});
	}
}

void print_vector(const std::vector<s_employee> &employees)
{
	for (const auto &employee : employees)
		std::cout << employee.nb << '\t' << employee.full_name << '\t'
				  << employee.birth_year << '\t' << employee.sex << std::endl;
}

void write_vector(const std::vector<s_employee> &employees, std::ofstream &file)
{
	for (const auto &employee : employees)
		file << employee.nb << ';' << employee.full_name << ';'
			 << employee.birth_year << ';' << employee.sex << std::endl;
}

int main(int argc, char **argv)
{
	std::ifstream				in;
	std::ofstream				out;
	std::vector<s_employee>		employees;

	open_files(argc, argv, in, out);
	parse_file(in, employees);
	print_vector(employees);
	std::sort(employees.begin(), employees.end(), [](s_employee first, s_employee second){
		return (first.birth_year < second.birth_year);
	});
	write_vector(employees, out);
	in.close();
	out.close();
	return (0);
}
