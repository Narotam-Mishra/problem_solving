
#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    // corner case
    if(n <= 1) return false;

    // check from 2 to sqrt(n)
    for(int i=2; i<=sqrt(n); i++){
        if(n % i == 0) return false;
    }

    // if no divisors are found, n is prime
    return true;
}

bool isThree(int n) {
    // check if n is a perfect square
    int sqrtNum = sqrt(n);

    if(sqrtNum * sqrtNum != n){
        // not a perfect square
        return false;
    }
    // check if the square root of n is a prime number
    return isPrime(sqrtNum);
}

int main(){
    // int n = 2;

    // int n = 4;

    int n = 12;
    bool res = isThree(n);
    res ? cout<<"true" : cout<<"false";
    return 0;
}