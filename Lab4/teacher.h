#ifndef TEACHER_H
#define TEACHER_H

#include "university_man.h"

class Teacher : public UniversityMan
{
private:
	std::string	subject;
	std::string	department;

public:
	Teacher();
	Teacher(const std::string &_subject, const std::string &_department);

	std::string	toString() const;
};

#endif // TEACHER_H
