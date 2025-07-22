
// Problem link - https://leetcode.com/problems/number-of-employees-who-met-the-target/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
    // store the count of employees who worked at least target hours in `count`
    int count = 0;

    // step 1 - iterate on each hour
    for (int hour : hours) {

        // step 2 - check if working hour is greater than or equal to target hour
        if (hour >= target) {
            // increment counter
            count++;
        }
    }

    // step 3 - return counter `count`
    return count;
}

int main(){
    // vector<int> hours = {0,1,2,3,4};
    // int target = 2;

    vector<int> hours = {5,1,4,2,2};
    int target = 6;
    cout<<numberOfEmployeesWhoMetTarget(hours, target);
}