
// Problem link - https://leetcode.com/problems/alice-and-bob-playing-flower-game/?envType=daily-question&envId=2025-08-29

package NumberTheory_Problems;

public class AliceAndBobPlayingFlowerGame {
    public static long flowerGame(int n, int m) {
        // Alice wins when (x + y) is odd
        // this happens when one number is odd and the other is even

        // step 1 - count odd and even numbers in range [1, n]
        long oddN = (n + 1) / 2;
        long evenN = n / 2;

        // step 2 - count odd and even numbers in range [1, m]
        long oddM = (m + 1) / 2;
        long evenM = m / 2;

        // Alice wins when :-
        // x is odd and y is even or
        // x is even or y is odd

        // step 3 - return total count
        return (oddN * evenM) + (evenN * oddM);
    }

    public static void main(String[] args) {
        // int n = 3, m = 2;

        // int n = 1, m = 1;

        int n = 100000, m = 100000;
        System.out.println(flowerGame(n, m));
    }
}