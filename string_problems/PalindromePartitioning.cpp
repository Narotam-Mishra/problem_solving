
// Problem link - https://leetcode.com/problems/palindrome-partitioning/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

// utility function to check if a string is a palindrome
bool isPalindrome(const string& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

// use recursive function to explore all possible partitions
void backtrack(const string &s, int start, vector<string> &path, vector<vector<string>> &res) {
    // base case: if we have reached the end of string
    if (start == s.length()) {
        res.push_back(path);
        return;
    }

    // recursive case: explore all substrings from start to end
    for (int end = start + 1; end <= s.length(); end++) {
        string substr = s.substr(start, end-start);

        // check for pallindrome string
        if (isPalindrome(substr)) {
            path.push_back(substr);
            backtrack(s, end, path, res);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> path;
    backtrack(s, 0, path, result);
    return result;
}

void print2DVector(vector<vector<string>>& matrix){
    cout << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < matrix.size() - 1) cout << ",";
    }
    cout << "]" << std::endl;
}

int main(){
    string s = "aab";
    vector<vector<string>> res = partition(s);
    print2DVector(res);
    return 0;
}