
// Problem link - https://leetcode.com/problems/number-of-people-aware-of-a-secret/?envType=daily-question&envId=2025-09-09

package DynamicProgramming_problems;

public class NumberOfPeopleAwareOfSecret {
    public static int peopleAwareOfSecret(int n, int delay, int forget) {
        final int mod = 1000000007;

        // using bottom-up dp
        long[] dp = new long[n+1];

        // base case: 1 person discovers on day 1
        dp[1] = 1;

        // keep track of window sum for current range [day-forget+1, day-delay]
        long c = 0;

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
        long ans = 0;
        for(int day=n-forget+1; day<=n; day++){
            if(day>0){
                ans = (ans + dp[day]) % mod;
            }
        }

        // step 5 - return final answer `ans`
        return (int)ans;
    }

    public static void main(String[] args) {
        // int n = 6, delay = 2, forget = 4;

        int n = 4, delay = 1, forget = 3;
        System.out.println(peopleAwareOfSecret(n, delay, forget));
    }
}
