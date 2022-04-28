#ifndef RESEARCH_ASSOCIATE_H
#define RESEARCH_ASSOCIATE_H

#include "university_man.h"

class ResearchAssociate : public UniversityMan
{
private:
	std::string post;
	std::string	research_scope;

public:
	ResearchAssociate();
	ResearchAssociate(const std::string &_post, const std::string &_researchScope);

	std::string	toString() const;
};

#endif // RESEARCH_ASSOCIATE_H
