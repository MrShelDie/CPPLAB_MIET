#include "abstract_reader.h"

AbstractReader& operator>>(AbstractReader &reader, UniversityMan &uman)
{
	reader.readObject(uman);
	return reader;
}
