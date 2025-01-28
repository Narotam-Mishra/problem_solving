
// Problem link : https://leetcode.com/problems/second-largest-digit-in-a-string/description/?envType=problem-list-v2&envId=hash-table

#include<bits/stdc++.h>
using namespace std;

int secondHighest(string s) {
    // step 1 - initialize largest and second largest variables
    int largest = -1;
    int secondLargest = -1;

    // step 2 - iterate through each character in the string
    for (char ch : s) {
        if (ch >= '0' && ch <= '9') {
            int digit = ch - '0';
            // step 3 - find second largest
            // if current digit is greater than largest
            if (digit > largest) {
                // current largest becomes second largest
                secondLargest = largest;

                // update largest
                largest = digit;

                // if digit is less than largest but greater than second largest
            }
            else if (digit < largest && digit > secondLargest) {
                secondLargest = digit;
            }
        }
    }

    // step 4 - return the second largest digit
    return secondLargest;
}

int main(){
    // string s = "dfa12321afd";

    string s = "abc1111";
    cout<<secondHighest(s)<<endl;
    return 0;
}