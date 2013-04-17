/*
 File Name:   LoanMortgage.h
 Created by:  Liz Klinger on 9/25/12.
 Description: LoanMortgage header file containing information about constructor, destructor, member functions, and member variables

 Uses: Loan, and LoanMortgage classes
 
 Files used:
 Loan.h
 Loan.cpp
 LoanMortgage.cpp

 */

#ifndef __HW1__loanHome__
#define __HW1__loanHome__

#include <iostream>
#include "Loan.h" // loan class definition
using namespace std;

class LoanMortgage : public Loan {
  
public:
    LoanMortgage(float = 0, double = 0, int = 0, int = 0, int = 0, int = 0, string address = " ", string city = " ", string state = " ");
    ~LoanMortgage();
    
    void setSquareFeet(int); // set house square feet
    int getSquareFeet() const; // get square feet
    
    void setBedrooms(int); // set number of bedrooms
    int getBedrooms() const; // get bedrooms
    
    void setBathrooms(int); // set number of bathrooms
    int getBathrooms() const; // get bathrooms
    
    void print() const;
    
private:
    int squareFeet; // house square feet
    int bedrooms; // house bedrooms
    int bathrooms; // house bathrooms   
};

#endif /* defined(__HW1__loanHome__) */
