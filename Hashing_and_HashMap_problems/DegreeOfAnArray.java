
// Problem link : https://leetcode.com/problems/degree-of-an-array/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class DegreeOfAnArray {
    public static int findShortestSubArray1(int[] nums) {
        // step 1 - create maps
        Map<Integer, Integer> map = new HashMap<>();
        Map<Integer, Integer> firstIndex = new HashMap<>();
        Map<Integer, Integer> lastIndex = new HashMap<>();

        // step 2 - populate map
        for(int i=0; i<nums.length; i++){
            int num = nums[i];
            map.put(num, map.getOrDefault(num, 0) + 1);
            if(!firstIndex.containsKey(num)){
                firstIndex.put(num, i);
            }
            lastIndex.put(num, i);
        }

        // step 3 - detemine degree
        int degree = 0;
        for(int frq : map.values()){
            degree = Math.max(frq, degree);
        }

        // step 4 - find the smallest subarray length
        int minLengthSubArray = Integer.MAX_VALUE;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int num = entry.getKey();
            int freq = entry.getValue();
            if (freq == degree) {
                int subArrLen = lastIndex.get(num) - firstIndex.get(num) + 1;
                minLengthSubArray = Math.min(minLengthSubArray, subArrLen);
            }
        }

        // step 5 - return the result
        return minLengthSubArray;
    }

    public static int findShortestSubArray(int[] nums) {
        // step 1 - find max number in nums
        int maxNum = 0;
        for(int num : nums){
            maxNum = Math.max(maxNum, num);
        }

        // step 2 - create map using array
        int[] map = new int[maxNum + 1];
        int[] lastIndex = new int[maxNum + 1];
        int[] firstIndex = new int[maxNum + 1];

        // step 3 - populate map array and find degree
        int degree = 0;
        for(int i=0; i<nums.length; i++){
            int num = nums[i];
            map[num]++;
            degree = Math.max(degree, map[num]);
            if(map[num] == 1){
                firstIndex[num] = i;
            }
            lastIndex[num] = i;
        }

        // step 4 - find the smallest subarray length
        int minLengthSubArray = Integer.MAX_VALUE;
        for (int num=0; num <= maxNum; num++) {
            if(map[num] == degree){
                int subArrLen = lastIndex[num] - firstIndex[num] + 1;
                minLengthSubArray = Math.min(minLengthSubArray, subArrLen);
            }
        }

        // step 5 - return the result
        return minLengthSubArray;
    }

    public static void main(String[] args) {
        int[] nums = {1,2,2,3,1};

        // int[] nums = {1,2,2,3,1,4,2};
        System.out.println(findShortestSubArray(nums));
    }
}