#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../include/department.h"
#include "../include/seats.h"
#include "../include/greedy_scheduler.h"

using namespace std;

int main() {

    srand(time(0));

    cout << "=========================================\n";
    cout << "       COLLEGE EXAM SCHEDULING SYSTEM    \n";
    cout << "=========================================\n\n";

    cout << "--- Step 1: Set College Capacity ---\n";
    Seats collegeCapacity; //This constructor asks about college capacity
    
    cout << "\nCapacity Set! Maximum seats per shift: " 
         << collegeCapacity.gettotalSeatsAvailable() << "\n\n";

    int numDepartments;
    cout << "--- Step 2: Add Departments ---\n";
    cout << "Enter the total number of departments: ";
    cin >> numDepartments;

    vector<Dept> departments;
    for (int i = 0; i < numDepartments; i++) {
        cout << "\n[ Adding Department " << (i + 1) << " ]\n";
        Dept newDept; // This constructor asks for name, students, and exams
        departments.push_back(newDept);
    }

    cout << "\n=========================================\n";
    cout << "       GENERATING EXAM SCHEDULE...       \n";
    cout << "=========================================\n";
    
    Scheduler::generateSchedule(departments, collegeCapacity);

    cout << "\nScheduling Complete. Exiting program...\n";
    cin.ignore();
    cin.get();
    return 0;
}