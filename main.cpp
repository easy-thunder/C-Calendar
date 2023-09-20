#include <iostream>
#include <string>
#include<cmath>
#include <iomanip>
#include <ios>
using namespace std;


int main(){

//////////////////below is days of week for regular calendar and how January 1st of year 0001 is. Also my months are here and setting the structure of my calendar /////////////////////////////////
const string days_of_week[]{  "saturday", "sunday", "monday", "tuesday", "wednesday", "thursday", "friday"}; // year 0001 january 1st in the julius calendar was a saturday so that is where we start the array we started with this before the gregorian calendar and day 1 is still on saturday

const string calendar_days_of_week[]{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};// The array We use for our regular calendar and correctly style the table.
const string months[]{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


const int end_of_row=7;
const int columns=6;

////////////////below is the prompt for a user entering the year//////////////////////////
unsigned int input_year {};
cout << "please select a year (AD)" << endl;
cin >> input_year;

//////////////// below is an equation that determines which day is the start of the year. The output correlates with a number on the array above of days_of_week////////////////////////////////////////////////////////
int first_day_data = (((floor((input_year-1)/4))+input_year));
int first_day_of_calendar = first_day_data%7;
// determine whether calendar needs extra day in February
bool leap_year {};


// I converted day 0 to day 7 which will work with how I set up my rows on the days of the week. This was the quickest way to convert the array (days of week) to what we use (sun, mon, tues, wed, thurs, fri, sat, sun)
if(first_day_of_calendar==0){
    first_day_of_calendar=7;
}
//determine if leap year is true will determine whether february has 28 or 29 days.
if(input_year%4==0){
    leap_year=true;
}
else{leap_year=false;}





//////////////////////////////////////// loop for month starting at January the days in month, day count, and last day found had to be in this scope./////////////////////////////////////////
for(string month : months){
    int days_in_month {};
    int day_count{1};
    bool last_day_found{false};


    if(month == "January" || month=="March" || month=="May" || month=="July" || month=="August"|| month=="October"|| month=="December"){days_in_month=31;}
    if(month=="April" || month=="June" || month=="September"|| month=="November"){days_in_month=30;}
    if(month=="February"&&leap_year==false){days_in_month=28;}
    if(month=="February"&&leap_year==true){days_in_month=29;}


    cout << setw(50)<< month << endl;
    cout << "----------------------------------------------------------------------------------------------"<<endl;
    for(string day : calendar_days_of_week){
        cout << setw(9) << day;
        if(day!="Saturday"){cout<< setw(5)<<"|";}
    }
    cout << endl;

    cout << "----------------------------------------------------------------------------------------------"<<endl;
    ////////////////////////// Below is table structure and the logic to put the dates in the squares of the calendar.//////////////////////////////////////
for(int i=1; i<=columns; i++){
/// I know it is a nested loop in a nested loop. Theoretically this would increase O of N. However, the dataset is so small this won't be noticed in speed.

    for(int j=1; j<=end_of_row; j++){
        if(last_day_found){break;}// stop the loop and don't run this loop anymore if the last day is found
            if(i==1){
                if(first_day_of_calendar>j){// if we are in the first row and if the table cell is lower than the first day place a blank space.
            cout<< setw(14)<< right<<"|";
        }
        if(first_day_of_calendar<=j){// if we are in the first row and if the table cell equals or is above the first day of the calendar then print the day in that table cell and increase day count.
            cout<< setw(7)<< day_count << setw(7)<< "|";
            day_count++;
        }
        
        

            }
            else if(day_count<=days_in_month){// we are in the second column now and we want to print the day on the cell unless we go above how many days are in that month
                cout<< setw(7)<< day_count << setw(7)<< "|";
                day_count++;
                }
            else{// else the day count is higher than days in month we want to report where the first day is on the next month!
                first_day_of_calendar=j;
                cout<<first_day_of_calendar;
                last_day_found=true;
                
                
            }
    }
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------"<<endl;
}
/////////////////// making more space between the months//////////////////////////
cout << endl;
cout << endl;
cout << endl;
cout << endl;

    

}







 
    return 0;
}