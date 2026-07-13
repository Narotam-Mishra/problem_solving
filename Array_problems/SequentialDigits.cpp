
// Problem link - https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2026-07-13

#include<bits/stdc++.h>
using namespace std;

vector<int> sequentialDigits(int low, int high) {
    // keep track of final result in `res`
    vector<int> res;

    // step 1 - try every possible digit from 1 to 9
    for(int s=1; s<=9; s++){
        int num = 0;

        // append digits from start, `s` upward
        for(int digit=s; digit<=9; digit++){
            // 12 -> 123
            num = num*10 + digit;

            // step 2 - formed number should not be greater than, `high`
            if(num > high) break;

            // step 3 - we need numbers inside the given range
            if(num >= low){
                res.push_back(num);
            }
        }
    }

    // step 4 - sort the result, `res`
    sort(res.begin(), res.end());

    // step 5 - return final result, `res`
    return res;
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
    // int low = 100, high = 300;

    int low = 1000, high = 13000;
    vector<int> res = sequentialDigits(low, high);
    printVector(res);
    return 0;
}