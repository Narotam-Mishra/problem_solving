
// Problem link - https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/?envType=problem-list-v2&envId=string

package string_problems;

public class MaximumValueOfStringInArray {
    private static boolean isNumeric(String str){
        try {
            Integer.parseInt(str);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    public static int maximumValue(String[] strs) {
        // step 1 - initialize variable to find maximum value of `strs`
        int maxVal = 0;

        // step 2 - iterate on each str of `strs` 
        for(String str : strs){
            if(!isNumeric(str)){
                // step 3 - if str is not number then find its length
                int n = str.length();

                // and update maximum value
                maxVal = Math.max(maxVal, n);
            }else{
                // step 4 - otherwise find maximum numeric value
                maxVal = Math.max(maxVal, Integer.parseInt(str));
            }
        }

        // step 5 - return maximum value
        return maxVal;
    }

    public static void main(String[] args) {
        // String[] strs = {"alic3","bob","3","4","00000"};

        String[] strs = {"1","01","001","0001"};
        System.out.println(maximumValue(strs));
    }
}