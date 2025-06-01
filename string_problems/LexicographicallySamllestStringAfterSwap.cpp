
// Problem link - https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/description/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

bool haveSameParity(char a, char b) {
    int num1 = a - '0';
    int num2 = b - '0';
    return (num1 % 2) == (num2 % 2);
}

string getSmallestString(string s) {
    // step 1 - convert string `s` to character array for easy iteration
    int n = s.size();

    // step 2 - scan each digit from left to right
    for(int i=0; i<n-1; i++){
        char currChar = s[i];
        char nextChar = s[i+1];

        // step 3 - check if adjacent digits have same parity AND swapping would make string smaller
        if(haveSameParity(currChar, nextChar) && currChar > nextChar){
            // perform swapping as above conditions satisfied
            swap(s[i], s[i+1]);

            // step 4 - return immediately after first swap (at most one swap allowed)
            return s;
        }
    }

    // step 5 - otherwise return original string `s`
    return s;
}

int main(){
    // string s = "45320";

    string s = "001";
    cout<<getSmallestString(s)<<endl; 
    return 0;
}