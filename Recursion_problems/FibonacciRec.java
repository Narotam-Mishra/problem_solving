
// Problem link - https://leetcode.com/problems/fibonacci-number/description/

package Recursion_problems;

public class FibonacciRec {
    private static int fibonacciRec(int n){
        if(n == 0 || n == 1) return n;

        return fibonacciRec(n-1) + fibonacciRec(n-2);
    }
    public int fib(int n) {
        return fibonacciRec(n);
    }
}
