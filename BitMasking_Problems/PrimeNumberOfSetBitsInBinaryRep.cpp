
// Problem link : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/?envType=problem-list-v2&envId=bit-manipulation

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

int countPrimeSetBits1(int left, int right) {
    // initialize counter for numbers with prime set bits
    int cntPrimeSetBits = 0;

    // iterate through all numbers in the range [left, right]
    for(int i=left; i<=right; i++){
        int num = i, setBits = 0;

        // count the number of set bits (1s) in the binary representation of num
        while(num > 0){
            // increment setBits if the least significant bit is 1
            setBits += num & 1;
            // right shift num to check the next bit
            num = num >> 1;
        }

        // check if the number of set bits is prime
        if(isPrime(setBits)){
            // increment counter if setBits is prime
            cntPrimeSetBits++;
        }
    }
    // return the total count of numbers with prime set bits
    return cntPrimeSetBits;
}

int countPrimeSetBits(int left, int right) {
    // store prime numbers in set (for fast lookup)
    unordered_set<int> primes = {2,3,5,7,11,13,17,19};

    // counter for numbers with prime set bits
    int cnt = 0;

    // step 1 - iterate on each number from given range
    for(int i=left; i<=right; i++){
        int num = i, setBits = 0;

        // step 2 - count the number of set bits (1s) in the binary representation of num
        while(num > 0){
            // increment setBits if the least significant bit is 1
            setBits += num & 1;
            // right shift num to check the next bit
            num = num >> 1;
        }

        // step 3 - check if the number of set bits is prime
        if(primes.count(setBits)){
            cnt++;
        }
    }

    // step 4 - return the total count of numbers with prime set bits
    return cnt;
}

int main(){
    int left = 6, right = 10;

    // int left = 10, right = 15;
    cout<<countPrimeSetBits(left, right);
    return 0;
}