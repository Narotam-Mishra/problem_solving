
#include<bits/stdc++.h>
using namespace std;

int smallestEvenMultiple(int n) {
    // check if n is even
        // if n is divisible by 2, it is already the smallest even multiple
    if (n % 2 == 0) return n;

    // if n is odd, the smallest even multiple is n * 2
    return n * 2;
}

int main(){
    int n = 5;

    // int n = 6;
    cout<<smallestEvenMultiple(n);
    return 0;
}