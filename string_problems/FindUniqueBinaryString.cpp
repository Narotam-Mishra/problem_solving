
// Problem link - https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2026-03-08

#include<bits/stdc++.h>
using namespace std;

string findDifferentBinaryString1(vector<string>& nums) {
    int n = nums.size();

    // step 1 - prepare set of input binary numbers (in decimal form)
    unordered_set<int> seen;
    for(string &str : nums){
        // convert each binary string to decimal number
        int decVal = stoi(str, 0, 2);
        seen.insert(decVal);
    }

    // step 2 - iterate on number from 0 to n
    for(int num=0; num<=n; num++){
        // step 3 - check if number, `num` exist in set or not
        if(!seen.count(num)){
            // convert number back to string
            string temp = bitset<16>(num).to_string();

            // step 4 - retun the number by removing tailing zeroes
            return temp.substr(16-n, n);
        }
    }

    return "";
}

string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();

    // empty string, `res` to store the result
    string res = "";

    // step 1 - use Cantor's diagonal argument to construct unique binary string
    // Iterate through each position i from 0 to n-1
    for(int i = 0; i < n; i++){
        // step 2 - extract the character at diagonal position [i][i]
        char ch = nums[i][i];

        // step 3 - flip the bit (0 becomes 1, 1 becomes 0)
        // this guarantees the result differs from every input string
        if(ch == '0'){
            res += "1";
        } else {
            res += "0";
        }
    }

    // step 4 - return the constructed unique binary string
    return res;
}

int main(){
    vector<string> nums = {"01","10"};

    // vector<string> nums = {"111","011","001"};
    cout<<findDifferentBinaryString(nums);
    return 0;
}