#ifndef GREEDY_SCHEDULER_H
#define GREEDY_SCHEDULER_H

#include <vector>
#include "../include/department.h"
#include "../include/seats.h"

class Scheduler {
public:
static void generateSchedule(std::vector<Dept>& departments, Seats& collegeCapacity);
};

#endif