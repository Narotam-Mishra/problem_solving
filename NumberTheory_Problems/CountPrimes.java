
// Problem link - https://leetcode.com/problems/count-primes/description/

package NumberTheory_Problems;

public class CountPrimes {

    private static int[] primeSieve(int maxN){
        int[] primes = new int[maxN + 1];

        // first mark all odd numbers as prime starting from 3
        for(int i=3; i<=maxN; i+=2){
            primes[i] = 1;
        }

        // prime sieve logic
        for(int i=3; i<=maxN; i+=2){
            // if the current number is not marked then it is prime
            if(primes[i] == 1){
                // mark all the multiples of i as not prime
                for(long j = (long)i*i; j<=maxN; j+=i){
                    primes[(int)j] = 0;
                }
            }
        }

        // special cornor case:
        primes[2] = 1;
        primes[0] = primes[1] = 0;

        return primes;
    }

    public static int countPrimes(int n) {
        int count = 0;

        // get all primes in an array
        int[] primes = primeSieve(n);

        // iterate through number in given range
        for(int i=1; i<n; i++){
            if(primes[i] == 1) count++;
        }

        // return count of prime numbers
        return count;
    }

    public static void main(String[] args) {
        int num = 10;
        System.out.println(countPrimes(num));
    }
}