
// Problem link : https://leetcode.com/problems/convert-date-to-binary/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

string convertDateToBinary(string date) {
    stringstream ss(date);
    string part;
    vector<string> binaryParts;

    // split the date string by '-'
    while(getline(ss, part, '-')){
        // convert each part to an integer and then to a binary string
        int num = stoi(part);
        binaryParts.push_back(bitset<16>(num).to_string());
    }

    // remove leading zeroes from each binary part
    for(auto& binary : binaryParts){
        // trim leading zeroes from each part
        binary.erase(0, binary.find_first_not_of('0'));

        // handle zero case
        if(binary.empty()) binary = "0";
    }

    // join parts with '-'
    string res;
    for(size_t i = 0; i < binaryParts.size(); i++){
        res += binaryParts[i];
        if(i < binaryParts.size() - 1){
            res += "-";
        }
    }
    // return the result 'res`
    return res;
}

int main(){
    // string date = "2080-02-29";

    string date = "1900-01-01";
    cout<<convertDateToBinary(date);
    return 0;
}