
// Problem link - https://leetcode.com/problems/lexicographical-numbers/description/

// Approach - using recursion

#include<bits/stdc++.h>
using namespace std;

void getLexicographicalOrderRecursion(int curNum, int n, vector<int>& res){
    // Base case: if the current number exceeds n, return
    if(curNum > n) return;

    // add current number curNum to result list res
    res.push_back(curNum);

    // Recursively call the recursive function for next numbers in lexical order (by multiplying by 10)
    getLexicographicalOrderRecursion(curNum * 10, n, res);

    //check if the last digit of the current number is not 9, recursively call for the next number
    if(curNum % 10 != 9) getLexicographicalOrderRecursion(curNum + 1, n, res);
}

vector<int> lexicalOrder(int n) {
    vector<int> res;
    getLexicographicalOrderRecursion(1, n, res);
    return res;
}

int main(){
    int n = 13;
    vector<int> ans = lexicalOrder(n);
    for(int num : ans){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}