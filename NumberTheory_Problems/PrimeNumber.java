
// Problem link : https://www.geeksforgeeks.org/problems/prime-number2314/1

package NumberTheory_Problems;

public class PrimeNumber {
    public static int isPrime(int n){
        // corner case:
        if(n <= 1){
            return 0;
        }

        // check from 2 to sqrt(n)
        for(int i=2; i<=Math.sqrt(n); i++){
            if(n % i == 0) return 0;
        }
        // if no divisors are found, n is prime
        return 1;
    }

    public static void main(String[] args) {
        // int num = 11;

        int num = 10007;
        System.out.println(isPrime(num));
    }
}