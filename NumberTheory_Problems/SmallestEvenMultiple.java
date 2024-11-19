
// Problem link : https://leetcode.com/problems/smallest-even-multiple/description/?envType=problem-list-v2&envId=number-theory&status=TO_DO&difficulty=EASY

package NumberTheory_Problems;

public class SmallestEvenMultiple {
    public static int smallestEvenMultiple(int n) {
        // check if n is even
        // if n is divisible by 2, it is already the smallest even multiple
        if(n % 2 == 0) return n;
        
        // if n is odd, the smallest even multiple is n * 2
        return n * 2;
    }

    public static void main(String[] args) {
        // int n = 5;

        int n = 6;
        System.out.println(smallestEvenMultiple(n));
    }
}