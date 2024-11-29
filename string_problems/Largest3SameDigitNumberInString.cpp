
#include<bits/stdc++.h>
using namespace std;

string largestGoodInteger(string num) {
    // step 1: define the possible good integers in descending order
    vector<string> strNums = { "999", "888", "777", "666", "555", "444", "333", "222", "111", "000" };

    // step 2: iterate through the list and check if num contains the current good integer
    for (string strNum : strNums) {
        // step 3: check if the current good integer is a substring of num
        if (num.find(strNum) != string::npos) {
            // return the first match
            return strNum;
        }
    }
    // step 4: if no good integer is found, return an empty string
    return "";
}

int main(){
    // string num = "6777133339";

    // string num = "2300019";

    string num = "42352338";
    cout<<largestGoodInteger(num)<<endl;
    return 0;
}