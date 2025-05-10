
// Problem link - https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/?envType=problem-list-v2&envId=string

package string_problems;

public class LongerContiguousSegmentsOfOnesThanZeros {
    public static boolean checkZeroOnes(String s) {
        // step 1 - initialize variables to keep track of the maximum length of contiguous segments of 1s and 0s
        int maxOnes = 0, maxZeros = 0;

        // step 2 - initialize variables to keep track of the current character and its count
        char currChar = s.charAt(0);
        int currCount = 1;

        // step 3 - iterate on each chacter of `s` starting from 1st index
        for(int i=1; i<s.length(); i++) {
            // step 4 - continue counting current segemnt
            if(s.charAt(i) == currChar){
                currCount++;
            }else{
                // step 5 - when contiguous segment ends, update max length of 1s and 0s
                if(currChar == '1'){
                    maxOnes = Math.max(maxOnes, currCount);
                }else{
                    maxZeros = Math.max(maxZeros, currCount);
                }

                // step 6 - reset current character and count
                currChar = s.charAt(i);
                currCount = 1;
            }
        }

        // step 7 - update last segemnt after loop ends
        if (currChar == '1') {
            maxOnes = Math.max(maxOnes, currCount);
        } else {
            maxZeros = Math.max(maxZeros, currCount);
        }

        // step 8 - return true if max length of 1s is greater than max length of 0s
        return maxOnes > maxZeros;
    }

    public static void main(String[] args) {
        String s = "1101";

        // String s = "111000";
        System.out.println(checkZeroOnes(s));
    }
}