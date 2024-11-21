
// Problem link : https://leetcode.com/problems/number-of-common-factors/description/?envType=problem-list-v2&envId=number-theory&status=TO_DO&difficulty=EASY

package NumberTheory_Problems;

public class NumberOfCommonFactors {

    private static int findGCD(int x, int y) {
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }

    public static int commonFactors(int a, int b) {
        // intialize counter to count common factors
        int commonFactorsCount = 0;
        
        // step 2: Compute the GCD of a and b
        int gcdVal = findGCD(a, b);

        // step 3 : count divisors of the GCD
        for (int i = 1; i*i <= gcdVal; i++) {
            // count i as a factor
            if (gcdVal % i == 0) {
                commonFactorsCount++;
                // count gcdVal/i as distinct factor
                if (i != gcdVal / i) {
                    commonFactorsCount++;
                }
            }
        }

        // step 4: Return the count of common factors
        return commonFactorsCount;
    }

    public static void main(String[] args) {
        // int a = 12, b = 6;

        int a = 25, b = 30;
        System.out.println(commonFactors(a, b));
    }
}