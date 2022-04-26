#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include <vector>

#include "university_man.h"

class AbstractReader
{
public:
    virtual std::vector<UniversityMan> readAll() = 0;
    virtual bool isOpen() const = 0;
};

#endif // ABSTRACTREADER_H
