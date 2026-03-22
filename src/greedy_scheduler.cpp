#include <iostream>
#include <vector>
#include <string>
#include "../include/greedy_scheduler.h"
#include "../include/quick_sort.h" 
#include "../include/display.h"

struct Shift {
    int day;
    std::string timeName;
    int remainingCapacity;
};

void addNewDay(std::vector<Shift>& shifts, int maxCapacity) {
    int sz = shifts.size();
    int nextDay = (sz/3)+1;
    shifts.push_back({nextDay, "Morning", maxCapacity});
    shifts.push_back({nextDay, "Afternoon", maxCapacity});
    shifts.push_back({nextDay, "Evening", maxCapacity});
}

void Scheduler::generateSchedule(std::vector<Dept>& departments, Seats& collegeCapacity) {
    QuickSort::sort(departments, 0, departments.size() - 1);

    int maxCapacity = collegeCapacity.gettotalSeatsAvailable();
    std::vector<Shift> shifts;
    addNewDay(shifts, maxCapacity); 

    std::vector<Assignment> finalSchedule; // This will hold our final results for the table

    std::cout << "\n--- Algorithm Trace: First-Fit Decreasing ---\n";
    std::cout << "Initial Capacity: " << maxCapacity << " seats per shift.\n";

    for (int i = 0; i < departments.size(); i++) {
        Dept& currentDept = departments[i];
        int students = currentDept.getnoOfStudents();
        int exams = currentDept.getnoOfExams();
        
        std::cout << "\nProcessing " << currentDept.getnameOfDept() 
                  << " (" << students << " students, " << exams << " exams)\n";

        std::vector<int> daysUsedByThisDept;

        for (int e = 1; e <= exams; e++) {
            std::cout << "  * Exam " << e << ":\n";
            bool scheduled = false;

            for (int s = 0; s < shifts.size(); s++) {
                std::cout << "      - Checking Day " << shifts[s].day << ", " << shifts[s].timeName 
                          << " (" << shifts[s].remainingCapacity << " seats available)... ";

                bool dayAlreadyUsed = false;
                for (int d = 0; d < daysUsedByThisDept.size(); d++) {
                    if (daysUsedByThisDept[d] == shifts[s].day) {
                        dayAlreadyUsed = true; break;
                    }
                }

                if (dayAlreadyUsed) {
                    std::cout << "Conflict! Dept already testing today.\n";
                } else if (shifts[s].remainingCapacity < students) {
                    std::cout << "Insufficient space.\n";
                } else {
                    std::cout << "Fits!\n";
                    shifts[s].remainingCapacity -= students;
                    daysUsedByThisDept.push_back(shifts[s].day);
                    
                    std::cout << "        -> Action: Assigned to Day " << shifts[s].day 
                              << ", " << shifts[s].timeName << ". (" 
                              << shifts[s].remainingCapacity << " seats remaining).\n";
                    
                    // Save to our results vector instead of printing
                    finalSchedule.push_back({currentDept.getnameOfDept(), e, shifts[s].day, shifts[s].timeName});
                    scheduled = true;
                    break; 
                }
            }

            if (!scheduled) {
                std::cout << "      - No existing shifts fit. Adding a new Day to the calendar...\n";
                addNewDay(shifts, maxCapacity);
                int newMorningIndex = shifts.size() - 3; 
                
                shifts[newMorningIndex].remainingCapacity -= students;
                daysUsedByThisDept.push_back(shifts[newMorningIndex].day);
                
                std::cout << "        -> Action: Assigned to Day " << shifts[newMorningIndex].day 
                          << ", Morning. (" << shifts[newMorningIndex].remainingCapacity << " seats remaining).\n";
                
                finalSchedule.push_back({currentDept.getnameOfDept(), e, shifts[newMorningIndex].day, "Morning"});
            }
        }
    }
    
    Display::printTable(finalSchedule);
}