//
//  main.cpp
//  EasterDateCalculator_A2
//
//  Created by Kevin Eastin on 9/24/15.
//  Copyright © 2015 Kevin Eastin. All rights reserved.
//


//Easter Date Calculator from the range of 1900 to 2099.

#include<string>
#include<iostream>
#include<cstdlib>

using namespace std;

//global constants
const int MINIMUMYEAR = 1900;
const int MAXIMUMYEAR = 2099;

//function prototypes
void DateCheck(int year);
int EasterCalculate(int quearyYear);
string MonthCheck(int easterDay);


//main function
int main() {
    //call variables
    int currentDay;
    int currentMonth;
    int currentYear; //
    int quearyYear;  //
    int easterDay;  //
    
    string easterMonth; //
    string tense; //xxxxx/
    
    
    //introduce the program the user.
    cout << "Welcome User! You've arrived at the niftiest Easter Calculator in town. Use at your" << endl;
    cout << "own discretion and keep in mind: We only accept years from 1900-2099. Now enjoy :)";
    cout << endl << endl;
    
    //ask the user for inputs
    cout << "Hey User, first things first, what's the current year? (please use 4 digits buddy) ";
    cin >> currentYear;
    DateCheck(currentYear);
    
    cout << "Now then, on what year would you like to know the date of easter? (4 digits, don't forget) ";
    cin >> quearyYear;
    DateCheck(quearyYear);
    
    //calculate the easterDay using the function EasterCalculate
    easterDay = EasterCalculate(quearyYear);
    //use easterDay to figure out easterMonth using function MonthCheck
    easterMonth = MonthCheck(easterDay);
    
    //fix easterDay based on the Month, if march do nothing, if april subtract 31
    if (easterMonth == "April") {
        easterDay -= 31;
    }

    //check to see if we need to add the month
    if (quearyYear == currentYear) {
        cout << "Please enter the current month as a number: ";
        cin >> currentMonth;
    }
    //check to see if we need to add the day
    if ((currentMonth ==  3) && (easterMonth == "March")) {
        cout << "Please enter the current day as a number: ";
        cin >> currentDay;
    }
    else if ((currentMonth == 4) && (easterMonth == "April")) {
        cout << "Please enter the current day as a number; ";
        cin >> currentDay;
    }
    
    //check to see if the current day, matches the easter day, if it does, print special reminder
    if (currentDay == easterDay) {
        cout << "EASTER IS TODAY! GET A FEW EGGS AND GO CELEBRATE USER!";
        exit(EXIT_SUCCESS);
    }
    
    //figure out the tense BASED ON THE YEAR
    if (quearyYear < currentYear) {
            tense = " was ";
    }
    else if (quearyYear > currentYear) {
            tense = " will be ";
    }
    else if ((quearyYear == currentYear) && (currentMonth > 3 && easterMonth == "March")) {
        tense = " will be ";
    }
    else if (quearyYear == currentYear) && (currentMonth )
    
    //IF THE YEARS WERE THE SAME, THEN CHECK THE MONTHS FOR THE TENSE

    
    //else if (quearyYear == currentYear) && (currentMonth >) FIXMEFIXMEFIXMEFIXME
    
    //print out the inputs given
    cout << "The current year is " << currentYear << ". The year you have selected to find the date of";
    cout << " Easter is " << quearyYear << endl;
    

    
    //print out the answer line, proper tense, proper year, proper date.
    cout << "Easter in the year " << currentYear << tense << " " << easterMonth << " " << easterDay;

    
    
    //print out a goodbye message
    
    return 0;
}

//function implementations

//function to check that the given year is within the allowed range
void DateCheck(int year) {
    if ((year < MINIMUMYEAR) || (year > MAXIMUMYEAR)) {
        cout << "Damnit user, I warned you about this! You will pay for your disobedience!!!!" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        return;
    }
}

//function to return the calculated easterDay given a queary year
int EasterCalculate(int quearyYear) {
    int easterDay;
    int a = quearyYear % 19;
    int b = quearyYear % 4;
    int c = quearyYear % 7;
    int d = ((19 * a) + 24) % 30;
    int e = ((2 * b) + (4 * c) + (6 * d) + 5) % 7;
    
    easterDay = (22 + d + e);
    
    if (((quearyYear == 1954) || (quearyYear == 1981)) || ((quearyYear == 2049) || (quearyYear == 2076))){
        easterDay = easterDay - 7;
        
        return easterDay;
    }
    else {

        return easterDay;
    }
}

//function to determine whether the easter month will be March, or April given an easter day.
string MonthCheck(int easterDay) {
    string easterMonth;
    if (easterDay > 31) {
        string easterMonth = "April";
        return easterMonth;
    }
    else {
        easterMonth = "March";
        return easterMonth;
    }
}
