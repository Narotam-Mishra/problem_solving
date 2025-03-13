
#include<bits/stdc++.h>
using namespace std;

int countBinarySubstrings(string s) {
    // step 1 - variable intialization
    int prevGroup = 0, currGroup = 1, count = 0;

    // step 2 - iterate on input string
    for(int i=1; i<s.size(); i++){
        if(s[i] == s[i-1]){
            // extend current group if current and previous digits are equal
            currGroup++;
        }else{
            // otherwise count valid substring
            count += min(currGroup, prevGroup);

            // move to new group
            prevGroup = currGroup;

            // reset counter for the new group
            currGroup = 1;
        }
    }

    // step 3 - count last valid substring
    return count + min(currGroup, prevGroup);
}

int main(){
    // string s = "00110011";

    string s = "10101";
    cout<<countBinarySubstrings(s)<<endl;
    return 0;
}