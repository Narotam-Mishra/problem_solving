
// Problem link - https://leetcode.com/problems/prime-arrangements/?envType=problem-list-v2&envId=math

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// utility function to precompute prime number using Sieve of Eratosthenes
vector<bool> preComputePrimeNumber(int n){
    vector<bool> isPrime(n+1, true);

    // 0 and 1 are no prime
    isPrime[0] = isPrime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}

// utility function to calculate factorial of number
long long getFactorialValue(int num){
    long long f = 1;
    for(int i=2; i<=num; i++){
        f = (f * i) % MOD;
    }
    return f;
}

int numPrimeArrangements(int n) {
    // step 1 - pre compute prime numbers in array
    vector<bool> primeNumbers = preComputePrimeNumber(n);

    // step 2 - count prime numbers from 1 to n
    int primeCount = 0;
    for(int i=1; i<=n; i++){
        if(primeNumbers[i]){
            primeCount++;
        }
    }

    // step 3 - find number of permutations for prime numbers
    long long np = getFactorialValue(primeCount);

    // step 4 - find number of permutations for non-prime numbers
    long long nnp = getFactorialValue(n - primeCount);

    // step 5 - compute the result and return it
    long long res = (np * nnp) % MOD;
    return static_cast<int>(res);
}

int main(){
    // int n = 5;

    int n = 100;
    cout<<numPrimeArrangements(n)<<endl;
    return 0;
}