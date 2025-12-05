package Array_problems;

public class CountPartitionsWithEvenSumDifference {
    public static int countPartitions(int[] nums) {
        int n = nums.length;

        // step 1 - find prefix sum of `nums`
        int[] prefixSum = new int[n];
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        // step 2 - count partition
        int c = 0;
        int total = prefixSum[n - 1];
        for (int i = 0; i < n - 1; i++) {
            // find left sum
            int leftSum = prefixSum[i];

            // find right sum
            int rightSum = total - leftSum;

            // calculate difference, `diff`
            int diff = leftSum - rightSum;

            // check if diff is even or not
            if ((diff & 1) == 0) {
                // count partitions
                c++;
            }
        }

        // step 3 - return count valid partitions, `c`
        return c;
    }

    public static void main(String[] args) {
        // int[] nums = {10,10,3,7,6};

        // int[] nums = {1,2,2};

        int[] nums = {2,4,6,8};
        System.out.println(countPartitions(nums));
    }
}
