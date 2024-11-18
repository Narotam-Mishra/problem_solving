
// Problem link : https://leetcode.com/problems/three-divisors/description/?envType=problem-list-v2&envId=number-theory&status=TO_DO%2CATTEMPTED&difficulty=EASY

package NumberTheory_Problems;

public class ThreeDivisors {

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

    public static boolean isThree(int n) {
        // check if n is a perfect square
        int sqrtNum = (int) Math.sqrt(n);

        if(sqrtNum * sqrtNum != n){
            // not a perfect square
            return false;
        }
        // check if the square root of n is a prime number
        return isPrime(sqrtNum);
    }

    public static void main(String[] args) {
        // int n = 2;

        // int n = 4;

        int n = 12;
        System.out.println(isThree(n));
    }
}