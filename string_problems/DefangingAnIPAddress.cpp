
// Problem link - https://leetcode.com/problems/defanging-an-ip-address/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string defangIPaddr(string address) {
    string result;
    for (char c : address) {
        if (c == '.') {
            result += "[.]";
        } else {
            result += c;
        }
    }
    return result;
}

int main(){
    string address = "1.1.1.1";
    cout<<defangIPaddr(address)<<endl;
    return 0;
}