
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// prime sieve - generate a array containing prime numbers
// all primes are marked as 1 and non primes are marked as 0
void prime_sieve(int *p, int maxN){
    
    // first mark all odd numbers as prime
    for(int i=3; i<=maxN; i+=2){
        p[i] = 1;
    }

    // prime sieve code
    for(ll i=3; i<=maxN; i+=2){
        // if the current number is not marked then it is prime
        if(p[i] == 1){
            // mark all the multiples of i as not prime
            for(ll j = i*i; j<=maxN; j+=i){
                p[j] = 0;
            }
        }
    }

    // special corner case
    p[2] = 1;
    p[1] = p[0] = 0;

}

int main(){
    int n = 100;
    int maxN = 100005;

    int primes[maxN + 1] = {0};
    prime_sieve(primes, maxN);

    for(int i=0; i<=n; i++){
        if(primes[i] == 1){
            cout<<i<<" ";
        }
    }
    return 0;
}