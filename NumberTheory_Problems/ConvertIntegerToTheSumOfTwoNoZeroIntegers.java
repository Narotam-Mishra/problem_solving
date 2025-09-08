
// Problem link - https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/?envType=daily-question&envId=2025-09-08

package NumberTheory_Problems;

import java.util.Arrays;

public class ConvertIntegerToTheSumOfTwoNoZeroIntegers {
    // utility function whether number `num` has zero or not
    private static boolean hasZero(int num){
        return String.valueOf(num).contains("0");
    }

    public static int[] getNoZeroIntegers(int n) {
        // step 1 - start with a = 1 and b = n-1
        int a = 1;
        int b = n - 1;

        // step 2 - keep searching until we find a valid pair
        // since a solution is guaranteed, this loop will terminate
        while(hasZero(a) || hasZero(b)){
            // try next value of `a`
            a++;

            // update `b` to maintain sum
            b = n - a;
        }

        // step 3 - return required numbers `a` and `b`
        return new int[] {a, b};
    }

    public static void main(String[] args) {
        // int n = 2;

        int n = 11;
        int[] res = getNoZeroIntegers(n);
        System.out.println(Arrays.toString(res));
    }
}
