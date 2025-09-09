
// Problem link - https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/?envType=daily-question&envId=2025-09-09

#include<bits/stdc++.h>
#define mod 1000000007 
using namespace std;

// using top-down DP (memoization)
vector<int> memo;

/*
* Logic: A person who discovered secret on day 'd' will share it from:
* - Start sharing: day (d + delay)
* - Stop sharing: day (d + forget - 1) [they forget on day (d + forget)]
*
* So for current 'day', we need people who:
* - Discovered secret on day 'd' where (d + delay <= day <= d + forget - 1)
* - Rearranging: (day - forget + 1 <= d <= day - delay)
*/

// utility recursive function to find how many people discovered the secret on a specific day
int solveRec(int day, int delay, int forget){
    // base case - only one person know the secret on day 1
    if(day == 1) return 1;

    // check if answer is already computed for this day
    if(memo[day] != -1){
        return memo[day];
    }

    // recursive case : calculate how many people discovered the secret on 'day'
    int res = 0;
    for(int d=day-forget+1; d<=day-delay; d++){
        // consider valid day only (it should not be negative)
        if(d > 0){
            // add number of people who discovered secret on day 'd'
            res = (res + solveRec(d, delay, forget)) % mod;
        }
    }

    // memoize the result
    return memo[day] = res;
}

/*
* People who know the secret on day 'n' are those who:
* - Discovered the secret on day 'd' where (d + forget > n)
* - Rearranging: d > n - forget
* - So: d >= n - forget + 1
* - Also: d <= n (can't discover secret in future)
*
* Range: [n - forget + 1, n]
*/

int peopleAwareOfSecret1(int n, int delay, int forget) {
    // initialize meomization table `memo`
    memo.assign(n+1, -1);

    // store final answer in `ans`
    int ans = 0;

    // step 1 - iterate on range[n-forget+1 to n]
    for(int day=n-forget+1; day<=n; day++){
        // consider valid day only (it should not be negative)
        if(day > 0){
            // step 2 - add people who discovered the secret on this 'day' by using recursive appraoch
            // they still remember it on day 'n'
            ans = (ans + solveRec(day, delay, forget)) % mod;
        }
    }

    // step 3 - return final answer `ans`
    return ans;
}

int peopleAwareOfSecret2(int n, int delay, int forget) {
    // using bottom-up dp
    vector<long long> dp(n+1, 0);

    // base case: 1 person discovers on day 1
    dp[1] = 1;

    // step 1 - fill dp table
    for(int day = 2; day<=n; day++){
        // track running count for current day in `c`
        long long c = 0;

        // step 2 - people who discover secret on 'day' are shared to by people who
        // discovered secret on day 'd' where (d + delay <= day <= d + forget - 1)
        // rearranging: (day - forget + 1 <= d <= day - delay)
        for(int d=day-forget+1; d<=day-delay; d++){
            // consider valid day only (it should not be negative)
            if(d>0){
                // step 3 - add number of people who discovered secret on day 'd'
                c = (c + dp[d]) % mod;
            }
        }

        // store current day count in dp table
        dp[day] = c;
    }

    
    // step 4 - calculate final answer `ans` : people who still know secret on day n
    long long ans = 0;
    for(int day=n-forget+1; day<=n; day++){
        if(day>0){
            ans = (ans + dp[day]) % mod;
        }
    }

    // step 5 - return final answer `ans`
    return (int)ans;
}

// optimized bottom-up dp (with linear time complexity) 
int peopleAwareOfSecret(int n, int delay, int forget) {
    // using bottom-up dp
    vector<long long> dp(n+1);

    // base case: 1 person discovers on day 1
    dp[1] = 1;

    // keep track of window sum for current range [day-forget+1, day-delay]
    long long c = 0;

    // step 1 - fill dp table
    for(int day = 2; day<=n; day++){
        // people who discover secret on 'day' are shared to by people who
        // discovered secret on day 'd' where (d + delay <= day <= d + forget - 1)
        // rearranging: (day - forget + 1 <= d <= day - delay)
        
        // step 2 - people start sharing 'delay' days after discovery, so add (day-delay)
        // check for valid (day-delay)
        if(day - delay > 0){
            c = (c + dp[day-delay]) % mod;
        }

        // step 3 - people stop sharing 'forget' days after discovery, so discard (day-forget)
        // check for valid (day-forget)
        if(day-forget > 0){
            c = (c - dp[day-forget] + mod) % mod;
        }

        // store current day count in dp table
        dp[day] = c;
    }

    
    // step 4 - calculate final answer `ans` : people who still know secret on day n
    long long ans = 0;
    for(int day=n-forget+1; day<=n; day++){
        if(day>0){
            ans = (ans + dp[day]) % mod;
        }
    }

    // step 5 - return final answer `ans`
    return (int)ans;
}

int main(){
    // int n = 6, delay = 2, forget = 4;

    int n = 4, delay = 1, forget = 3;
    cout<<peopleAwareOfSecret(n, delay, forget);
    return 0;
}