
// Problem link - https://leetcode.com/problems/prime-arrangements/description/?envType=problem-list-v2&envId=math

package NumberTheory_Problems;

import java.util.*;

public class PrimeArrangements {
    private static final int MOD = 1000000007;

    // utility method to precompute prime number in an array
    private static boolean[] preComputePrimeNumbers(int n){
        boolean[] isPrime = new boolean[n+1];
        Arrays.fill(isPrime, true);

        // 0 and 1 are no prime
        isPrime[0] = isPrime[1] = false;

        for(int i=2; i*i <= n; i++){
            if(isPrime[i]){
                for(int j=i*i; j<=n; j+=i){
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    // utility method to compute factorial of number
    private static long getFactorialValue(int n){
        long f = 1;
        for(int i=2; i<=n; i++){
            f = (f * i) % MOD;
        }
        return f;
    }

    public static int numPrimeArrangements(int n) {
        // step 1 - pre compute prime numbers in array
        boolean[] isPrimeNumbers = preComputePrimeNumbers(n);

        // step 2 - count prime numbers from 1 to n
        int primeCount = 0;
        for(int i=1; i<=n; i++){
            if(isPrimeNumbers[i]){
                primeCount++;
            }
        }

        // step 3 - find number of permutations for prime numbers
        long np = getFactorialValue(primeCount);

        // step 4 - find number of permutations for non-prime numbers
        long nnp = getFactorialValue(n - primeCount);

        // step 5 - compute the result and return it
        long res = (np * nnp) % MOD;
        return (int)res;
    }

    public static void main(String[] args) {
        // int n = 5;

        int n = 100;
        System.out.println(numPrimeArrangements(n));
    }
}