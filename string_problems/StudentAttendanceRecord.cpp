
#include<bits/stdc++.h>
using namespace std;

bool checkRecord(string s) {
    // step 1: count the number of absences ('A')
    int numOfAbsences = 0;
    for (char ch : s) {
        if (ch == 'A') {
            numOfAbsences++;
            if (numOfAbsences >= 2) {
                // early exit if absences are 2 or more
                return false;
            }
        }
    }

    // step 2: check for 3 or more consecutive 'L's
    if (s.find("LLL") != string::npos) {
        return false;
    }

    // if both conditions are satisfied, the student is eligible
    return true;
}

int main(){
    // string str = "PPALLP";

    string str = "PPALLL";
    bool res = checkRecord(str);
    res ? cout<<"true" : cout<<"false";
}