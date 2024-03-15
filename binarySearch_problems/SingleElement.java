
// Problem link - https://leetcode.com/problems/single-element-in-a-sorted-array/description/


package binarySearch_problems;

/**
 * SingleElement
 */
public class SingleElement {
    public int singleNonDuplicate(int[] nums) {
        int s = 0, e = nums.length - 1;

        while(s < e){
            int mid = s + (e - s)/2;

            if(mid%2 == 1){
                mid--;
            }

            // if pair is intact (i.e mid and mid+1 th elements are same)
            // discard left half of array
            if(nums[mid] == nums[mid+1]){
                s = mid + 2;
            }else{
                // otherwise discard right half of array
                e = mid - 1;
            }
        }
        // At this point, start,s and end,e converge to the single element
        return nums[s];
    }
}