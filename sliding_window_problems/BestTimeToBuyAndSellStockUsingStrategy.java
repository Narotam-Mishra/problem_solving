
// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/

package sliding_window_problems;

public class BestTimeToBuyAndSellStockUsingStrategy {
    public static long maxProfit(int[] prices, int[] strategy, int k) {
        // step 1 - find profit for each stock price and strategy
        int n = prices.length;
        long[] profit = new long[n];
        long actualProfit = 0;
        for (int i = 0; i < n; i++) {
            profit[i] = (long)prices[i] * strategy[i];
            actualProfit += profit[i];
        }

        // keep track of maximum original window profit
        long originalWindowProfit = 0;

        // keep track of maximum modified window profit
        long modifiedWindowProfit = 0;

        // keep track of maximum profit for each window
        long maxGain = 0;

        // using sliding window approach
        int i = 0, j = 0;
        while(j < n){
            originalWindowProfit += profit[j];

            // step 2 - find modified window profit using second half of window
            if(j - i + 1 > k/2){
                modifiedWindowProfit += prices[j];
            }

            // check if window size exceed `k`
            if(j - i + 1 > k){
                // shrink window
                originalWindowProfit -= profit[i];
                modifiedWindowProfit -= prices[i + k/2];
                i++;
            }

            // step 3 - find maximum profit in window of size `k`
            if(j - i + 1 == k){
                maxGain = Math.max(maxGain, modifiedWindowProfit - originalWindowProfit);
            }

            // move to next window
            j++;
        }

        // step 4 - return maximum profit
        return actualProfit + maxGain;
    }

    public static void main(String[] args) {
        // int[] prices = {4,2,8};
        // int[] strategy = {-1,0,1};
        // int k = 2;

        int[] prices = {5,4,3};
        int[] strategy = {1,1,0};
        int k = 2;
        System.out.println(maxProfit(prices, strategy, k));
    }
}
