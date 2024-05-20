
// Problem link - https://leetcode.com/problems/minimum-cost-for-tickets/description/

// Approach - using Bottom Up DP

package DynamicProgramming_problems;

import java.util.*;

public class MinCostForTicketBottomUpDP {
    public static int[] daysArr;
    public static int[] costsArr;
    public static int[] dp;
    public static Set<Integer> s;
    public static int lastDay;

    private static int findMinimumCostTopDownDP(){
        dp = new int[400];
        for(int day = 365; day >= 0; day--){
            // base case1: if 'd'th day is greater than last day of days array
            if(day > lastDay) dp[day] = 0;

            // Recursive case: if dth day doesn't exist in set 
            if(!s.contains(day)) dp[day] = dp[day+1];

            else{
                int ans = Math.min(costsArr[0]+dp[day+1], Math.min(costsArr[1]+dp[day+7], costsArr[2]+dp[day+30]));
                dp[day] = ans;
            }
        }
        return dp[1];
    }

    public static int mincostTickets(int[] days, int[] costs) {
        daysArr = days;
        costsArr = costs;
        lastDay = daysArr[daysArr.length - 1];
        s = new HashSet<Integer>();

        for(int d : days){
            s.add(d);
        }
        return findMinimumCostTopDownDP();
    }

    public static void main(String[] args) {
        int[] days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
        int[] costs = {2, 7, 15};

        // int[] days = {1,4,6,7,8,20};
        // int[] costs = {2, 7, 15};
        int ans = mincostTickets(days, costs);
        System.out.println(ans);
    }
}
