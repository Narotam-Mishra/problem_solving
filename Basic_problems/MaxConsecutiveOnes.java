
package Basic_problems;

public class MaxConsecutiveOnes {
    public static int findMaxConsecutiveOnes(int[] nums) {
        int maxOne = 0 , counter = 0;

        for(int i=0; i<nums.length; i++){
            if(nums[i] == 1){
                counter++;
                maxOne = Math.max(maxOne, counter);
            }else{
                counter = 0;
            }
        }
        return maxOne;
    }

    public static void main(String[] args) {
        int[] arr = {1,1,0,1,1,1};
        System.out.println(findMaxConsecutiveOnes(arr));
    }
}