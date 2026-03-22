#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <string>

class Dept{
private:
std::string nameOfDept;
int noOfStudents = 0;
int noOfExams = 0;

void setnameOfDept();
void setnoOfStudents();
void setnoOfExams();

public:

Dept();
std::string getnameOfDept();
int getnoOfStudents();
int getnoOfExams();

void displayDept();
};

#endif