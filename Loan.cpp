/*
 File Name:   Loan.cpp
 Created by:  Liz Klinger on 9/25/12.
 Description: cpp file for Loan class

 Uses: Loan class
 
 Files used:
 Loan.h
 
 */

#include <iostream>
#include "Loan.h" // loan class definition
#include <iomanip>
using namespace std;

// default constructor
Loan::Loan(float userLoan, double userRate, int userYears)
{
    setLoanAmount(userLoan);
    setPercentageRate(userRate);
    setTermYears(userYears);
    
    getPayment();
} // end loan constructor

// destructor
Loan::~Loan()
{
    
}//end loan destructor

// set loan amount
void Loan::setLoanAmount(float userLoan)
{
    loanAmount = userLoan;
} // end function setLoanAmount

// return loan amount
float Loan::getLoanAmount() const
{
    return loanAmount;
} // end function getLoanAmount

// set percentage rate
void Loan::setPercentageRate(double userRate)
{
    percentageRate = userRate;
}

// return percentage rate
double Loan::getPercentageRate() const
{
    return percentageRate;
}

// set years of terms
void Loan::setTermYears(int userYears)
{
    termYears = userYears;
}

// return years of terms
int Loan::getTermYears() const
{
    return termYears;
}

double Loan::getPayment()
{
    return costPerMonth = getLoanAmount() * (1 + getPercentageRate() / 100) / getTermYears() / 12;
}

// print object
void Loan::print() const
{
    cout << "Loan Amount: $" << loanAmount << endl <<
            "Term (years): " << termYears << " years" << endl <<
            "Interest Rate: " << percentageRate << "%" << endl;
}

