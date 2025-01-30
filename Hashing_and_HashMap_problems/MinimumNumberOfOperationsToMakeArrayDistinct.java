package Hashing_and_HashMap_problems;

public class MinimumNumberOfOperationsToMakeArrayDistinct {
    public static int minimumOperations(int[] nums) {
        // edge case:
        if(nums.length <= 1) return 0;

        // step 1 - create boolean array map to track seen numbers
        boolean[] freqMap = new boolean[101];
        
        // step 2 - traverse the array from the last element to the first (right to left)
        for(int i=nums.length-1; i>=0; i--) {
            if(freqMap[nums[i]]){
                // step 3: compute the minimum number of operations required
                return (i+3)/3;
            }
            // mark the number in frquency array map
            freqMap[nums[i]] = true;
        }
        return 0;
    }

    public static void main(String[] args) {
        // int[] nums = {1,2,3,4,2,3,3,5,7};

        int[] nums = {4,5,6,4,4};
        System.out.println(minimumOperations(nums));
    }
}
