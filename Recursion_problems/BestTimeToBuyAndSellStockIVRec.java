
// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

// Approach - Using Recursion

package Recursion_problems;

public class BestTimeToBuyAndSellStockIVRec {
    public static int[] pArr;
    private static int findMaxProfitRec(int i, boolean ts, int k){
        // Base case: all days are completed
        if(i == pArr.length) return 0;

        int ans = Integer.MIN_VALUE;

        // Recursive case:
        // Case 1 : Ignore stock
        ans = Math.max(ans, findMaxProfitRec(i+1, ts, k));

        // Case 2 : Buy the stock on ith day
        if(k > 0 && ts == false){
            ans = Math.max(ans, -pArr[i] + findMaxProfitRec(i+1, true, k));
        }
        

        // Case 3 : sell the stock on ith day
        if(ts == true){
            ans = Math.max(ans, pArr[i] + findMaxProfitRec(i+1, false, k-1));
        }
        return ans;
    }
    public static int maxProfit(int k, int[] prices) {
        pArr = prices;
        return findMaxProfitRec(0, false, k);
    }

    public static void main(String[] args) {
        int k = 2;
        int[] prices = {3,2,6,5,0,3};
        System.out.println(maxProfit(k, prices));
    }
}
