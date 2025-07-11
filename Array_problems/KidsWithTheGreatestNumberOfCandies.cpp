
// Problem link - https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    // store result in `res` list
    vector<bool> res;

    // step 1 - find maximum number of candies
    int maxNumCandy = -1;
    for (int num : candies) {
        if (num > maxNumCandy) {
            maxNumCandy = num;
        }
    }

    // step 2 - iterate on each candy from `candies`
    for (int numCandy : candies) {
        // step 3 - check if kid has greatest number of candies among all or not
        if (numCandy + extraCandies >= maxNumCandy) {
            // add true
            res.push_back(true);
        }
        else {
            // otherwise add false
            res.push_back(false);
        }
    }

    // step 4 - return resultant array `res`
    return res;
}

void printVector(vector<bool>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << (vec[i] ? "true" : "false");
        if (i < vec.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main(){
    // vector<int> candies = {2,3,5,1,3};
    // int extraCandies = 3;

    // vector<int> candies = {4,2,1,1,2};
    // int extraCandies = 1;

    vector<int> candies = {12,1,12};
    int extraCandies = 10;
    vector<bool> res = kidsWithCandies(candies, extraCandies);
    printVector(res);
    return 0;
}