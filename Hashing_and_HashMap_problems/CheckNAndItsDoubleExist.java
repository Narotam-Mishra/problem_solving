
// Problem link : https://leetcode.com/problems/check-if-n-and-its-double-exist/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class CheckNAndItsDoubleExist {
    public static boolean checkIfExist1(int[] arr) {
        // step 1 - iterate through input array
        int n = arr.length;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // step 2 - check if double of current element exists in array
                if(i!=j && arr[i] == 2*arr[j]){
                    return true;
                }
            }
        }
        // step 3 - otherwise return false
        return false;
    }

    public static boolean checkIfExist(int[] arr) {
        // step 1 - initialize a Set to store elements we have seen so far
        Set<Integer> seen = new HashSet<>();
        
        // step 2 - iterate through the array
        for (int num : arr) {
            // check given condition
            if (seen.contains(num * 2) || (num % 2 == 0 && seen.contains(num / 2))) {
                return true;
            }
            // step 3 - add the current number to the set
            seen.add(num);
        }

        // step 4 - if no such pair is found, return false
        return false;
    }

    public static void main(String[] args) {
        // int[] arr = {10,2,5,3};

        int[] arr = {3,1,7,11};
        System.out.println(checkIfExist(arr));
    }
}