
// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

package Array_problems;

/**
 * FindMaximumProfile
 */
public class FindMaximumProfile {

    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        int curMin = prices[0];

        for(int i=0; i<prices.length; i++) {
            // can we buy stock?
            if(prices[i] < curMin){
                curMin = prices[i];
            }

            // can we sell stock?, find maximum profit
            if(prices[i] > curMin){
                maxProfit = Math.max(maxProfit, prices[i] - curMin);
            }
        }
        return maxProfit;
    }
}