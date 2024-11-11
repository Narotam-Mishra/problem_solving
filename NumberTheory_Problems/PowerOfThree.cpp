
#include<bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n) {
    // base case:
    if (n < 1) return false;

    // loop case:
    while (n % 3 == 0) {
        n = (int)n / 3;
    }
    return n == 1;
}

int main(){
    // int num = 27;

    // int num = 0;

    int num = -1;
    bool res = isPowerOfThree(num);
    res ? cout<<"true" : cout<<"false";
    return 0;
}