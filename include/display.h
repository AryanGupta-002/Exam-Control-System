#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>
#include <string>

struct Assignment {
std::string deptName;
int examNum;
int day;
std::string shiftName;
};

class Display {
public:
static void printTable(const std::vector<Assignment>& schedule);
};

#endif