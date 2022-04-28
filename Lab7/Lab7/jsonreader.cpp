#include "jsonreader.h"
#include "nlohmann/json.hpp"
#include "parse_error_exeption.h"
#include "invalid_data_exception.h"

JSONReader::JSONReader(const QString &file_name)
{
	fin.open(file_name.toStdString());

	json = nlohmann::json::parse(fin);
	json_iterator = json.begin();
	json_end = json.end();

    isFileEnd = json_iterator == json_end ? true : false;
}

JSONReader::JSONReader(JSONReader&& other)
    : fin(std::move(other.fin))
{

}

JSONReader::~JSONReader()
{
    if (fin.is_open())
        fin.close();
}

JSONReader JSONReader::operator=(JSONReader&& other)
{
    return std::move(other);
}

JSONReader::operator bool() const
{
	return !this->eof();
}

void JSONReader::readNextObject(UniversityMan &uman)
{
    if (json_iterator == json_end)
    {
        isFileEnd = true;
		return;
    }

	int id = (*json_iterator)["id"];
	int birth_year = (*json_iterator)["birth_year"];
	std::string full_name = (*json_iterator)["full_name"];
	e_sex sex = static_cast<e_sex>((*json_iterator)["sex"]);

//	if (id < 0 || birth_year < 0 || static_cast<int>(sex) < 0 || static_cast<int>(sex) > 1)
//		throw(ParseErrorExeption());

    if (id < 0)
        throw InvalidDataException("ID less then zero");
    else if (birth_year < 0)
        throw InvalidDataException("Birth year less then zero");

	uman = UniversityMan(id, birth_year, full_name, sex);
	json_iterator++;
}

std::vector<UniversityMan> JSONReader::readAll()
{
	UniversityMan				uman;
	std::vector<UniversityMan>  result;

	while (*this >> uman)
		result.push_back(uman);

    return (result);
}
