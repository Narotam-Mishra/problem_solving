
// Problem link - https://leetcode.com/problems/count-square-sum-triples/?envType=daily-question&envId=2025-12-08

#include<bits/stdc++.h>
using namespace std;

int countTriples(int n) {
    // store count of square triplets
    int cnt = 0;

    // step 1 - iterate on possible value of `a` & `b` and find triplets
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            // compute `c2`
            int c2 = a * a + b * b;

            // find square root value of `c2`
            int c = (int)(sqrt(c2));

            // check if `c2` is perfect square number or not
            if (c <= n && c * c == c2) {
                // increment triplet counter
                cnt++;
            }
        }
    }

    // step 3 - return the number of square triples
    return cnt;
}

int main(){
    int n = 5;
    cout<<countTriples(n);
    return 0;
}