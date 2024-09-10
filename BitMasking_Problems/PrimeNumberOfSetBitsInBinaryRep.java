
// Problem link : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class PrimeNumberOfSetBitsInBinaryRep {

    private static boolean isPrime(int n){
        // corner case:
        if(n <= 1){
            return false;
        }

        // check from 2 to sqrt(n)
        for(int i=2; i<=Math.sqrt(n); i++){
            if(n % i == 0) return false;
        }
        // if no divisors are found, n is prime
        return true;
    }

    public static int countPrimeSetBits(int left, int right) {
        // initialize counter for numbers with prime set bits
        int cntPrimeSetBits = 0;

        // iterate through all numbers in the range [left, right]
        for(int i=left; i<=right; i++){
            int num = i, setBits = 0;

            // count the number of set bits (1s) in the binary representation of num
            while(num > 0){
                // increment setBits if the least significant bit is 1
                setBits += num & 1;
                // right shift num to check the next bit
                num >>= 1;
            }

            // check if the number of set bits is prime
            if(isPrime(setBits)){
                // increment counter if setBits is prime
                cntPrimeSetBits++;
            }
        }

        // return the total count of numbers with prime set bits
        return cntPrimeSetBits;
    }

    public static void main(String[] args) {
        // int left = 6, right = 10;

        int left = 10, right = 15;
        System.out.println(countPrimeSetBits(left, right));
    }
}
