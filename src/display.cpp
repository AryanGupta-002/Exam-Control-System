#include <iostream>
#include <iomanip> 
#include "../include/display.h"

void Display::printTable(const std::vector<Assignment>& schedule) {
    std::cout << "\n==============================================================\n";
    std::cout << "         UNIVERSITY EXAM SCHEDULING SYSTEM        \n";
    std::cout << "==============================================================\n";

    std::cout << std::left 
              << std::setw(20) << "Department" 
              << std::setw(15) << "Exam Number" 
              << std::setw(10) << "Day" 
              << std::setw(15) << "Shift" << "\n";
    std::cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < schedule.size(); i++) {
        std::cout << std::left 
                  << std::setw(20) << schedule[i].deptName
                  << "Exam " << std::setw(10) << schedule[i].examNum
                  << "Day " << std::setw(6) << schedule[i].day
                  << std::setw(15) << schedule[i].shiftName << "\n";
    }
    std::cout << "==============================================================\n";
}