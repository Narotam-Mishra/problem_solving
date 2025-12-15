
// Problem link - https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/?envType=daily-question&envId=2025-12-15

package NumberTheory_Problems;

public class NumberOfSmoothDescentPeriodsOfStock {
    public static long getDescentPeriods(int[] prices){
                // get size of `prices`
        int n = prices.length;

        // step 1 - iterate on each prices
        long count = 1, res = 1;
        for(int i=1; i<n; i++){
            // step 2 - check if current price and previous price is differ by 1 or not
            if(prices[i-1] - prices[i] == 1){
                // increment count
                count++;
            }else{
                // otherwise reset count to 1
                count = 1;
            }

            // step 3 - add count into result, `res`
            res += count;
        }

        // step 4 - return final result, `res`
        return res;
    }

    public static void main(String[] args) {
        int[] prices = {3,2,1,4};
        System.out.println(getDescentPeriods(prices));
    }
}
