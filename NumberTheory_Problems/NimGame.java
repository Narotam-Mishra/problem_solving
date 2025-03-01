
// Problem link - https://leetcode.com/problems/nim-game/?envType=problem-list-v2&envId=brainteaser

package NumberTheory_Problems;

public class NimGame {
    public static boolean canWinNim(int n) {
        // you can win if and only if n is not dvisible by 4
        return n % 4 != 0;
    }

    public static void main(String[] args) {
        // int n = 4;

        // int n = 1;

        int n = 2;
        System.out.println(canWinNim(n));
    }
}