
// Problem link - https://leetcode.com/problems/number-of-people-aware-of-a-secret/?envType=daily-question&envId=2025-09-09

let peopleAwareOfSecret = function(n, delay, forget) {
    const mod = 1000000007;

    // using bottom-up dp
    let dp = new Array(n+1).fill(0);

    // base case: 1 person discovers on day 1
    dp[1] = 1;

    // keep track of window sum for current range [day-forget+1, day-delay]
    let c = 0;

    // step 1 - fill dp table
    for(let day = 2; day<=n; day++){
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
    let ans = 0;
    for(let day=n-forget+1; day<=n; day++){
        if(day>0){
            ans = (ans + dp[day]) % mod;
        }
    }

    // step 5 - return final answer `ans`
    return ans;
};

// const n = 6, delay = 2, forget = 4;

const n = 4, delay = 1, forget = 3;
console.log(peopleAwareOfSecret(n, delay, forget));