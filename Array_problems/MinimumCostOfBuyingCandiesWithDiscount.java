
// Problem link - https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/

package Array_problems;

import java.util.*;

public class MinimumCostOfBuyingCandiesWithDiscount {
    public static int minimumCost(int[] cost) {
        // store minimum cost of all candies in `minCost`
        int minCost = 0;

        // step 1 - sort the candies in desending order to get most expensive first
        // this ensures we buy the most expensive candies and get cheaper ones free
        Arrays.sort(cost);

        // sort the array and rverser it to get it in ascending order
        for (int i = 0; i < cost.length / 2; i++) {
            int temp = cost[i];
            cost[i] = cost[cost.length - 1 - i];
            cost[cost.length - 1 - i] = temp;
        }

        // step 2 - process candies in groups of 3
        // for every 3 candies: buy 2 most expensive, get 1 cheapest free
        for (int i = 0; i < cost.length; i += 3) {

            // step 3 - buy the first candy in the group (most expensive)
            minCost += cost[i];

            // step 4 - buy the second candy in the group if it exists
            if (i + 1 < cost.length) {
                minCost += cost[i + 1];
            }
        }

        // step 5 - return minimum cost of all candies in `minCost`
        return minCost;
    }

    public static void main(String[] args) {
        // int[] cost = {1,2,3};

        // int[] cost = {5,5};

        int[] cost = {6,5,7,9,2,2};
        System.out.println(minimumCost(cost));
    }
}