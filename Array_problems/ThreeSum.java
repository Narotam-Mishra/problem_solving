package Array_problems;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSum {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> resArr = new ArrayList<>();

        for(int i=0; i<nums.length-2; i++) {
            // avoid duplicates
            if(i>0 && nums[i-1] == nums[i]) continue;

            int l = i+1, r = nums.length - 1, sum = 0;

            while(l < r){
                sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    // add triplets to the list
                    resArr.add(Arrays.asList(nums[i], nums[l], nums[r]));
                    // avoid duplicates
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while (l < r && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }else if(sum > 0){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return resArr;
    }
}
