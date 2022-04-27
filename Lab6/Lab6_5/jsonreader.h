#ifndef JSONREADER_H
#define JSONREADER_H

#include <QString>
#include <fstream>

#include "abstract_reader.h"
#include "nlohmann/json.hpp"

class JSONReader : public AbstractReader
{
private:
	std::ifstream				fin;
	nlohmann::json				json;
	nlohmann::json::iterator	json_iterator;
	nlohmann::json::iterator	json_end;

public:
    JSONReader(const QString &file_name);
    JSONReader(const JSONReader&) = delete;
    JSONReader(JSONReader&&);
    ~JSONReader();

    JSONReader& operator=(const JSONReader&) = delete;
    JSONReader operator=(JSONReader&&);
	operator bool() const override;

    virtual bool isOpen() const override { return fin.is_open(); };
	virtual bool eof() const override { return json_iterator == json_end; };
	virtual void readNextObject(UniversityMan &uman) override;
    virtual std::vector<UniversityMan> readAll() override;
};

#endif // JSONREADER_H
