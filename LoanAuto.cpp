/*
 File Name:   LoanAuto.cpp
 Created by:  Liz Klinger on 9/25/12.
 Description: cpp file for LoanAuto class
 
 Uses: Loan, and LoanAuto classes
 
 Files used:
 Loan.h
 Loan.cpp
 LoanAuto.h

 */

#include "LoanAuto.h"
#include <iostream>

using namespace std;

LoanAuto::LoanAuto(float amount, double rate, int years, string userMake, string userModel, int userYear, int userMilage)
: Loan(amount, rate, years) // call base class constructor
{
    setMake(userMake);
    setModel(userModel);
    setYear(userYear);
    setMilage(userMilage);
}

LoanAuto::~LoanAuto()
{
    
}

void LoanAuto::setMake(string userMake)
{
    make = userMake;
}
 
std::string LoanAuto::getMake() const
{
    return make;
}
 
void LoanAuto::setModel(string userModel)
{
     model = userModel;
}
 
std::string LoanAuto::getModel() const
{
     return model;
}
 
void LoanAuto::setYear(int userYear)
{
    year = userYear;
}

int LoanAuto::getYear() const
{
    return year;
}

void LoanAuto::setMilage(int userMilage)
{
    milage = userMilage;
}

int LoanAuto::getMilage() const
{
    return milage;
}

void LoanAuto::print() const
{
    Loan::print(); // invoke loan's print funciton
    cout << "Make: " << make << endl <<
    "Model: " << model << endl <<
    "Year: " << year << endl <<
    "Milage: " << milage << " miles" << endl;
}


