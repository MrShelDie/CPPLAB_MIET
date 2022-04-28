#include "csvreader.h"
#include "parse_error_exeption.h"

CSVReader::CSVReader(const QString &file_name)
{
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

UniversityMan CSVReader::parseLine(const std::string& line)
{
	std::vector<std::string>	tokens;

	tokens = split(line, ';');
	if (tokens.size() != 4)
        throw(ParseErrorExeption());

	const int			id			= std::stoi(tokens[0]);
	const int			birth_year	= std::stoi(tokens[2]);
	const std::string	full_name	= tokens[1];
	const e_sex			sex			= static_cast<e_sex>(std::stoi(tokens[3]));

	if (id < 0 || birth_year < 0 || static_cast<int>(sex) < 0 || static_cast<int>(sex) > 1)
        throw(ParseErrorExeption());

	UniversityMan result(id, birth_year, full_name, sex);

	return (result);
}

void CSVReader::readNextObject(UniversityMan &uman)
{
	std::string	line;

	/* Skips blank lines */
	do
		std::getline(fin, line);
    while (line.empty() && !fin.eof());

    if (!line.empty())
        uman = parseLine(line);
}

std::vector<UniversityMan> CSVReader::readAll()
{
	UniversityMan				uman;
	std::vector<UniversityMan>	result;

	while (*this >> uman)
		result.push_back(uman);

	return (result);
}
