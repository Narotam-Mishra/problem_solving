
#include<bits/stdc++.h>
using namespace std;

string restoreString(string s, vector<int>& indices) {
    // step 1: Create an empty array of the same length as the string
    vector<char> shuffled(s.length());

    // step 2: iterate through each character of the string and place it at the correct index.
    for(int i=0; i<s.length(); i++){
        shuffled[indices[i]] = s[i];
    }

    // step 3: Convert the array back to a string and return it.
    return string(shuffled.begin(), shuffled.end());
}

int main(){
    // string str = "codeleet";
    // vector<int> indices = {4,5,6,7,0,2,1,3};

    string str = "abc";
    vector<int> indices = {0,1,2};
    cout<<restoreString(str, indices)<<endl;
    return 0;
}