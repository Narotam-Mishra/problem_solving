
// Problem link - https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/?envType=daily-question&envId=2026-03-07

#include<bits/stdc++.h>
using namespace std;

int minFlips1(string s) {
    int n = s.length();
    
    // step 1 - double input string 
    // to simulate all posiiton rotations
    s = (s + s);

    // step 2 - create two alternating pattern strings
    // s1 -> "101010..."
    // s2 -> "010101..."
    string s1,s2;
    for(int i=0; i<2*n; i++){
        s1 += (i%2 ? '0' : '1');
        s2 += (i%2 ? '1' : '0');
    }

    // store final result in `res`
    int res = INT_MAX;

    // keep track of flip required for both string s1 & s2
    int f1=0, f2=0;

    // step 3 - using sliding window approach
    int i=0, j=0;
    // expand window
    while(j < 2*n){
        // check for mismatch with pattern `s1`
        if(s[j] != s1[j]){
            f1++;
        }

        // check for mismatch with pattern `s2`
        if(s[j] != s2[j]){
            f2++;
        }

        // step 4 - check if window size exceed `n`
        // then shrink the window
        if(j-i+1 > n){
            // remove the effect of character leaving the window
            if(s[i] != s1[i]){
                f1--;
            }

            if(s[i] != s2[i]){
                f2--;
            }

            // move left pointer
            i++;
        }

        // step 5 - when window size is exactly n
        if(j-i+1 == n){
            // then update final result, `res`
            res = min({res, f1, f2});
        }

        // step 6 - move right pointer to expand window
        j++;
    }

    // step 7 - return final result, `res`
    return res;
}

int minFlips2(string s) {
    int n = s.length();
    
    // step 1 - create two alternating pattern strings
    // s1 -> "101010..."
    // s2 -> "010101..."
    string s1,s2;
    for(int i=0; i<2*n; i++){
        s1 += (i%2 ? '0' : '1');
        s2 += (i%2 ? '1' : '0');
    }

    // store final result in `res`
    int res = INT_MAX;

    // keep track of flip required for both string s1 & s2
    int f1=0, f2=0;

    // step 2 - using sliding window approach
    int i=0, j=0;
    // expand window
    while(j < 2*n){
        // check for mismatch with pattern `s1`
        if(s[j%n] != s1[j]){
            f1++;
        }

        // check for mismatch with pattern `s2`
        if(s[j%n] != s2[j]){
            f2++;
        }

        // step 3 - check if window size exceed `n`
        // then shrink the window
        if(j-i+1 > n){
            // remove the effect of character leaving the window
            if(s[i%n] != s1[i]){
                f1--;
            }

            if(s[i%n] != s2[i]){
                f2--;
            }

            // move left pointer
            i++;
        }

        // step 4 - when window size is exactly n
        if(j-i+1 == n){
            // then update final result, `res`
            res = min({res, f1, f2});
        }

        // step 5 - move right pointer to expand window
        j++;
    }

    // step 6 - return final result, `res`
    return res;
}

int minFlips(string s) {
    int n = s.length();
    
    // store final result in `res`
    int res = INT_MAX;

    // keep track of flip required for both string s1 & s2
    int f1=0, f2=0;

    // step 1 - using sliding window approach
    int i=0, j=0;
    // expand window
    while(j < 2*n){
        // step 2 - find expected character for string s1 & s2
        char expCharS1 = (j % 2) ? '1' : '0';
        char expCharS2 = (j % 2) ? '0' : '1';

        // check for mismatch with pattern `s1`
        if(s[j%n] != expCharS1){
            f1++;
        }

        // check for mismatch with pattern `s2`
        if(s[j%n] != expCharS2){
            f2++;
        }

        // step 3 - check if window size exceed `n`
        // then shrink the window
        if(j-i+1 > n){
            expCharS1 = (i % 2) ? '1' : '0';
            expCharS2 = (i % 2) ? '0' : '1';

            // remove the effect of character leaving the window
            if(s[i%n] != expCharS1){
                f1--;
            }

            if(s[i%n] != expCharS2){
                f2--;
            }

            // move left pointer
            i++;
        }

        // step 4 - when window size is exactly n
        if(j-i+1 == n){
            // then update final result, `res`
            res = min({res, f1, f2});
        }

        // step 5 - move right pointer to expand window
        j++;
    }

    // step 6 - return final result, `res`
    return res;
}

int main(){
    // string s = "111000";

    // string s = "010";

    string s = "1110";
    cout<<minFlips(s);
    return 0;
}