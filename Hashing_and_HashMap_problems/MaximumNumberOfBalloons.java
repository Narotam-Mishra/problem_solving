
// Problem link : https://leetcode.com/problems/maximum-number-of-balloons/description/?envType=problem-list-v2&envId=string

package Hashing_and_HashMap_problems;

public class MaximumNumberOfBalloons {
    public static int maxNumberOfBalloons(String text) {
        // step 1 - initialize a frequency array for 26 letters of the alphabet
        int[] freq = new int[26];

        // step 2 - populate the frequency array based on the characters in the text
        for(char ch : text.toCharArray()){
            freq[ch - 'a']++;
        }
        
        // step 3 - compute the maximum number of "balloon" instances
        int bCount = freq[1];
        int aCount = freq[0];
        int lCount = freq[11] / 2;
        int oCount = freq[14] / 2;
        int nCount = freq[13];
        
        // step 4 - return the minimum count among all required characters
        return Math.min(bCount, Math.min(aCount, Math.min(lCount, Math.min(oCount, nCount))));
    }

    public static void main(String[] args) {
        // String text = "nlaebolko";

        // String text = "loonbalxballpoon";

        String text = "leetcode";
        System.out.println(maxNumberOfBalloons(text));
    }
}
