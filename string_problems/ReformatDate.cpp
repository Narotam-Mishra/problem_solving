
#include<bits/stdc++.h>
using namespace std;

string reformatDate(string date) {
    // step 1: split the input string into day, month, year
    stringstream ss(date);
    string day, month, year;
    ss >> day >> month >> year;

    // step 2: remove the last two characters from day ("th", "st", "nd", "rd")
    day = day.substr(0, day.size()-2);
    
    // step 3: convert the day to 2-digit format if necessary
    if(day.size() == 1) {
        day = "0" + day; 
    }
    
    // step 4: create a map to convert the 3-letter month to 2-digit numeric value
    unordered_map<string, string> monthMap = {
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
        {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
        {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
    };
    
    // step 5: get the numeric month from the map
    string numericMonth = monthMap[month];
    
    // step 6: combine everything into YYYY-MM-DD format
    string formattedDate = year + "-" + numericMonth + "-" + day;
    
    // step 7: return the formatted date
    return formattedDate;
}

int main(){
    // string date = "20th Oct 2052";

    // string date = "6th Jun 1933";

    string date = "26th May 1960";
    cout<<reformatDate(date)<<endl;
    return 0;
}