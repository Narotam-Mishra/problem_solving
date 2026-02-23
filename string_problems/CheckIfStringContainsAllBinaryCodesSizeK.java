
// Problem link - https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

package string_problems;

import java.util.*;

public class CheckIfStringContainsAllBinaryCodesSizeK {
    public static boolean hasAllCodes(String s, int k) {
        int n = s.length();
        
        // store unique codes of length k
        Set<String> seen = new HashSet<>();
        
        // total possible binary codes of length k
        int codes = 1 << k;   // 2^k
        
        // step 1 - iterate over the string
        for (int i = k; i <= n; i++) {
            
            // step 2 - get substring of length k
            String sub = s.substring(i - k, i);
            
            // step 3 - if not already seen
            if (!seen.contains(sub)) {
                seen.add(sub);
                codes--;
            }
            
            // step 4 - if all possible codes are found
            if (codes == 0) {
                return true;
            }
        }

        // step 5 - otherwise return false
        return false;
    }

    public static void main(String[] args) {
        String s = "00110110";
        int k = 2;
        System.out.println(hasAllCodes(s, k));
    }
}
