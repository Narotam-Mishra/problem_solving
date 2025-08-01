
// Problem link - https://leetcode.com/problems/check-if-any-element-has-prime-frequency/description/?envType=problem-list-v2&envId=array

package Array_problems;

public class CheckIfAnyElementHasPrimeFrequency {
    // utility method to check if number is prime or not
    private static boolean isPrimeNumber(int n){
        if(n <= 1) return false;

        for(int i=2; i<=Math.sqrt(n); i++){
            if(n % i == 0) return false;
        }

        return true;
    }
    
    public static boolean checkPrimeFrequency(int[] nums) {
        // step 1 - create frequency array to store frquency of `nums` elements
        int[] frqArr = new int[101];

        // step 2 - count frequency of each `nums` element
        for (int num : nums) {
            frqArr[num]++;
        }

        // step 3 - iterate on frequency array
        for (int num : frqArr) {
            // step 4 - check if any frquency has prime frequency
            if (isPrimeNumber(num)) {
                return true;
            }
        }

        // step 5 - if none of the frequency is prime then return false
        return false;
    }

    public static void main(String[] args) {
        // int[] nums = {1,2,3,4,5,4};

        // int[] nums = {1,2,3,4,5};

        int[] nums = {2,2,2,4,4};
        System.out.println(checkPrimeFrequency(nums));
    }
}