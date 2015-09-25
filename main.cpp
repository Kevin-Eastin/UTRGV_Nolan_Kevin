//
//  main.cpp
//  EasterDateCalculator_A2
//
//  Created by Kevin Eastin on 9/24/15.
//  Copyright © 2015 Kevin Eastin. All rights reserved.
//


//Easter Date Calculator from the range of 1900 to 2099.

#include<string>    //To allow me to use string variables
#include<iostream>  //for basic outputting
#include<cstdlib> //included to use the exit() function to end the program at my leisure

using namespace std;

//global constants
const int MINIMUMYEAR = 1900;
const int MAXIMUMYEAR = 2099;

//function prototypes
void DateCheck(int year);               //checks that the year given is valid (hindsight: unecessary)
int EasterCalculate(int quearyYear);    //calculate the easterDAY
string MonthCheck(int easterDay);       //use easterDAY to calculate easterMONTH


//main function
int main() {
    //call variables
    int currentDay;    //inputed current day (only if current and monthNum are equal)
    int currentMonth; //inputed current month (only if current and queary year are equal
    int currentYear; //Inputed current year
    int quearyYear;  //Inputed year of desired easterDay
    int easterDay;  //calculated easterDay
    int monthNum; //integer version of easterMonth
    
    string easterMonth; //given by MonthCheck function
    string tense; //based on whether or not easter has happened yet
    
    
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
    
    
    //Assign a value to monthNum based on easterMonth, 3 if march, 4 if april
    //this simplifies later if's significantly.
    if (easterMonth == "March") {
        monthNum = 3;
    }
    else if (easterMonth == "April"){
        monthNum = 4;
    }
    //redo all the checks to be more readable and coherent. Use a reasonable logic you dolt.
    //first check the years, if equal ask for months.
    if (currentYear < quearyYear) {
        tense = "will be";
    }
    else if (currentYear > quearyYear) {
        tense = "was";
    }
    else if (currentYear == quearyYear) {
        cout << "Please enter the current month as a number (1-12 only): ";
        cin >> currentMonth;
    }
    //check that the month given is an acceptable figure. if it's not, SHUT IT DOWN
    if (currentMonth > 12 || currentMonth < 1) {
        cout << "GOSH DARN IT USER! FOLLOW THE DIRECTIONS!";
        exit(EXIT_FAILURE);
    }
    //then check the months (if years equal of course) use monthNum and currentMonth! if equal ask for days
    if (currentMonth > monthNum) {
        tense = "was";
    }
    else if (currentMonth < monthNum) {
        tense = "will be";
    }
    else if (currentMonth == monthNum) {
        cout << "Please enter the current DAY as a number: ";
        cin >> currentDay;
    }
    
    //THEN check the days (if months are equal of course) use easterDay and currentDay, if equal print special message and quit the program (successfully)
    if ((currentDay > easterDay) && (currentMonth == monthNum)) {
        tense = "was";
    }
    else if ((currentDay < easterDay) && (currentMonth == monthNum)) {
        tense = "will be";
    }
    else if (currentDay == easterDay) {
        cout << "EASTER IS TODAY! GET OUT AND CELEBRATE WOOOOOOHOOOOOOOOO!!!!!!!!!!!" << endl << endl;
        exit(EXIT_SUCCESS);
    }

    //print out the inputs given
    cout << endl << "The current year is " << currentYear << ". The year you have selected to find the date of";
    cout << " Easter is " << quearyYear << endl << endl;
    

    
    //print out the answer line, proper tense, proper year, proper date.
    cout << "Easter in the year " << quearyYear << " " << tense << " " << easterMonth << " " << easterDay;
    cout << endl << endl;

    
    
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

