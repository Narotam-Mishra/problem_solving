
// Problem link : https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/?envType=problem-list-v2&envId=number-theory&status=TO_DO&difficulty=EASY

package NumberTheory_Problems;

public class FindGreatestCommonDivisorArray {

    // helper function to calculate the greatest common divisor (GCD) using Euclid's algorithm
    private static int gcd(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static int findGCD(int[] nums) {
        // find maximum number from array
        int maxNum = Integer.MIN_VALUE;

        // find minimum number from array
        int minNum = Integer.MAX_VALUE;

        for(int i=0; i<nums.length; i++){
            // maximum number
            maxNum = Math.max(maxNum, nums[i]);

            // minimum number
            minNum = Math.min(minNum, nums[i]);
        }

        // find and return GCD of maximum and minimum number
        return gcd(minNum, maxNum);
    }

    public static void main(String[] args) {
        // int[] nums = {2,5,6,9,10};

        int[] nums = {7, 5, 6, 8, 3};
        System.out.println(findGCD(nums));
    }
}