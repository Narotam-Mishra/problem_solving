
// Problem link : https://leetcode.com/problems/power-of-three/description/

package NumberTheory_Problems;

public class PowerOfThree {
    public static boolean isPowerOfThree(int n) {
        // base case:
        if(n < 1) return false;

        // loop case:
        while(n % 3 == 0){
            n = n / 3;
        }
        return n == 1;
    }

    public static void main(String[] args) {
        // int num = 27;

        // int num = 0;

        int num = -1;
        System.out.println(isPowerOfThree(num));
    }
}