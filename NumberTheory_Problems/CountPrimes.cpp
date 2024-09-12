
// Problem link - https://leetcode.com/problems/count-primes/description/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<bool> primeSieve(int maxN){
    vector<bool> primes(maxN+1, false);

    // first mark all odd numbers as prime starting from 3
    for(int i=3; i<=maxN; i+=2){
        primes[i] = true;
    }

    // prime sieve code
    for(ll i=3; i<=maxN; i+=2){
        // if the current number is not marked then it is prime
        if(primes[i]){
            // mark all the multiples of i as not prime
            for(ll j = (ll)i*i; j<=maxN; j+=i){
                primes[j] = false;
            }
        }
    }

    // special corner case:
    primes[2] = 1;
    primes[0] = primes[1] = 0;

    return primes;
}

int countPrimes(int n) {
    int c = 0;

    // get all primes in an array
    vector<bool> primes = primeSieve(n);

    // iterate through number in given range
    for (int i = 1; i < n; i++) {
        if (primes[i]) c++;
    }

    // return count of prime numbers
    return c;
}

int main(){
    int num = 10;
    cout<<countPrimes(num);
    return 0;
}