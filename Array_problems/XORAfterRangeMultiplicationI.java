
// Problem link - https://leetcode.com/problems/xor-after-range-multiplication-queries-i/description/?envType=daily-question&envId=2026-04-08

package Array_problems;

public class XORAfterRangeMultiplicationI {
    public int xorAfterQueries(int[] nums, int[][] queries) {
        final int mod = (int)1e9 + 7;

        // step 1 - iterate on each query
        for (int[] query : queries) {
            // extract value from queries
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            // step 2 - perform given operation
            while (l <= r) {
                nums[l] = (int)((1L * nums[l] * v) % mod);

                l += k;
            }
        }

        // step 3 - perform XOR for all element
        int res = 0;
        for (int num : nums) {
            res ^= num;
        }

        // step 4 - return final result
        return res;
    }

    public static void main(String[] args) {
        XORAfterRangeMultiplicationI obj = new XORAfterRangeMultiplicationI();
        // int[] nums = {1,1,1};
        // int[][] queries = {{0,2,1,4}};

        int[] nums = {2,3,1,5,4};
        int[][] queries = {{1,4,2,3},{0,2,1,2}};
        System.out.println(obj.xorAfterQueries(nums, queries));
    }
}
