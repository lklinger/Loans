/*
 File Name:   LoanMortgage.cpp
 Created by:  Liz Klinger on 9/25/12.
 Description: cpp file for LoanMortgage class
 
 Uses: Loan, and LoanMortgage classes

 Files used:
 Loan.h
 Loan.cpp
 LoanMortgage.h
 
 */

#include "LoanMortgage.h"
#include <iostream>
using namespace std;

LoanMortgage::LoanMortgage(float userAmount, double userRate, int userYears, int userSquareFeet, int userBedrooms, int userBathrooms, string userAddress, string userCity, string userState)
: Loan(userAmount, userRate, userYears) // call base class constructor
{
    setSquareFeet(userSquareFeet);
    setBedrooms(userBedrooms);
    setBathrooms(userBathrooms);
}

LoanMortgage::~LoanMortgage()
{
    
}

void LoanMortgage::setSquareFeet(int userSquareFeet)
{
    squareFeet = userSquareFeet;
}

int LoanMortgage::getSquareFeet() const
{
    return squareFeet;
}

void LoanMortgage::setBedrooms(int userBedrooms)
{
    bedrooms = userBedrooms;
}

int LoanMortgage::getBedrooms() const
{
    return bedrooms;
}

void LoanMortgage::setBathrooms(int userBathrooms)
{
    bathrooms = userBathrooms;
}

int LoanMortgage::getBathrooms() const
{
    return bathrooms;
}

void LoanMortgage::print() const
{
    Loan::print(); // invoke loan's print funciton
    cout << "Square Feet: " << squareFeet << " square feet" << endl <<
    "Bedrooms: " << bedrooms << endl <<
    "Bathrooms: " << bathrooms << endl;
}