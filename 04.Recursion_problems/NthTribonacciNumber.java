
// Problem link - https://leetcode.com/problems/n-th-tribonacci-number/description/

package Recursion_problems;

/**
 * NthTribonacciNumber
 */
public record NthTribonacciNumber() {
    public static int tribonacci(int n) {
        if(n == 0) return 0;
        else if(n == 1 || n == 2) return 1;
        else{
            return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        }
    }

    public static void main(String[] args) {
        int num = 25;
        System.out.println(tribonacci(num));
    }
}