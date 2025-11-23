
// Problem link - https://leetcode.com/problems/greatest-sum-divisible-by-three/?envType=daily-question&envId=2025-11-23

package GreedyAlgorithms_problems;

import java.util.*;

public class GreatestSumDivisbleByThree {
    public static int maxSumDivThree(int[] nums) {
        // step 1 - categorize numbers by their remainder when divided by 3
        List<Integer> remain1 = new ArrayList<>();
        List<Integer> remain2 = new ArrayList<>();

        int sum = 0;
        for(int num : nums){
            sum += num;

            if(num % 3 == 1){
                remain1.add(num);
            }
            else if(num % 3 == 2){
                remain2.add(num);
            }
        }

        // edge case
        if(sum % 3 == 0){
            return sum;
        }

        // step 2 - sort both lists in ascending order
        // this allows us to easily access the smallest numbers for removal
        Collections.sort(remain1);
        Collections.sort(remain2);

        // step 3 - based on the remainder of total sum, decide what to remove
        int res = 0;
        int remainder = sum % 3;

        if(remainder == 1){
            // case 1 - sum has remainder 1
            int r1 = remain1.size() >= 1 ? remain1.get(0) : Integer.MAX_VALUE;
            int r2 = remain2.size() >= 2 ? remain2.get(0) + remain2.get(1) : Integer.MAX_VALUE;

            res = Math.max(res, sum - Math.min(r1, r2));
        }else{
            // case 2 - sum has reaminder 2
            int r1 = remain2.size() >= 1 ? remain2.get(0) : Integer.MAX_VALUE;
            int r2 = remain1.size() >= 2 ? remain1.get(0) + remain1.get(1) : Integer.MAX_VALUE;

            res = Math.max(res, sum - Math.min(r1, r2));
        }

        // step 4 - return final result `res`
        return res;
    }
    
    public static void main(String[] args) {
        // int[] nums = {3,6,5,1,8};

        // int[] nums = {1,2,3,4,4};

        int[] nums = {4};
        System.out.println(maxSumDivThree(nums));
    }
}
