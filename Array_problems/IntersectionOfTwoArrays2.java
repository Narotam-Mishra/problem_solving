
// Problem link - https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
// Approach - Two pointers

package Array_problems;

import java.util.*;

public class IntersectionOfTwoArrays2 {
    public static int[] intersect(int[] nums1, int[] nums2) {
        // sort both arrays
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        // take two poinyers to iterate on arrays and find common elements
        int i = 0, j = 0;

        ArrayList<Integer> resList = new ArrayList<>();
        while(i < nums1.length && j < nums2.length){
            if(nums1[i] < nums2[j]){
                i++;
            }else if(nums1[i] > nums2[j]){
                j++;
            }else{
                // found first common element, 
                resList.add(nums1[i]);
                i++;
                j++;
            }
        }

        // copy resList items to res array
        int[] res = new int[resList.size()];
        for(int k=0; k<resList.size(); k++){
            res[k] = resList.get(k);
        }
        return res;
    }

    public static int[] intersect1(int[] nums1, int[] nums2) {
        // HashMap to store counts of numbers
        Map<Integer, Integer> map = new HashMap<>();

        // ArrayList to store intersecting elements
        ArrayList<Integer> resList = new ArrayList<>();

        // count frequecy of each element of nums1 array
        for(int num : nums1){
            map.put(num, map.getOrDefault(num, 0)+1);
        }

        // Check for intersecting elements in nums2 and decrement counts in map
        for(int num : nums2){
            if(map.containsKey(num) && map.get(num) > 0){
                // Add intersecting element to resultList
                resList.add(num);
                // Decrement count in map
                map.put(num, map.get(num)-1);
            }
        }

        // copy resList items to res array
        int[] res = new int[resList.size()];
        for(int k=0; k<resList.size(); k++){
            res[k] = resList.get(k);
        }
        return res;
    }

    public static void main(String[] args) {
        int[] arr1 = {4,9,5};
        int[] arr2 = {9,4,9,8,4};
        // int[] ans = intersection(arr1, arr2);
        int[] ans = intersect1(arr1, arr2);
        System.out.println(Arrays.toString(ans));
    }
}
