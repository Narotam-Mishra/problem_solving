
// Problem link - https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/?envType=daily-question&envId=2026-03-01

#include<bits/stdc++.h>
using namespace std;

int minPartitions1(string n) {
    // keep track of how many deci-binary numbers we use
    int minCount = 0;

    // step 1 - keep substracting layers until all digits become zero
    while(true){
        // flag to check whether any digit was reduced
        bool changed = false;

        // step 2 - traverse on each digit
        for(char& ch : n){

            // step 3 - check if digit is non-zero
            if(ch != '0'){
                // substract 1 from digit
                ch--;

                // mark changed flag as true since we modified
                changed = true;
            }
        }

        // step 4 - check If no digit was reduced
        if(!changed){
            // it means all digits are zero
            break;
        }

        // step 5 - one full subtraction layer completed, so increment
        minCount++;
    }

    // step 6 - minimum number of positive deci-binary numbers
    // needed for this operation
    return minCount;
}

int minPartitions(string n) {
    // step 1 - find and return maximum digit in the string
    char ch = *max_element(n.begin(), n.end());
    return ch - '0';
}

int main(){
    string n = "32";

    // string n = "82734";

    // string n = "27346209830709182346";
    cout<<minPartitions(n);
    return 0;
}