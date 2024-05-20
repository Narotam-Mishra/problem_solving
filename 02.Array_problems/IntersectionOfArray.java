
// Problem link - https://leetcode.com/problems/intersection-of-two-arrays/description/

package Array_problems;

import java.util.*;

public class IntersectionOfArray {
    public static int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        // two pointers i and j to interate on array
        int i = 0, j = 0;

        List<Integer> resList = new ArrayList<>();
        while (i < nums1.length && j < nums2.length) {
            if(nums1[i] < nums2[j]){
                i++;
            }else if(nums1[i] > nums2[j]){
                j++;
            }else{
                // found first common element, also we have to make sure we are not duplicating the same element 
                // as we need to store unique element in result array res[]
                if(resList.size() == 0 || resList.get(resList.size() - 1) != nums1[i]){
                    resList.add(nums1[i]);
                }
                i++;
                j++;
            }
        }

        // copy resList items to res array
        int[] res = new int[resList.size()];
        for(int id=0; id<resList.size(); id++){
            res[id] = resList.get(id);
        }
        return res;
    }

    public static int[] intersection1(int[] nums1, int[] nums2) {
        Set<Integer> numSet = new HashSet<>();
        Set<Integer> intersectionSet = new HashSet<>();

        // add nums1 elements to numSet
        for(int num : nums1){
            numSet.add(num);
        }

        // check if numSet items are present in nums2 array or not
        // if they are present then add those items to intersectionSet
        for(int num : nums2){
            if(numSet.contains(num)){
                intersectionSet.add(num);
            }
        }

        int[] res = new int[intersectionSet.size()];
        int i = 0;
        for(int num : intersectionSet){
            res[i++] = num;
        }
        return res;
    }

    public static void main(String[] args) {
        int[] arr1 = {4,9,5};
        int[] arr2 = {9,4,9,8,4};
        // int[] ans = intersection(arr1, arr2);
        int[] ans = intersection1(arr1, arr2);
        System.out.println(Arrays.toString(ans));
    }
}
