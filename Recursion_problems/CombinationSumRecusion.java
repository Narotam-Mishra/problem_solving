
// Problem link - https://leetcode.com/problems/combination-sum-iv/

package Recursion_problems;

public class CombinationSumRecusion {
    public static int[] arr;
    private static int findNumberOfPossibleCombinationsRec(int curTarget){
        // Base case: if target become 0 then we will first way
        if(curTarget == 0) return 1;

        // Recursive case: recurively calculate number of possible combinations that add up to target
        // f(target) = f(target - arr[i])

        int res = 0;
        for(int i=0; i<arr.length; i++){
            if(curTarget - arr[i] >= 0){
                res += findNumberOfPossibleCombinationsRec(curTarget - arr[i]);
            }
        }
        return res;
    }
    public static int combinationSum4(int[] nums, int target) {
        arr = nums;
        return findNumberOfPossibleCombinationsRec(target);
    }

    public static void main(String[] args) {
        int[] nums = {1,2,3};
        int target = 4;
        System.out.println(combinationSum4(nums, target));
    }
}
