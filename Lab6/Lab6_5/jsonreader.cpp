#include "jsonreader.h"
#include "nlohmann/json.hpp"
#include "parse_error_exeption.h"

JSONReader::JSONReader(const QString &file_name)
{
	fin.open(file_name.toStdString());
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

// TODO
void JSONReader::readObject(UniversityMan &uman)
{
	nlohmann::json json = nlohmann::json::parse(fin);
}

std::vector<UniversityMan> JSONReader::readAll()
{
    std::vector<UniversityMan>  result;

    try
    {
		nlohmann::json json = nlohmann::json::parse(fin);
		for (auto &elem : json)
        {
			int id = elem["id"];
            int birth_year = elem["birth_year"];
            std::string full_name = elem["full_name"];
            e_sex sex = static_cast<e_sex>(elem["sex"]);

			if (id < 0 || birth_year < 0 || static_cast<int>(sex) < 0 || static_cast<int>(sex) > 1)
				throw(ParseErrorExeption());

			UniversityMan uman(id, birth_year, full_name, sex);
			result.push_back(uman);
        }
    }
    catch (nlohmann::json::parse_error)
    {
        throw(ParseErrorExeption());
    }

    return (result);
}
