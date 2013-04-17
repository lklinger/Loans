/*
 File Name:   main.cpp
 Created by:  Liz Klinger on 9/25/12.
 Description: Keeps track of multiple auto and mortgage loans at a time. Allows user to add additional loans to list. User can double check (validate) their loan information before adding it to the list.
 
 NOTE: Menu still accepts decimals (e.g. if there are options 1 & 2, program will accept an input like "2.8") and will treat input as two separate inputs ("2" and "8"). Don't quite know how to work around this, but wanted to acknowledge that this is a known error in the menu system of this program.
 
 Uses: Loan, LoanAuto, and LoanMortgage classes
 
 Files used (including main.cpp):
 Loan.h
 Loan.cpp
 LoanAuto.h
 LoanAuto.cpp
 LoanMortgage.h
 LoanMortgage.cpp
 
 */

#include <iostream>
#include "LoanAuto.h"
#include "LoanMortgage.h"
#include <vector>
#include <iomanip>
using namespace std;

int mainMenu(); // main menu of the program
int loanTracker(); // launch LoanTracker program
template <class T> int loanInput(vector <T> * someVector, int * count, int * size); // input for general loan; can be used by auto loan or mortgage
int autoLoanInput(vector <LoanAuto> * autoVector, int * vectorCountAuto, int * vectorSizeAuto); // input specifically for auto loans
int mortgageInput(vector <LoanMortgage> * mortgageVector, int * vectorCountMortgage, int * vectorSizeMortgage); // input specifically for mortgages
template <class T> int validateInfo(vector <T> * someVector, int * count, int * size); // validate loan info to add or not add to the loan list
int printLoanTracker(vector <LoanAuto> * autoVector, vector <LoanMortgage> * mortgageVector, int vectorSizeAuto, int vectorSizeMortgage); // print list of loans

int main()
{
    mainMenu();
    return 0;
}

int mainMenu()
{
    int option = 0;
    
    cout << "Welcome to LoanTracker! If this is your first time using LoanTracker, please read the instructions below." << endl << endl
    << "Instructions: Navigate menu options by typing in the corresponding number for the desired option." << endl << endl
    << "For example: Type \'1\' for \'1. Auto Loan\'" << endl << endl
    << "Thank you and we hope you enjoy our services! Your feedback is important to us, so please contact klinger005@connect.wcsu.edu for any questions or comments." << endl << endl;
    
    // menu options
    while (option != 2) {
        cout << "What would you like to do today?" << endl
        << "1. Track outstanding loans" << endl
        << "2. Quit" << endl
        << "Select Option: ";
        cin >> option;
        
        switch (option) {
            case 1:
                cout << endl;
                loanTracker();
                break;
            case 2:
                cout << endl << "Thank you for using LoanTracker! Goodbye.";
                return 0;
            default:
                cin.clear();
                cin.ignore(1000, '\n');
                cout << endl << "Sorry, that is not a valid option. Please try again." << endl << endl;
                break;
            }
    }
    
    return 0;
}

