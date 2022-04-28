#ifndef STUDENT_H
#define STUDENT_H

#include "university_man.h"

class Student : public UniversityMan
{
private:
	int			course;
	std::string	specialization;

public:
	Student();
	Student(int _course, const std::string &_specialization);

	std::string	toString() const;
};

#endif // STUDENT_H
