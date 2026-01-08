
// Problem link - https://leetcode.com/problems/max-dot-product-of-two-subsequences/?envType=daily-question&envId=2026-01-08

package DynamicProgramming_problems;

public class MaxDotProductOfTwoSubsequences {
    private static int m, n;

    static final int NEG_VAL = Integer.MIN_VALUE / 2;

    private static  int[][] memo;

    private static int solveRec(int i, int j, int[] nums1, int[] nums2){
        // base case: if we reach the end of either array,
        // return a very small number to enforce
        if (i == m || j == n) {
            return (int) NEG_VAL;
        }

        // if already computed, return stored value
        if (memo[i][j] != (int) NEG_VAL) {
            return memo[i][j];
        }

        // value of taking current pair only
        int val = nums1[i] * nums2[j];

        // take both i and j and continue
        int takeBoth = val + solveRec(i + 1, j + 1, nums1, nums2);

        // skip nums2[j]
        int skipJ = solveRec(i, j + 1, nums1, nums2);

        // skip nums1[i]
        int skipI = solveRec(i + 1, j, nums1, nums2);

        // store and return the maximum of all choices
        memo[i][j] = Math.max(
            val,
            Math.max(takeBoth, Math.max(skipJ, skipI))
        );

        return memo[i][j];
    }
    
    public static int maxDotProduct(int[] nums1, int[] nums2) {
        // find size of `nums1` and `nums2`
        m = nums1.length;
        n = nums2.length;

        // initialize memo
        memo = new int[501][501];
        for(int i=0; i<501; i++){
            for(int j=0; j<501; j++){
                memo[i][j] = (int) NEG_VAL;
            }
        }

        // step 1 - start recursion from index (0, 0)
        return solveRec(0, 0, nums1, nums2);
    }

    public static void main(String[] args) {
        // int[] nums1 = {2,1,-2,5}, nums2 = {3,0,-6};

        // int[] nums1 = {3,-2}, nums2 = {2,-6,7};

        int[] nums1 = {-1,-1}, nums2 = {1,1};
        System.out.println(maxDotProduct(nums1, nums2));
    }
}
