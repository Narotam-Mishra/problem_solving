
// Problem link - https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class FindAllKDistantIndicesInArray {
    public static List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        int n = nums.length;

        // store key indices that matches nums[j] == key
        List<Integer> keyIndices = new ArrayList<>();
        
        // store result in `res` list
        List<Integer> res = new ArrayList<>();

        // step 1 - find all indices where `nums[j] == key`
        for(int j=0; j<n; j++){
            if(nums[j] == key){
                keyIndices.add(j);
            }
        }

        // step 2 - for each index `i`, check if any key is within diatance `k`
        for(int i=0; i<n; i++){
            boolean isKDistant = false;

            // step 3 - check each key position
            for(int j : keyIndices){
                if(Math.abs(i - j) <= k){
                    isKDistant = true;
                    break;
                }
            }

            // if current index is within k-distance then add it to result
            if(isKDistant){
                res.add(i);
            }
        }

        // step 4 - return final result `res`
        return res;
    }

    public static void main(String[] args) {
        // int[] nums = {3,4,9,1,3,9,5};
        // int key = 9, k = 1;

        int[] nums = {2,2,2,2,2};
        int key = 2, k = 2;
        List<Integer> res = findKDistantIndices(nums, key, k);
        System.out.println(res);
    }
}
