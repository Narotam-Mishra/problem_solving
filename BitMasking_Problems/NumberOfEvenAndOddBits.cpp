
#include<bits/stdc++.h>
using namespace std;

vector<int> evenOddBit(int n) {
    int curBit = 0, pos = 0;
    vector<int> res(2, 0);
    // initialize counters for even and odd positions
    int oddCnt = 0, evenCnt = 0;

    // iterate through all bits of n until n becomes zero
    while (n > 0) {
        // isolate the least significant bit (LSB) by performing bitwise AND with 1
        curBit = n & 1;

        // if the current bit is 1, check its position and update the respective counter
        if (curBit == 1) {
            if ((pos & 1) == 1) {
                // if position is odd (pos & 1 equals 1), increment oddCnt
                oddCnt++;
            }
            else {
                // if position is even (pos & 1 equals 0), increment evenCnt
                evenCnt++;
            }
        }
        // right-shift n to process the next bit in the next iteration
        n = n >> 1;

        // increment the bit position counter
        pos++;
    }
    res[0] = evenCnt;
    res[1] = oddCnt;

    // return the counts of 1's at even and odd positions
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
    // int n = 50;

    int n = 2;
    vector<int> res = evenOddBit(n);
    printVector(res); 
    return 0;
}