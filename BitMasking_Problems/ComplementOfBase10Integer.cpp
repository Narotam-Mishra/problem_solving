
#include<bits/stdc++.h>
using namespace std;

int bitwiseComplement(int n) {
    // edge case
    if(n == 0){
        return 1;
    }
    // step 1: find the bit length of the number
    int bitLength = log2(n) + 1;

    // step 2: create a mask of the same length with all bits set to 1
    unsigned int bitMask = (1U << bitLength) - 1;

    // step 3: XOR the number with the mask to get the complement
    return bitMask ^ n;
}

int main(){
    // int num = 5;

    // int num = 7;

    int num = 10;
    cout<<bitwiseComplement(num);
    return 0;
}