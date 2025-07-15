package Array_problems;

import java.util.*;

public class FinalPricesWithSpecialDiscountInShop {
    public static int[] finalPrices(int[] prices) {
        // store result in `res` array
        int n = prices.length;
        int[] res = new int[n];

        // step 1 - for each item in the shop
        for(int i=0; i<n; i++){
            int discount = 0;

            // step 2 - look for the first item to the right with price <= current price
            for(int j=i+1; j<n; j++){
                // step 3 - found discount
                if(prices[j] <= prices[i]){
                    // take only first discount
                    discount = prices[j];
                    break;
                }
            }

            // step 4 - calculate the discounted price
            res[i] = prices[i] - discount;
        }

        // step 5 - return resultant discount array `res`
        return res;
    }

    public static void main(String[] args) {
        // int[] prices = {8,4,6,2,3};

        // int[] prices = {1,2,3,4,5};

        int[] prices = {10,1,1,6};
        int[] res = finalPrices(prices);
        System.out.println(Arrays.toString(res));
    }
}
