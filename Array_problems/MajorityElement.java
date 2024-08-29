
// Problem link : https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-100-liked

package Array_problems;

public class MajorityElement {

    public static int majorityElement(int[] nums) {
        int reqNum = nums[0];
        int count = 1;

        for(int i=1; i<nums.length; i++){
            if(reqNum == nums[i]){
                count++;
            }else{
                count--;
                if(count == 0){
                    reqNum = nums[i];
                    count = 1;
                }
            }
        }
        return reqNum;
    }

    public static void main(String[] args) {
        int[] nums = {2,2,1,1,1,2,2};
        System.out.println(majorityElement(nums));
    }
}