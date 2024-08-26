
// Problem link : https://leetcode.com/problems/largest-number/

package Array_problems;

import java.util.*;

public class LargestNumber {
    public static String largestNumber(int[] nums) {
        // convert the integer array to a string array for comparison
        String[] strNums = new String[nums.length];

        for(int i=0; i<nums.length; i++){
            strNums[i] = String.valueOf(nums[i]);
        }

        // custom comparator to compare concatenated strings
        Arrays.sort(strNums, new Comparator<String>() {
            @Override
            public int compare(String a, String b){
                String order1 = a + b;
                String order2 = b + a;

                // sort in descending order
                return order2.compareTo(order1);
            }
        });

        // if the largest number is "0", return "0"
        if(strNums[0].equals("0")){
            return "0";
        }

        // concatenate the sorted strings to form largest number (in string)
        StringBuilder largestNum = new StringBuilder();
        for(String num : strNums){
            largestNum.append(num);
        }

        // return largest number in string form
        return largestNum.toString();
    }

    public static void main(String[] args) {
        int[] nums = {3, 30, 34, 5, 9};
        System.out.println(largestNumber(nums));
    }
}