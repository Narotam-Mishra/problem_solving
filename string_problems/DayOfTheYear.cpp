
// Problem link : https://leetcode.com/problems/day-of-the-year/description/?envType=problem-list-v2&envId=string&difficulty=EASY&status=TO_DO

#include<bits/stdc++.h>
using namespace std;

int dayOfYear(string date) {
    // create a tm struct to hold the date components
    // this line tm tm = {}; is initializing a std::tm struct in C++.
    tm tm = {};

    // convert the date string to a tm struct
    istringstream ss(date);
    ss >> get_time(&tm, "%Y-%m-%d");

    // get the time value for the start of the current year
    time_t start_of_year = mktime(&tm);

    // set the date to January 1st of the current year
    tm.tm_mday = 1;
    tm.tm_mon = 0;
    time_t start_of_current_year = mktime(&tm);

    // calculate the difference in seconds between the given date and January 1st
    // and convert to days by dividing by 86400 (seconds per day)
    // add 1 to get the day of the year (since January 1st is day 1)
    return static_cast<int>(difftime(start_of_year, start_of_current_year) / 86400) + 1;
}

int main(){
    string date = "2019-02-10";
    cout<<dayOfYear(date);
    return 0;
}