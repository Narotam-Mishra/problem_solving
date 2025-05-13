
#include<bits/stdc++.h>
using namespace std;

bool areNumbersAscending(string s) {
    // step 1 - to tokenize the sentence by spaces
    istringstream iss(s);  
    string token;

    // initialize with the smallest possible int value
    int prevNumber = INT_MIN;  

    // valid positive number without leading zeros
    regex numberRegex("^[1-9][0-9]*$");  

    // step 2 - iterate on each token of `s`
    while (iss >> token) {
        if (regex_match(token, numberRegex)) {
            // convert string to int
            int currentNumber = stoi(token);  
            if (currentNumber <= prevNumber) {
                // numbers not strictly increasing
                return false;  
            }

            // update last seen number
            prevNumber = currentNumber;  
        }
    }

    // step 3 - all numbers in strictly increasing order
    return true;  
}

int main(){
    // string s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles";

    // string s = "hello world 5 x 5";

    string s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s";
    bool res = areNumbersAscending(s);
    res ? cout<<"true" : cout<<"false";
    return 0;
}
