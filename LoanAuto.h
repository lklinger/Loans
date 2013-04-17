/*
 File Name:   LoanAuto.h
 Created by:  Liz Klinger on 9/25/12.
 Description: LoanAuto header file containing information about constructor, destructor, member functions, and member variables

 Uses: Loan, and LoanAuto classes
 
 Files used:
 Loan.h
 Loan.cpp
 LoanAuto.cpp

 */

#ifndef __HW1__LoanAuto__
#define __HW1__LoanAuto__

#include "Loan.h" // loan class definition
#include <iostream>
using namespace std;


class LoanAuto : public Loan {
    
public:
    LoanAuto(float = 0, double = 0, int = 0, string = " ", string = " ", int = 0, int = 0);
    ~LoanAuto();
    
    void setMake(std::string); // set car make
    std::string getMake() const; // get car make
     
    void setModel(std::string); // set car model
    std::string getModel() const; // get car model
     
    void setYear(int); // set car year
    int getYear() const; // get car year
    
    void setMilage(int); // set car milage
    int getMilage() const; // get car milage
    
    void print() const;
    
private:
    string make; // car make
    string model; // car model
    int year; // car year
    int milage; // car milage (if used car)
    
    
};

#endif /* defined(__HW1__loanAuto__) */

