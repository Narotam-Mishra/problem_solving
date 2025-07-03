package Array_problems;

import java.util.Arrays;

public class DecompressRunLengthEncodedList {
    public static int[] decompressRLElist(int[] nums) {
        int n = nums.length;

        // step 1 - calculate total size needed for result array
        int totalSize = 0;
        for(int i=0; i<n; i+=2){
            totalSize += nums[i];
        }

        // store resultant decompressed list in `res`
        int[] res = new int[totalSize];
        int index = 0;

        // step 2 - iterate on input array `nums`
        for(int i=0; i<n; i+=2){
            // step 3 - extract frq and value
            int frq = nums[i];
            int val = nums[i+1];

            // step 4 - fill the value in `res`
            while(frq > 0){
                res[index++] = val;
                frq--;
            }
        }

        // step 5 - return resultant array `res`
        return res;
    }

    public static void main(String[] args) {
        // int[] nums = {1,2,3,4};

        int[] nums = {1,1,2,3};
        int[] res = decompressRLElist(nums);
        System.out.println(Arrays.toString(res));
    }
}