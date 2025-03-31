
// Problem link - https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int minimumChairs(string s) {
    // step 1 - intialize all necessary variables
    int currentOccupancy = 0;
    int maxNumberOfChairs = 0;

    // step 2 - iterate on each character of input `s`
    for(char ch : s){
        if(ch == 'E'){
            // step 3 - increment current occupancy for each entry
            currentOccupancy++;

            // step 4 - update max chairs needed if current occupancy exceed
            if(currentOccupancy > maxNumberOfChairs){
                maxNumberOfChairs = currentOccupancy;
            }
        }else{
            // step 5 - decrement current occupancy for each leave
            currentOccupancy--;
        }
    }

    // step 6 - return max number of chairs
    return maxNumberOfChairs;
}

int main(){
    // string s = "EEEEEEE";

    // string s = "ELELEEL";

    string s = "ELEELEELLL";
    cout<<minimumChairs(s)<<endl;
    return 0;
}