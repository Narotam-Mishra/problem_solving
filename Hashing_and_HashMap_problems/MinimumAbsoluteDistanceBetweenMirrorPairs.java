
// Problem link - https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/?envType=daily-question&envId=2026-04-17

package Hashing_and_HashMap_problems;

import java.util.*;

public class MinimumAbsoluteDistanceBetweenMirrorPairs {
    private int reverseNum(int num){
        int rev = 0;
        while(num > 0){
            int rem = num % 10;
            rev = rev*10 + rem;
            num = num/10;
        }
        return rev;
    }

    public int minMirrorPairDistance(int[] nums) {
        int n = nums.length;

        // step 1 - store each number reverse in map
        Map<Integer, Integer> revMap = new HashMap<>();
        int res = Integer.MAX_VALUE;
        for(int i=0; i<n; i++){
            // step 2 - check if reverse number already exist in map or not
            if(revMap.containsKey(nums[i])){
                // find minimum absolute diff
                res = Math.min(res, Math.abs(i - revMap.get(nums[i])));
            }

            int rev = reverseNum(nums[i]);
            revMap.put(rev, i);
        }

        // step 3 - return final result `res`
        return res == Integer.MAX_VALUE ? -1 : res;
    }

    public static void main(String[] args) {
        int[] nums = {12,21,45,33,54};
        MinimumAbsoluteDistanceBetweenMirrorPairs obj = new MinimumAbsoluteDistanceBetweenMirrorPairs();
        System.out.println(obj.minMirrorPairDistance(nums));
    }
}
