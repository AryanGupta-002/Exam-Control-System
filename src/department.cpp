#include <iostream>
#include "../include/department.h"
#include <string>

Dept::Dept(){
setnameOfDept();
setnoOfStudents();
setnoOfExams();
}

void Dept::setnameOfDept(){
    std::cout<<"Enter the name of the Department: ";
    std::cin.ignore();
    std::getline(std::cin,nameOfDept);
}

void Dept::setnoOfStudents(){
    std::cout<<"Enter the no of Students in this Department: ";
    std::cin>>noOfStudents;
}

void Dept::setnoOfExams(){
    std::cout<<"Enter the total no of Exams to be conducted in this Department: ";
    std::cin>>noOfExams;
}

std::string Dept::getnameOfDept(){
    return nameOfDept;
}

int Dept::getnoOfStudents(){
    return noOfStudents;
}

int Dept::getnoOfExams(){
    return noOfExams;
}

void Dept::displayDept(){ //helper not using in main
    std::cout<<"Department : "<<getnameOfDept()<<std::endl;
    std::cout<<"The no of students in the Department are : "<<getnoOfStudents()<<std::endl;
    std::cout<<"The no of exams in the department are : "<<getnoOfExams()<<std::endl;
}