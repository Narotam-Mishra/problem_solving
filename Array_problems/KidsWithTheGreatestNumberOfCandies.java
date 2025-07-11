
// Problem link - https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class KidsWithTheGreatestNumberOfCandies {
    public static List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        // store result in `res` list
        List<Boolean> res = new ArrayList<>();

        // step 1 - find maximum number of candies
        int maxNumCandy = -1;
        for (int num : candies) {
            if (num > maxNumCandy) {
                maxNumCandy = num;
            }
        }

        // step 2 - iterate on each candy from `candies`
        for (int numCandy : candies) {
            // step 3 - check if kid has greatest number of candies among all or not
            if (numCandy + extraCandies >= maxNumCandy) {
                // add true
                res.add(true);
            } else {
                // otherwise add false
                res.add(false);
            }
        }

        // step 4 - return resultant array `res`
        return res;
    }

    public static void main(String[] args) {
        // int[] candies = {2,3,5,1,3};
        // int extraCandies = 3;

        // int[] candies = {4,2,1,1,2};
        // int extraCandies = 1;

        int[] candies = {12,1,12};
        int extraCandies = 10;
        List<Boolean> res = kidsWithCandies(candies, extraCandies);
        System.out.println(res);
    }
}