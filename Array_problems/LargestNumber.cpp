
#include<bits/stdc++.h>
using namespace std;

string largestNumber(vector<int>& nums) {
    // convert the integer vector to a string vector for comparison
    vector<string> strNums;

    for(int num : nums){
        string val = to_string(num);
        strNums.push_back(val);
    }

    // custom comparator to compare concatenated strings
    sort(strNums.begin(), strNums.end(), [](string &a, string &b){
        // sort in descending order
        return a + b > b + a;
    });

    // if the largest number is "0", return "0"
    if(strNums[0] == "0"){
        return "0";
    }

    // concatenate the sorted strings
    string largestNum;
    for(string &num : strNums){
        largestNum += num;
    }

    // return largest number in string form
    return largestNum;
}

int main(){
    vector<int> nums = {3, 30, 34, 5, 9};
    cout<<largestNumber(nums);
    return 0;
}