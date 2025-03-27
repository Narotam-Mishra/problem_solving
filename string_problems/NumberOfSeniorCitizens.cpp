
// Problem link - https://leetcode.com/problems/number-of-senior-citizens/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int countSeniors(vector<string>& details) {
    // step 1 - initialize count
    int count = 0;

    // step 2 - iterate on each detail
    for(string data : details){
        // extract age from detail
        int age = stoi(data.substr(11,2));
        
        // step 3 - check if age is greater than 60
        if(age > 60){
            // increment count
            count++;
        }
    }

    // step 4 - return count
    return count;
}


int main(){
    // vector<string> details = {"7868190130M7522","5303914400F9211","9273338290F4010"};

    vector<string> details = {"1313579440F2036","2921522980M5644"};
    cout<<countSeniors(details)<<endl;
    return 0;
}