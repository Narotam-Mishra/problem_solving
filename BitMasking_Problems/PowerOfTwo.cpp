
#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    // check if n is positive
    if(n <= 0){
        return false;
    }
    
    // A power of two has exactly one bit set, 
    // so n > 0 and (n & (n - 1)) should be 0
    bool res = (n & (n-1)) == 0;
    return (n>0) && res;
}

int main(){
    // int num = 1;

    int num = 16;

    // int num = 3;
    bool ans = isPowerOfTwo(num);
    ans == 1 ? cout<<"true" : cout<<"false";
    return 0;
}