
// Problem link - https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/?envType=daily-question&envId=2025-09-05

package BitMasking_Problems;

public class MinimumOperationsToMakeTheIntegerZero {
    public static int makeTheIntegerZero(int num1, int num2) {
        // step 1 - iterate through possible operation counts from 1 to 36
        // Bound selection rationale:
        // - Most problems have solutions with very small k (typically < 10)
        // - 36 provides generous margin for unusual cases
        // - Avoids infinite loops while ensuring comprehensive coverage
        for (int k = 1; k <= 36; k++) {

            // step 2 - calculate target value for sum of powers of 2
            // After k operations: num1 - k*num2 = sum of k distinct powers
            long val = (long) num1 - (long) k * num2;
            
            // edge case - negative values can't be sum of powers of 2
            if (val < 0) {
                return -1;
            }
            
            // step 3 - Feasibility verification using two key conditions:
            // 1. Long.bitCount(val) <= k:
            //    Population count gives minimum powers needed
            //    Must fit within k available operations
            // 2. k <= val:
            //    Total value constraint - need at least k units
            //    Since smallest power is 1, val must be at least k
            if (Long.bitCount(val) <= k && k <= val) {
                return k;
            }
        }
        
        // step 4 - Solution not found within iteration bounds
        return -1;
    }

    public static void main(String[] args) {
        // int num1 = 3, num3 = -2;

        int num1 = 5, num3 = 7;
        System.out.println(makeTheIntegerZero(num1, num3));
    }
}