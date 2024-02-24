package Array_problems;

import java.util.Arrays;

public class ContainDuplicates {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);

        for(int i=0; i<nums.length; i++) {
            if(i>0 && nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;
    }
}