// LoanTracker main menu
int loanTracker()
{
    vector<LoanAuto> autoList(0); // create empty vector of autoList objects
    vector<LoanMortgage> mortgageList(0); // create empty vector of morgageList objects
    int option = 0, vectorCountAuto = 0, vectorSizeAuto = 0, vectorCountMortgage = 0, vectorSizeMortgage = 0; // variables to adjust menu (option), or size of vectors (the rest listed)
    
    cout << "LoanTracker" << endl << endl <<
    "Instructions: Track mortgage and auto loans with our handy Loantracker. Enter in your loan information, and when you are finished, we will organize all of your loans in one place and calculate the cost per month of each loan." << endl << endl;
    
    while (option != 4) {
        cout << "What kind of loan are you entering?" << endl <<
        "1. Auto Loan" << endl <<
        "2. Mortgage" << endl <<
        "3. Print loan data" << endl <<
        "4. Return to main menu (this will erase any loan data you've entered)" << endl <<
        "Select Option: ";
        cin >> option;
        
        switch (option) {
            case 1:
                cout << endl;
                autoList.resize(vectorSizeAuto + 1);
                loanInput(&autoList, &vectorCountAuto, &vectorSizeAuto);
                autoLoanInput(&autoList, &vectorCountAuto, &vectorSizeAuto);
                validateInfo(&autoList, &vectorCountAuto, &vectorSizeAuto);
                break;
            case 2:
                cout << endl;
                mortgageList.resize(vectorSizeMortgage + 1);
                loanInput(&mortgageList, &vectorCountMortgage, &vectorSizeMortgage);
                mortgageInput(&mortgageList, &vectorCountMortgage, &vectorSizeMortgage);
                validateInfo(&mortgageList, &vectorCountMortgage, &vectorSizeMortgage);
                break;
            case 3:
                printLoanTracker(&autoList, &mortgageList, vectorSizeAuto, vectorSizeMortgage);
                break;
            case 4:
                cout << endl << "Clearing your loan data... ";
                cout << endl << "Returning to main menu" << endl << endl;
                autoList.clear(); // clears auto loan data before returning to main menu
                mortgageList.clear(); // clears mortgage data before returning to main menu
                return 0;
            default:
                // clears input, allows user to try again
                cin.clear();
                cin.ignore(1000, '\n');
                cout << endl << "Sorry, that is not a valid option. Please try again." << endl << endl;
        }
        
    }
    return 0;
}

// inputs for auto loan OR mortgage
template <class T>
int loanInput(vector <T> * someVector, int * count, int * size)
{
    float userLoan = 0;
    double userRate = 0;
    int userTerm = 0;
    
    cout << "What is the total amount of the loan? ";
    cin >> userLoan;
    (* someVector)[*count].setLoanAmount(userLoan);
    cout << "What is the interest rate of the loan (no '%' percentage signs)? ";
    cin >> userRate;
    (* someVector)[*count].setPercentageRate(userRate);
    cout << "What is the term (in years) of the loan? ";
    cin >> userTerm;
    (* someVector)[*count].setTermYears(userTerm);
    
    return 0;
}

// inputs for auto loans ONLY
int autoLoanInput(vector <LoanAuto> * autoVector, int * vectorCountAuto, int * vectorSizeAuto)
{    
    string userMake = " ", userModel = " ";
    int userYear = 0, userMilage = 0;
    
    cout << "What is the make of the car? ";
    cin >> userMake;
    (* autoVector)[*vectorCountAuto].setMake(userMake);
    cout << "What is the model of the car? ";
    cin >> userModel;
    (* autoVector)[*vectorCountAuto].setModel(userModel);
    cout << "What is the year of the car? ";
    cin >> userYear;
    (* autoVector)[*vectorCountAuto].setYear(userYear);
    cout << "What is the milage of the car (if car is used)? ";
    cin >> userMilage;
    (* autoVector)[*vectorCountAuto].setMilage(userMilage);
    
    return 0;
}

// inputs for mortgages ONLY
int mortgageInput(vector <LoanMortgage> * mortgageVector, int * vectorCountMortgage, int * vectorSizeMortgage)
{
    int userSquareFeet = 0, userBedrooms = 0, userBathrooms = 0;
    string userAddress = " ", userCity = " ", userState = " ";
    
    cout << "What is the square footage of the house? ";
    cin >> userSquareFeet;
    (* mortgageVector)[*vectorCountMortgage].setSquareFeet(userSquareFeet);
    cout << "How many bedrooms are in the house? ";
    cin >> userBedrooms;
    (* mortgageVector)[*vectorCountMortgage].setBedrooms(userBedrooms);
    cout << "How many bathrooms are in the house? ";
    cin >> userBathrooms;
    (* mortgageVector)[*vectorCountMortgage].setBathrooms(userBathrooms);
    cout << endl;
        
    return 0;
}

