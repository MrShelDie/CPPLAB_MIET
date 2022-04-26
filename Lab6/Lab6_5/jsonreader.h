#ifndef JSONREADER_H
#define JSONREADER_H

#include <QString>
#include <fstream>

#include "abstract_reader.h"

class JSONReader : public AbstractReader
{
private:
    std::ifstream	fin;

public:
    JSONReader(const QString &file_name);
    JSONReader(const JSONReader&) = delete;
    JSONReader(JSONReader&&);
    ~JSONReader();

    JSONReader& operator=(const JSONReader&) = delete;
    JSONReader operator=(JSONReader&&);

    virtual bool isOpen() const override { return fin.is_open(); };
	virtual void readObject(UniversityMan &uman) override;
    virtual std::vector<UniversityMan> readAll() override;
};

#endif // JSONREADER_H
