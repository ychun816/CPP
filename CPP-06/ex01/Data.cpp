#include "Data.hpp"

////contructor & destructor
Data::Data() : _name("DEFAULT"), _id(0), _score(0.0){};

Data::Data(std::string name, int id, double score) : _name(name), _id(id), _score(score)
{
    std::cout << "Data Constructor called : [" << _name << " | " << _id << " | " << _score << " ]" << std::endl;
}

Data::~Data(){};

////getters
int Data::getID() const { return (_id); }
std::string Data::getName() const { return (_name); }
double Data::getScore() const { return (_score); }
