
// Problem link - https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/

package Basic_problems;

public class FindMinimumOperations {

    public static int minimumOperations(int[] nums) {
        int count1 = 0, count2 = 0;
        for(int num : nums){
            int remainder = num % 3;
            if(remainder == 1) count1++;
            else if(remainder == 2) count2++;
        }
        int ans = Math.min(count1, count2) * 2 + Math.abs(count1 - count2);
        return ans;
    }    

    public static void main(String[] args) {
        int[] nums = {1, 2 ,3, 4};
        System.out.println(minimumOperations(nums));
    }
}