
// Problem link : https://leetcode.com/problems/number-of-beautiful-pairs/description/?envType=problem-list-v2&envId=number-theory&status=TO_DO&difficulty=EASY

package NumberTheory_Problems;

public class NumberOfBeautifulPairs {

    // helper function to extract the first digit of a number
    private static int getFirstDigit(int num){
        while(num >= 10){
            num = num / 10;
        }
        return num;
    }

    // helper function to extract the last digit of a number
    private static int getLastDigit(int num){
        return num % 10;
    }

    // helper function to calculate the greatest common divisor (GCD) using Euclid's algorithm
    private static int gcd(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static int countBeautifulPairs(int[] nums) {
        // initialize count of beautiful pairs
        int count = 0;

        // iterate over all pairs of indices (i, j) where i < j
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                // extract the first digit of nums[i] and the last digit of nums[j]
                int x = getFirstDigit(nums[i]);
                int y = getLastDigit(nums[j]);

                // check if pair are coprime
                if (gcd(x, y) == 1) {
                    // increment count if the pair is beautiful
                    count++;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        // int[] nums = {2, 5, 1, 4};

        int[] nums = {11, 21, 12};
        System.out.println(countBeautifulPairs(nums));
    }
}