
// Problem link - https://leetcode.com/problems/find-the-divisibility-array-of-a-string/

#include<bits/stdc++.h>
using namespace std;

vector<int> divisibilityArray(const string& word, int m) {
    // step 1 - use `div` array to store result
    int n = word.size();
    vector<int> div(n, 0);
    long currMod = 0;

    // step 2 - iterate on each digit of string `word`
    for (int i = 0; i < n; i++) {
        // step 3 - convert the current digit character to integer
        int digit = word[i] - '0';

        // step 4 - update the running modulo using rolling formula
        currMod = (currMod * 10 + digit) % m;

        // step 5 - if current number from word[0..i] is divisible by m, mark as 1
        div[i] = (currMod == 0) ? 1 : 0;
    }

    // step 6 - return resultant `div`
    return div;
}

void printVector(vector<int>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

int main(){
    // string word = "998244353";
    // int m = 3;

    string word = "1010";
    int m = 10;
    vector<int> res = divisibilityArray(word, m);
    printVector(res);
    return 0;
}