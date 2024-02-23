
// Problem link - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

package Array_problems;

/**
 * TwoSumII
 */

public class TwoSumII {
    public int[] twoSum(int[] numbers, int target) {
        int s = 0;
        int e = numbers.length - 1;

        while(s<e){
            if(numbers[s] + numbers[e] == target){
                return new int[]{s+1, e+1};
            }else if(numbers[s] + numbers[e] > target){
                e--;
            }else{
                s++;
            }
        }
        return new int[]{};
    }
}