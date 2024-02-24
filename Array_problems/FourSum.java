
// Problem link - https://leetcode.com/problems/4sum/description/

package Array_problems;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class FourSum {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> resArr = new ArrayList<>();

        for(int i=0; i<nums.length-3; i++){
            // avoid duplicates
            if(i>0 && nums[i-1] == nums[i]) continue;

            for(int j=i+1; j<nums.length-2; j++){
                // avoid duplicates
                if(j>i+1 && nums[j-1] == nums[j]) continue;
                int l = j+1, r = nums.length - 1;

                while(l < r){
                    // added long to handle edge case
                    long sum = (long)nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum == target){
                        //if sum found add quadruplets to the list
                        resArr.add(Arrays.asList(nums[i], nums[j], nums[l], nums[r]));
                        // avoid duplicates
                        while(l < r && nums[l] == nums[l+1]) l++;
                        while (l < r && nums[r] == nums[r-1]) r--;
                        l++;
                        r--;
                    }else if(sum > target){
                        r--;
                    }else{
                        l++;
                    }
                }
            }
        }
        return resArr;
    }
}
