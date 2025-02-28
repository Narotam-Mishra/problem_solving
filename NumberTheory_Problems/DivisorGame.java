
// Problem link - https://leetcode.com/problems/divisor-game/?envType=problem-list-v2&envId=math

package NumberTheory_Problems;

public class DivisorGame {
    private static boolean divisorGameHelper(int n, boolean[] cache){
        // base case : if n is 1, Alice loses immediately
        if(n == 1) return false;

        // if `n` is already computed then return its value
        if(cache[n]) return cache[n];

        // step 1 - iterate on all possible value of `n`
        for(int x=1; x<n; x++){
            // step 2 - if `x` is valid move and if that move make Bob lose then Alice wins
            if(n % x == 0 && !divisorGameHelper(n-x, cache)){
                return cache[n] = true;
            }
        }

        // step 3 - if no winning move is found, Alice lose
        return cache[n] = false;
    }

    public static boolean divisorGame1(int n) {
        boolean[] cache = new boolean[n+1];
        return divisorGameHelper(n, cache);
    }

    public static boolean divisorGame(int n) {
        // Alice can only win if and only if n is even
        return n % 2 == 0;
    }

    public static void main(String[] args) {
        // int n = 2;

        int n = 3;
        System.out.println(divisorGame(n));
    }
}