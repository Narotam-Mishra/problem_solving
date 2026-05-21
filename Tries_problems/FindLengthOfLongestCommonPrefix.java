
// Problem link - https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2026-05-21

package Tries_problems;

import java.util.*;

public class FindLengthOfLongestCommonPrefix {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        // step 1 - build a set of all prefixes (as integers) that appear in arr1.
        Set<Integer> set = new HashSet<>();
        for(int val : arr1){
            // insert val and all its numeric prefixes until 0 or prefix already seen.
            while(val > 0 && !set.contains(val)){
                set.add(val);

                // drop the last digit to get the next shorter prefix
                val = val / 10;
            }
        }

        // keep track of longest prefix seen so far
        int longestPrefix = 0;
        
        // step 2 - now check numbers in arr2: reduce each number to its longest prefix
        for(int num : arr2){
            // reduce num until its current value is found in st or becomes 0.
            while(num > 0 && !set.contains(num)){
                // drop last digit
                num = num / 10;
            }

            // step 3 - check If we found a matching prefix (num > 0), compute its length in digits
            if(num > 0){
                longestPrefix = Math.max(longestPrefix, (int)Math.log10(num) + 1);
            }
        }

        // step 4 - return the maximum common prefix length found
        return longestPrefix;
    }

    public static void main(String[] args) {
        int[] arr1 = {1,10,100}, arr2 = {1000};
        FindLengthOfLongestCommonPrefix obj = new FindLengthOfLongestCommonPrefix();
        System.out.println(obj.longestCommonPrefix(arr1, arr2));
    }
}
