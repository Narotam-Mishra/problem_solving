
// Problem link - https://leetcode.com/problems/calculate-digit-sum-of-a-string/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string digitSum(string s, int k) {
    // step 1 - continue processing while string length is greater than k
    while (s.length() > k) {
        // stores the new transformed string for this round
        string newStr = ""; 

        // step 2 - process the string in chunks of size k
        for (int i = 0; i < s.length(); i += k) {
            int sum = 0;

            // step 3 - sum the digits in the current group
            for (int j = i; j < i + k && j < s.length(); ++j) {
                sum += s[j] - '0'; // Convert character digit to integer
            }

            // step 4 - append the sum to the new string
            newStr += to_string(sum);
        }

        // step 5 - update s with the new string for the next round
        s = newStr;
    }

    // step 6 - return the final string once it's short enough
    return s;
}

int main(){
    // string s = "11111222223";
    // int k = 3;

    string s = "00000000";
    int k = 3;
    cout<<digitSum(s, k)<<endl;
    return 0;
}