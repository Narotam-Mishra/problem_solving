
#include<bits/stdc++.h>
using namespace std;

// utility function to parse a date string in "YYYY-MM-DD" format and return a tm struct.
tm parseDate(const string& dateStr){
    tm date = {};
    stringstream ss(dateStr);
    
    // parse date in YYYY-MM-DD format
    ss >> get_time(&date, "%Y-%m-%d");
    return date;
}

int daysBetweenDates(string date1, string date2) {
    // parse input date string
    tm d1 = parseDate(date1);
    tm d2 = parseDate(date2);

    // convert tm structs to time_t (seconds since epoch)
    time_t t1 = mktime(&d1);
    time_t t2 = mktime(&d2);

    // calculate the absolute difference in seconds and convert to days
    double diffInSeconds = difftime(t1, t2);
    return abs(diffInSeconds) / (60 * 60 * 24);
}

int main(){
    // string date1 = "2019-06-29", date2 = "2019-06-30";

    string date1 = "2020-01-15", date2 = "2019-12-31";
    cout<<daysBetweenDates(date1, date2)<<endl;
    return 0;
}