// allows user to validate input before adding it to list; can be used for auto loan OR mortgage
template <class T>
int validateInfo(vector <T> * someVector, int * count, int * size)
{
    int option = 0;
    int cont = 1;
    
    while (cont) {
        cout << endl << "Is this information correct?" << endl <<
        "1. Yes, please add it to my list" << endl <<
        "2. No, don't add it to my list" << endl << endl;
        (* someVector)[*count].print(); // prints auto loan or mortgage
        cout << endl << "Select Option: ";
        cin >> option;
        switch (option) {
            case 1:
                cout << endl << "Adding information to your LoanTracker... " << endl << endl;
                *count = *count + 1; // count tracker to keep track of added loan
                *size = *size + 1; // size tracker to keep track of added loan
                cont = 0;
                break;
            case 2:
                cout << endl << "Clearing information from your LoanTracker... " << endl << endl;
                (* someVector).pop_back();
                cont = 0;
                break;
            default:
                cin.clear();
                cin.ignore(1000, '\n');
                cout << endl << "Sorry, that is not a valid option. Please try again." << endl;
                break;
        }
    }
    
    return 0;
}

int printLoanTracker(vector <LoanAuto> * autoVector, vector <LoanMortgage> * mortgageVector, int vectorSizeAuto, int vectorSizeMortgage)
{
    if (vectorSizeAuto > 0 || vectorSizeMortgage > 0) // print title if either vector has at least one element
    {
        cout << endl << "---------- LoanTracker ----------" << endl << endl;
    
        // print auto loan section if auto loan vector has at least one element
        if (vectorSizeAuto > 0) {
            cout << "Auto Loans:" << endl;
            cout << "|  Loan Amount  |  Interest Rate  |  Term  |  Payment Per Month  |   Make   |   Model   |  Year  |  Milage  |" << endl;
            cout << fixed << setiosflags(ios::left);
    
            for (int vectorCountAuto = 0; vectorCountAuto < vectorSizeAuto; vectorCountAuto++)
            {
                cout << setprecision(2) << " $" << setw(15) << (* autoVector)[vectorCountAuto].getLoanAmount() << setw(6) << (* autoVector)[vectorCountAuto].getPercentageRate() << setw(12) << "%" << setw(3) << (* autoVector)[vectorCountAuto].getTermYears() << "yrs   " << "$" << setw(21) << (* autoVector)[vectorCountAuto].getPayment() << setw(11) << (* autoVector)[vectorCountAuto].getMake() << setw(12) << (* autoVector)[vectorCountAuto].getModel() << setw(9) << (* autoVector)[vectorCountAuto].getYear() << setw(12) << (* autoVector)[vectorCountAuto].getMilage() << endl;
            }
        }
        
        // if both vectors have at least one element then add spacing between the two lists
        if (vectorSizeAuto > 0 && vectorSizeMortgage > 0) {
            cout << endl << endl;
        }

        // print mortgage section if auto loan vector has at least one element
        if (vectorSizeMortgage > 0) {
            cout << "Mortgages:" << endl;
            cout << "|  Loan Amount  |  Interest Rate  |  Term  |  Payment Per Month  |  Square Feet  |  Bedrooms  |  Bathrooms  |" << endl;
            cout << fixed << setiosflags(ios::left);
    
            for (int vectorCountMortgage = 0; vectorCountMortgage < vectorSizeMortgage; vectorCountMortgage++)
            {
                cout << setprecision(2) << " $" << setw(15) << (* mortgageVector)[vectorCountMortgage].getLoanAmount() << setw(6) << (* mortgageVector)[vectorCountMortgage].getPercentageRate() << setw(12) << "%" << setw(3) << (* mortgageVector)[vectorCountMortgage].getTermYears() << "yrs   " << "$" << setw(21) << (* mortgageVector)[vectorCountMortgage].getPayment() << setw(16) << (* mortgageVector)[vectorCountMortgage].getSquareFeet() << setw(13) << (* mortgageVector)[vectorCountMortgage].getBedrooms() << setw(14) << (* mortgageVector)[vectorCountMortgage].getBathrooms() << endl;
            }
        }
        cout << endl << "Thanks for using LoanTracker!" << endl << endl;
    }
    else // if both vectors are empty
    {
        cout << endl << "You didn't enter any data! Please try again." << endl << endl;
    }
    
    return 0;
}