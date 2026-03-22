#include <iostream>
#include "../include/seats.h"

Seats::Seats(){
settotalClassRooms();
setaccomodationInClass();
settotalSeatsAvailable();
}

void Seats::settotalClassRooms(){
    std::cout<<"Enter the total no of classrooms available: ";
    std::cin>>totalClassRooms;
}
void Seats::setaccomodationInClass(){
    std::cout<<"Enter the accomodation of a classroom: ";
    std::cin>>accomodationInClass;
}
void Seats::settotalSeatsAvailable(){
    totalSeatsAvailable = totalClassRooms * accomodationInClass;
}
int Seats::gettotalClassRooms(){
    return totalClassRooms;
}
int Seats::getaccomodationInClass(){
    return accomodationInClass;
}
int Seats::gettotalSeatsAvailable(){
    return totalSeatsAvailable;
}

void Seats::displayseats(){// helper not using in main
    std::cout<<"The total no of classrooms available are : "<<gettotalClassRooms()<<std::endl;
    std::cout<<"The accomodation in a classroom is : "<<getaccomodationInClass()<<std::endl;
    std::cout<<"The total no of seats available are : "<<gettotalSeatsAvailable()<<std::endl;
}

