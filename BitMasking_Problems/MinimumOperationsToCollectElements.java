
// Problem link : https://leetcode.com/problems/minimum-operations-to-collect-elements/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

package BitMasking_Problems;

import java.util.*;

public class MinimumOperationsToCollectElements {
    public static int minOperations(List<Integer> nums, int k) {
        // initialize a set to keep track of collected elements from 1 to k
        Set<Integer> collSet = new HashSet<>();
        int minOps = 0;

        // traverse the array from the last element to the first
        for(int i=nums.size()-1; i>=0; i--){
            // perform one operation (remove the last element)
            minOps++;

            // if the current element is between 1 and k, 
            // add it to the collected set
            if(nums.get(i) >= 1 && nums.get(i) <= k){
                collSet.add(nums.get(i));
            }

            // if we've collected all elements from 1 to k, we can stop
            if(collSet.size() == k) break;
        }

        // return the number of operations performed
        return minOps;
    }

    public static void main(String[] args) {
        // List<Integer> nums = Arrays.asList(3,1,5,4,2);
        // int k = 2;

        List<Integer> nums = Arrays.asList(3,1,5,4,2);
        int k = 5;
        System.out.println(minOperations(nums, k));
    }
}