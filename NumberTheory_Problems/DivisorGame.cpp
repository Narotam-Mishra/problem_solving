
#include<bits/stdc++.h>
using namespace std;

bool divisorGameHelper(int n, vector<bool>& cache){
    // base case : if n is 1, Alice loses immediately
    if(n == 1) return false;

    // if `n` is already computed then return its value
    if(cache[n]) return cache[n];

    // step 1 - iterate on all possible value of `n`
    for(int x=1; x<n; x++){
        // step 2 - if `x` is valid move and if that move make Bob lose then Alice wins
        if(n % x == 0 && !divisorGameHelper(n-x, cache)){
            return cache[n] = true;
        }
    }

    // step 3 - if no winning move is found, Alice lose
    return cache[n] = false;
}

bool divisorGame1(int n) {
    vector<bool> cache(n+1, false);
    return divisorGameHelper(n, cache);
}

bool divisorGame(int n) {
    // Alice wins if and only if `n` is even
    return n % 2 == 0;
}

int main(){
    // int n = 2;

    int n = 3;
    bool res = divisorGame(n);
    res ? cout<<"true" : cout<<"false";
    return 0;
}