
// Problem link : https://www.geeksforgeeks.org/problems/prime-number2314/1

#include<bits/stdc++.h>
using namespace std;

int isPrime(int n){
    // corner case
    if(n <= 1) return 0;

    // check from 2 to sqrt(n)
    for(int i=2; i<=sqrt(n); i++){
        if(n % i == 0) return 0;
    }

    // if no divisors are found, n is prime
    return 1;
}

int main(){
    // int num = 11;

    int num = 21;
    cout<<isPrime(num);
    return 0;
}