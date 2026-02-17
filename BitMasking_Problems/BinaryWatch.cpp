
// Problem link - https://leetcode.com/problems/binary-watch/description/?envType=daily-question&envId=2026-02-17

#include<bits/stdc++.h>
using namespace std;

vector<string> readBinaryWatch(int turnedOn) {
    vector<string> res;

    // step 1 - iterate on each hour
    for(int h=0; h<12; h++){
        // step 2 - iterate on each minute of a hour
        for(int m=0; m<60; m++){
            // step 3 - check if sum of set bits of hour and minute equal to `turned`
            if(__builtin_popcount(h) + __builtin_popcount(m) == turnedOn){
                // step 4 - form this time and add into `res`
                string hour = to_string(h);
                string minute = (m < 10 ? "0" : "") + to_string(m);

                res.push_back(hour + ":" + minute);
            }
        }
    }

    // step 5 - return final result `res`
    return res;
}

void printVector(vector<string>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

int main(){
    // int turnedOn = 1;

    // int turnedOn = 2;

    int turnedOn = 9;
    vector<string> res = readBinaryWatch(turnedOn);
    printVector(res);
    return 0;
}