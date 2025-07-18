
// Problem link - https://leetcode.com/problems/pascals-triangle-ii/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<int> getRow(int rowIndex) {
    // store result in `res`
    vector<int> res;
    res.push_back(1);

    // edge case: if rowIndex is 0, return [1]
    if (rowIndex == 0) {
        return res;
    }

    // step 1 - generate each row of Pascal's triangle
    // using formula - C(n,i) = C(n,i-1) * (n-i+1) / i
    // where `n` is rowIndex and `i` is the current position
    for (int i = 1; i <= rowIndex; i++) {
        // step 2 - calculate next element based on previous element
        long long nextVal = (long long)res[i - 1] * (rowIndex - i + 1) / i;

        // store in result `res`
        res.push_back((int)nextVal);
    }

    // step 3 - return result `res`
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
    // int rowIndex = 3;

    // int rowIndex = 1;

    // int rowIndex = 0;

    int rowIndex = 2;
    vector<int> res = getRow(rowIndex);
    printVector(res);
    return 0;
}