
// Problem link - https://leetcode.com/problems/finding-3-digit-even-numbers/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

bool canFormNumber(vector<int>& requiredDigits, unordered_map<int, int>& availableDigits) {
    // count how many of each digit we need
    unordered_map<int, int> neededMap;
    for (int digit : requiredDigits) {
        neededMap[digit]++;
    }

    // check if we have enough of each required digits
    for (const auto& entry : neededMap) {
        int digit = entry.first;
        int count = entry.second;
        auto it = availableDigits.find(digit);
        int available = (it != availableDigits.end()) ? it->second : 0;
        if (available < count) {
            return false;
        }
    }

    return true;
}

vector<int> findEvenNumbers1(vector<int>& digits) {
    // step 1 - store frequency of each digit in `digitsMap` map
    unordered_map<int, int> digitsMap;
    for (int digit : digits) {
        digitsMap[digit]++;
    }

    // step 2 - check each possible even 3-digit number from 100 to 999
    vector<int> validEvenNums;
    for (int num = 100; num <= 999; num += 2) {
        // step 3 - extract each digit from current number
        int hundreds = num / 100;
        int tens = (num % 100) / 10;
        int units = num % 10;

        // step 4 - check if we can form this number from available digits in `digitsMap`
        vector<int> requiredDigits = { hundreds, tens, units };
        if (canFormNumber(requiredDigits, digitsMap)) {
            validEvenNums.push_back(num);
        }
    }

    // step 5 - return `validEvenNums` array as it is already sorted
    return validEvenNums;
}

vector<int> findEvenNumbers(vector<int>& digits) {
    // step 1 - count frequency of each digit of `digits`
    vector<int> counts(10, 0);
    for (int digit : digits) {
        counts[digit]++;
    }

    // step 2 - check each possible even 3-digit number from 100 to 999
    vector<int> validEvenNums;
    for (int num = 100; num <= 999; num += 2) {
        // step 3 - extract each digit from current number
        int hundreds = num / 100;
        int tens = (num % 100) / 10;
        int units = num % 10;

        // step 4 - check if we can form this number from available digits in `digitsMap`
        counts[hundreds]--, counts[tens]--, counts[units]--;
        if(counts[hundreds] >= 0 && counts[tens] >= 0 && counts[units] >= 0){
            // store this number into valid even number array
            validEvenNums.push_back(num);
        }

        // step 5 - restore the count to check other combination of number
        counts[hundreds]++, counts[tens]++, counts[units]++;
    }

    // step 6 - return `validEvenNums` array as it is already sorted
    return validEvenNums;
}

void printVector(vector<int>& vec){
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
    vector<int> digits = {2,1,3,0};

    // vector<int> digits = {2,2,8,8,2};

    // vector<int> digits = {3,7,5};
    vector<int> res = findEvenNumbers(digits);
    printVector(res);
}