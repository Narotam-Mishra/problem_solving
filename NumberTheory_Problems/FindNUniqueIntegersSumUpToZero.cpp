
// Problem link - https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/?envType=daily-question&envId=2025-09-07

#include<bits/stdc++.h>
using namespace std;

vector<int> sumZero(int n) {
    // store result in `res`
    vector<int> res(n, 0);

    // keep track of index
    int index = 0;

    // edge case - if `n` is odd add 0 in resutant array `res`
    if(n % 2 == 1){
        res[index++] = 0;
    }

    // step 1 - iterate from 1 to n/2 
    for(int i=1; i<=n/2; i++){
        // step 2 - add number and its negative that can sum up to 0
        res[index++] = i;
        res[index++] = -i;
    }

    // step 3 - return res
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
    // int n = 5;

    // int n = 3;

    int n = 1;
    vector<int> res = sumZero(n);
    printVector(res);
    return 0;
}