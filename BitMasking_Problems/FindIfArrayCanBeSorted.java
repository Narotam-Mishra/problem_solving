
// Problem link : https://leetcode.com/problems/find-if-array-can-be-sorted/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class FindIfArrayCanBeSorted {
    // utility method to count set bits
    private static int countSetBits(int num){
        int setBits = 0;
        while(num > 0){
            setBits += num & 1;
            num = num >> 1;
        }
        return setBits;
    }

    // utility method to check if array is sorted or not
    private static boolean isSorted(int[] nums){
        for(int i=1; i<nums.length; i++){
            if(nums[i-1] > nums[i]) return false;
        }
        return true;
    }

    public static boolean canSortArray(int[] nums) {
        int n = nums.length;

        // outer loop for passes
        for(int i=0; i<n-1; i++){
            // inner loop for comparisons in each pass
            for(int j=0; j<n-i-1; j++){
                // if adjacent elements can be swapped and are in wrong order
                if(countSetBits(nums[j]) == countSetBits(nums[j+1]) && nums[j] > nums[j+1]){
                    // swap
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }

        // check if array can be sorted or not
        return isSorted(nums);
    }

    public static void main(String[] args) {
        // int[] nums = {8, 4, 2, 30, 15};

        // int[] nums = {3,16,8,4,2};

        // int[] nums = {1, 2, 3, 4, 5};

        int[] nums = {20, 16};
        System.out.println(canSortArray(nums));
    }
}