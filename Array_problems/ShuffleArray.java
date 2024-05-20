package Array_problems;

/**
 * ShuffleArray
 */
public class ShuffleArray {

    public static int[] shuffleArray(int[] nums, int n){
        int[] res = new int[2*n];
        for(int i=0; i<n; i++){
            res[2*i] = nums[i];
            res[2*i+1] = nums[i+n];
        }
        return res;
    }
}