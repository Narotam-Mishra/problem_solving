
// Problem link - https://leetcode.com/problems/minimum-cost-for-tickets/description/

package DynamicProgramming_problems;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class MinCostForTicketsTopDownDP {
    public static int[] daysArr;
    public static int[] costsArr;
    public static int[] dp;
    public static Set<Integer> s;

    private static int findMinimumCostTopDownDP(int day){
        // base case1: if 'd'th day is greater than last day of days array
        if(day > daysArr[daysArr.length - 1]) return 0;

        // Recursive case: if dth day doesn't exist in set 
        if(!s.contains(day)) return findMinimumCostTopDownDP(day+1);

        // if dp[day] is already claculated then return dp[day]
        if(dp[day] != -1){
            return dp[day];
        }

        // recursively calculate minimim cost: f(day) = min(costs[0]+f(d+1), costs[1]+f(d+8), costs[2]+f(d+30))
        int ans = Math.min(costsArr[0]+findMinimumCostTopDownDP(day+1), Math.min(costsArr[1]+findMinimumCostTopDownDP(day+7), costsArr[2]+findMinimumCostTopDownDP(day+30)));

        return dp[day] = ans;
    }
    public static int mincostTickets(int[] days, int[] costs) {
        daysArr = days;
        costsArr = costs;
        dp = new int[400];
        Arrays.fill(dp, -1);

        s = new HashSet<Integer>();

        for(int d : days){
            s.add(d);
        }
        return findMinimumCostTopDownDP(days[0]);
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
