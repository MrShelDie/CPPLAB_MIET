#include "abstract_reader.h"

AbstractReader& operator>>(AbstractReader &reader, UniversityMan &uman)
{
	reader.readNextObject(uman);
	return reader;
}
