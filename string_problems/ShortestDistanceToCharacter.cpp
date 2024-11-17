
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestToChar(string s, char c) {
    int len = s.length();
    // initialize result array with Infinity
    vector<int> res(len, INT_MAX);

    // represents the last seen position of 'c' (left to right)
    int prev = INT_MAX;

    // traverse from left to right
    for (int i = 0; i < len; i++) {
        if (s[i] == c) {
            // update the position of 'c'
            prev = i;
        }
        // calculate distance from the nearest 'c' so far
        res[i] = abs(i - prev);
    }

    // reset prev for the second pass
    prev = INT_MAX;

    // traverse from right to left
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == c) {
            prev = i;
        }
        // take smaller absolute distance
        res[i] = min(abs(i - prev), res[i]);
    }
    // return the result array
    return res;
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
    string str = "loveleetcode";
    char ch = 'b';
    vector<int> res = shortestToChar(str, ch);
    printVector(res);
    return 0;
}