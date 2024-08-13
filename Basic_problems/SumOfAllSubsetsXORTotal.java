
// Problem link : https://leetcode.com/problems/sum-of-all-subset-xor-totals/

package Basic_problems;

public class SumOfAllSubsetsXORTotal {

    public static int subsetXORSum(int[] nums) {
        int totalSum = 0;
        int n = nums.length;

        for(int num : nums){
            totalSum |= num;
        }
        return (totalSum << n - 1);
    }
    public static void main(String[] args) {
        int[] arr = {3, 4, 5, 6, 7, 8};
        System.out.println(subsetXORSum(arr));
    }
}