#include "csvreader.h"
#include "csv_parse_error_exeption.h"

CSVReader::CSVReader(const QString &file_name)
{
	fin.exceptions( fin.failbit | fin.badbit );
    fin.open(file_name.toStdString());
}

CSVReader::CSVReader(CSVReader&& other)
    : fin(std::move(other.fin))
{

}

CSVReader::~CSVReader()
{
	if (fin.is_open())
		fin.close();
}

CSVReader CSVReader::operator=(CSVReader&& other)
{
    return std::move(other);
}

CSVReader::operator bool() const
{
	return !this->eof();
}

std::vector<std::string> CSVReader::split(const std::string& str, char delim)
{
	std::vector<std::string>	tokens;

	if (str.empty())
		return (tokens);

	size_t start = 0;
	size_t end = str.find(delim, start);

	while (end != std::string::npos)
	{
		tokens.push_back(str.substr(start, end - start));
		start = end + 1;
		end = str.find(delim, start);
	}
	tokens.push_back(str.substr(start, str.length() - start));

	return (tokens);
}

UniversityMan CSVReader::parseLine(const std::string& line)
{
	std::vector<std::string>	tokens;

	tokens = split(line, ';');
	if (tokens.size() != 4)
		throw CSVParseErrorExeption("invalid syntax", line_nb);

	const int			id			= std::stoi(tokens[0]);
	const int			birth_year	= std::stoi(tokens[2]);
	const std::string	full_name	= tokens[1];
	const e_sex			sex			= static_cast<e_sex>(std::stoi(tokens[3]));

	if (id < 0)
		throw CSVParseErrorExeption("ID less then 0", line_nb);
	else if (birth_year < 0)
		throw CSVParseErrorExeption("Birth year less then 0", line_nb);
	else if (static_cast<int>(sex) < 0 || static_cast<int>(sex) > 1)
		throw CSVParseErrorExeption("Sex is not equal to 0 or 1", line_nb);

	UniversityMan result(id, birth_year, full_name, sex);

	return (result);
}

void CSVReader::readNextObject(UniversityMan &uman)
{
	std::string	line;

	try
	{
		/* Skips blank lines */
		while (std::getline(fin, line) && line.empty())
			line_nb++;
		line_nb++;
		if (!line.empty())
			uman = parseLine(line);
	}
	catch (const std::ifstream::failure &e)
	{
		if (!fin.eof())
			throw e;
	}
	catch (const std::invalid_argument &e)
	{
		std::string msg = std::string("invalid argument: ") + std::string(e.what());
		throw CSVParseErrorExeption(msg, line_nb);
	}
	catch (const std::out_of_range &e)
	{
		std::string msg = std::string("out of range error: ") + std::string(e.what());
		throw CSVParseErrorExeption(msg, line_nb);
	}
}

std::vector<UniversityMan> CSVReader::readAll()
{
	UniversityMan				uman;
	std::vector<UniversityMan>	result;

	while (*this >> uman)
		result.push_back(uman);

	return (result);
}
