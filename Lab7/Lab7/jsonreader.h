#ifndef JSONREADER_H
#define JSONREADER_H

#include <QString>
#include <fstream>

#include "abstract_reader.h"
#include "nlohmann/json.hpp"

class JSONReader : public AbstractReader
{
private:
    bool                        isFileEnd;
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

	virtual bool isOpen() const override { return !isFileEnd; };
    virtual bool eof() const override { return isFileEnd; };
	virtual void readNextObject(UniversityMan &uman) override;
    virtual std::vector<UniversityMan> readAll() override;
};

#endif // JSONREADER_H
