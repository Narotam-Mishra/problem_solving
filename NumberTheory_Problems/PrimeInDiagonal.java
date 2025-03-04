
// Problem link - https://leetcode.com/problems/prime-in-diagonal/?envType=problem-list-v2&envId=number-theory

package NumberTheory_Problems;

public class PrimeInDiagonal {
    // utility method to check if a number is prime or not
    private static boolean isPrime(int n){
        // base case:
        if(n < 2) return false;

        // iterate on number from 2 to sqrt(n)
        for(int i=2; i*i <= n; i++){
            if(n % i == 0) return false;
        }

        return true;
    }
    
    public static int diagonalPrime(int[][] nums) {
        // step 1 - store maximum Prime number ina variable `maxPrime`
        int maxPrime = 0;

        // find number of rows
        int n = nums.length;

        // step 2 - iterate on 2D array
        for(int i=0; i<n; i++){
            // step 3 - get primary diagonal elements
            int primary = nums[i][i];

            // step 4 - get secondary diagonal elements
            int secondary = nums[i][n-i-1];

            // step 5 - check and update maxPrime for Primary and secondary elements
            if(isPrime(primary)){
                maxPrime = Math.max(primary, maxPrime);
            }

            if(isPrime(secondary)){
                maxPrime = Math.max(secondary, maxPrime);
            }
        }

        // step 6 - return maxPrime
        return maxPrime;
    }

    public static void main(String[] args) {
        // int[][] nums = {{1, 2, 3}, {5, 6, 7}, {9, 10, 11}};

        int[][] nums = {{1, 2, 3}, {5, 17, 7}, {9, 11, 10}};
        System.out.println(diagonalPrime(nums));
    }
}