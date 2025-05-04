
// Problem link - https://leetcode.com/problems/number-of-valid-clock-times/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int countTime(string time) {
    // step 1 - store final result in `res`
    int res = 1;

    // step 2 - get hours and minutes
    string hours = time.substr(0, 2);
    string minutes = time.substr(3, 2);

    // step 3 - handling hours
    if(hours == "??"){
        res *= 24;
    }else{
        if(hours[0] == '?'){
            if(hours[1] > '3'){
                res *= 2;
            }else{
                res *= 3;
            }
        }

        if(hours[1] == '?'){
            if(hours[0] == '2'){
                res *= 4;
            }else{
                res *= 10;
            }
        }
    }

    // step 4 - handling minutes
    if(minutes[0] == '?'){
        res *= 6;
    }
    if(minutes[1] == '?'){
        res *= 10;
    }

    // step 5 - return final result
    return res;
}

int main(){
    // string time = "?5:00";

    // string time = "0?:0?";

    string time = "??:??";
    cout<<countTime(time)<<endl;
    return 0;
}