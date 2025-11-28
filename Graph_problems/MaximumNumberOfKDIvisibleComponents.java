
// Problem link - https://leetcode.com/problems/maximum-number-of-k-divisible-components/?envType=daily-question&envId=2025-11-28

package Graph_problems;

public class MaximumNumberOfKDIvisibleComponents {
    public static int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        return 0;
    }

    public static void main(String[] args) {
        int n = 5;
        int[][] edges = {{0,2},{1,2},{1,3},{2,4}};
        int[] values = {1,8,1,4,4};
        int k = 6;
        System.out.println(maxKDivisibleComponents(n, edges, values, k));
    }
}
