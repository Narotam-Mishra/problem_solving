
// Problem link - https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/?envType=daily-question&envId=2025-11-15

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - using prefix sum concept (will give TLE)
int numberOfSubstrings1(string s) {
    int n = s.size();

    // step 1 - find prefix sum of ones
    vector<int> prefix(n+1, 0);
    for(int i=0; i<n; i++){
        prefix[i+1] = prefix[i] + (s[i] == '1');
    }

    // store final result in res
    int res = 0;

    // step 2 - find maximum possible zeros
    int maxPossibleZeros = sqrt(n) + 1;
    
    // step 3 - iterate on every possible substring
    for(int i=0; i<n; i++){
        int zeros = 0;
        
        // step 4 - find count of zeros in current substring
        for(int j=i; j<n; j++){
            if(s[j] == '0') zeros++;

            // step 5 - check if number of zeros are within range or not
            if(zeros > maxPossibleZeros){
                break;
            }

            // step 6 - find count of 1 till current substring
            int ones = prefix[j+1] - prefix[i];

            // step 7 - check condition for dominant string
            if(ones >= zeros * zeros){
                res++;
            }
        }
    }

    // step 8 - return final result, res
    return res;
}

// Approach 2 - Optimal Solution
int numberOfSubstrings(string s) {
    int n = s.size();

    // step 1 - find cummulative count of 1
    vector<int> cumOneCount(n, 0);
    cumOneCount[0] = (s[0] == '1') ? 1 : 0;

    for(int i=1; i<n; i++){
        cumOneCount[i] = cumOneCount[i-1] + ((s[i] == '1') ? 1 : 0);
    }

    // step 2 - iterate on each substring
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            // step 2 - find count of 1 & 0 at each substring
            int ones = cumOneCount[j] - (i - 1 >= 0 ? cumOneCount[i-1] : 0);
            int zeros = (j - i + 1) - ones;

            // case 1 - too many zeros - substring is not dominant
            // skip ahead to avoid checking invalid substrings
            if(zeros * zeros > ones){
                int deficit = (zeros * zeros) - ones;
                j += deficit - 1;
            }
            // case 2 - exactly at the boundary - this substring is valid
            else if(zeros * zeros == ones){
                res += 1;
            }
            // case 3  - dominant substring found - count all valid extensions
            else{
                // [i....j] is a valid dominant string
                res += 1;

                // step 3 - calculate how many positions we can extend to the right
                int k = sqrt(ones) - zeros;
                int nextJ = j + k;

                // step 4 - check if we can extend beyond the string, all remaining positions are valid
                if(nextJ >= n){
                    res += (n - j - 1);
                    break;
                }else{
                    // otherwise, count the valid extensions and skip ahead
                    res += k;
                }

                j = nextJ;
            }
        }
    }

    // step 5 - return final result res
    return res;
}

int main(){
    string s = "00011";

    // string s = "101101";
    cout<<numberOfSubstrings(s);
    return 0;
}