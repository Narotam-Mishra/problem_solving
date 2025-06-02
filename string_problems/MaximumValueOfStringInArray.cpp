
// Problem link - https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/description/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

// utility fucntion to check given string is numeric or not
bool isNumeric(const string& str) {
    size_t start = 0;
    for (size_t i = start; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int maximumValue(vector<string>& strs) {
    // step 1 - initialize variable to find maximum value of `strs`
    int maxVal = 0;

    // step 2 - iterate on each str of `strs` 
    for (string str : strs) {
        if (!isNumeric(str)) {
            // step 3 - if str is not number then find its length
            int n = str.size();

            // and update maximum value
            maxVal = max(maxVal, n);
        }
        else {
            // step 4 - otherwise find maximum numeric value
            maxVal = max(maxVal, stoi(str));
        }
    }

    // step 5 - return maximum value
    return maxVal;
}

int main(){
    // vector<string> strs = {"alic3","bob","3","4","00000"};

    vector<string> strs = {"1","01","001","0001"};
    cout<<maximumValue(strs)<<endl;
    return 0;
}