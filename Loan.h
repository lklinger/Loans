/*
 File Name:   Loan.h
 Created by:  Liz Klinger on 9/25/12.
 Description: Loan header file containing information about constructor, destructor, member functions, and member variables
 
 Uses: Loan class
 
 Files used:
 Loan.cpp
 */

#ifndef Loan_h
#define Loan_h

class Loan {

public:
    Loan(float = 0, double = 0, int = 0); // default constructor
    ~Loan(); // destructor
    
    void setLoanAmount(float); // set loan amount
    float getLoanAmount() const; // return loan amount
    
    void setPercentageRate(double); // set percentage rate
    double getPercentageRate() const; // return percentage rate
    
    void setTermYears(int); // set term years
    int getTermYears() const; // return term years
    
    double getPayment(); // return payment
                         //double getPaymentSchedule(); // return payment schedule by month
    
    void print() const; // output object
    
private:
    // variables part of loan calculation
    float loanAmount;
    double percentageRate;
    int termYears;
    
    float yearPayment;
    float monthPayment;
    float loanTotal;
    float costPerMonth;
    
    int count = 0;

}; // end class loan

#endif
