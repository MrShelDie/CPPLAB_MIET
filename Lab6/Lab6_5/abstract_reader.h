#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include <vector>

#include "university_man.h"

class AbstractReader
{
public:
    virtual std::vector<UniversityMan> readAll() = 0;
    virtual bool isOpen() const = 0;
	virtual bool eof() const = 0;

	virtual operator bool() const = 0;
	friend AbstractReader& operator>>(AbstractReader &reader, UniversityMan &uman);

protected:
	virtual void readNextObject(UniversityMan &uman) = 0;
};

#endif // ABSTRACTREADER_H
