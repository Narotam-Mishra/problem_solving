
// Problem link - https://leetcode.com/problems/perfect-squares/description/

package Recursion_problems;

public class PerfectSquaresRec {
    public static int[] sqArr;

    private static int PerfectSquaresRecurive(int num){
        // Base case: if num is 0 return 0
        if(num == 0) return 0;

        int ans = Integer.MAX_VALUE;
        int len = sqArr.length;

        // Recursive case f(num) = 1 + min(f(num - sqArr[i]))
        for(int i=1; i<len; i++){
            if(num >= sqArr[i]){
                ans = Math.min(ans, PerfectSquaresRecurive(num - sqArr[i]));
            }
        }

        return 1 + ans;
    }

    public static int numSquares(int n) {
        sqArr = new int[n+1];
        for(int i=1; i<=n; i++){
            sqArr[i] = i*i;
        }
        int res = PerfectSquaresRecurive(n);
        return res;
    }

    public static void main(String[] args) {
        int num = 13;
        System.out.println(numSquares(num));
    }
}
