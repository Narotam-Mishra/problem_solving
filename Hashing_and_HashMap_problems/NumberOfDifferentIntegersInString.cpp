
// Problem link - https://leetcode.com/problems/number-of-different-integers-in-a-string/?envType=problem-list-v2&envId=hash-table

#include<bits/stdc++.h>
using namespace std;

int numDifferentIntegers(string word) {
    // define a set to store the numbers
    unordered_set<string> s;
    
    // step 1 - iterate over the string and check if the character is a digit
    for(int i=0;i<word.size();i++){
        if(isdigit(word[i])){
            string num = "";
            while(i<word.size() && isdigit(word[i])){
                num += word[i];
                i++;
            }

            // step 2 - remove leading zeros
            while(num.size()>1 && num[0]=='0'){
                num.erase(num.begin());
            }

            // step 3 - insert the number in the set
            s.insert(num);
        }
    }

    // step 4 - return the size of the set
    return s.size();
}

int main(){
    // string word = "a123bc34d8ef34";

    // string word = "leet1234code234";

    string word = "a1b01c001";
    cout<<numDifferentIntegers(word)<<endl;
    return 0;
}