
// Problem link - https://leetcode.com/problems/di-string-match/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.Arrays;

public class DIStringMatch {
    public static int[] diStringMatch(String s) {
        // step 1 - intialize all necessary variables and store result into `res`
        int n = s.length();
        int low = 0;
        int high = n;
        int[] res = new int[n + 1];

        // step 2 - iterate on `s`
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'I') {
                // step 3 - if 'I', assign the lowest number and increment low
                res[i] = low;
                low++;
            } else {
                // step 4 - if 'D', assign the highest number and decrement high
                res[i] = high;
                high--;
            }
        }

        // step 5 - after the loop, one number (low === high) remains to be added
        res[n] = low;

        // step 6 - return `res`
        return res;
    }

    public static void main(String[] args) {
        // String s = "IDID";

        // String s = "III";

        String s = "DDI";
        System.out.println(Arrays.toString(diStringMatch(s)));
    }
}