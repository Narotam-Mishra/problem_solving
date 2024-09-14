
// Problem link : https://leetcode.com/problems/counting-bits/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
    vector<int> res(n+1);
    int setBits = 0;

    // loop through all numbers from 0 to n
    for(int i=0; i<=n; i++){
        int num = i;

        // reset setBits counter for each number
        setBits = 0;

        // count the number of 1's in the binary representation of num
        while(num > 0){
            // increment if the least significant bit is 1
            setBits += num & 1;
            // right shift num by 1 bit
            num = num >> 1;
        }
        // store the result at correct index
        res[i] = setBits;
    }
    // return result 'res' array
    return res;
}

int main(){
    int n = 5;
    vector<int> res = countBits(n);

    for(int num : res){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}