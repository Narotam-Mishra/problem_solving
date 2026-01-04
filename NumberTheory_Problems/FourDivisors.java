
// Problem link - https://leetcode.com/problems/four-divisors/?envType=daily-question&envId=2026-01-04

package NumberTheory_Problems;

public class FourDivisors {
    private static int findDivisorSum(int num){
        // keep track of factors count and factors sum
        int factorsCount = 0;
        int divisorsSum = 0;

        // iterate on each posisble factor from 1 to sqrt(n)
        for(int f=1; f*f<=num; f++){
            // check if `num` is divisble
            if(num % f == 0){
                // find other factor
                int f2 = num/f;

                // check if num is perfect square number
                if(f == f2){
                    // count only one factor
                    factorsCount += 1;

                    // calculate factors sum
                    divisorsSum += f;
                }else{
                    // count factors in pair
                    factorsCount += 2;

                    // calculate factors sum
                    divisorsSum += (f + f2);
                }
            }

            // check if factors count is greater than 4 than return 0
            if(factorsCount > 4) return 0;
        }

        // return factors sum if factors count is exactly four otherwise 0
        return factorsCount == 4 ? divisorsSum : 0;
    }

    public static int sumFourDivisors(int[] nums) {
        // keep track of factors s
        int factorsSum = 0;

        // step 1 - iterate on each num of `nums`
        for(int num : nums){
            // step 2 - find factors sum
            factorsSum += findDivisorSum(num);
        }

        // step 3 - return factors sum, `factorsSum`
        return factorsSum;
    }

    public static void main(String[] args) {
        // int[] nums = {21,4,7};

        // int[] nums = {21, 21};

        int[] nums = {1,2,3,4,5};
        System.out.println(sumFourDivisors(nums));
    }
}
