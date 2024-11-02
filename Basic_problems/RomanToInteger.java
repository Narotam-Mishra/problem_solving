
// Problem link : https://leetcode.com/problems/roman-to-integer/description/

package Basic_problems;

import java.util.*;

public class RomanToInteger {
    public static int romanToInt(String s) {
        Map<Character, Integer> romanMap = new HashMap<>();
        romanMap.put('I', 1);
        romanMap.put('V', 5);
        romanMap.put('X', 10);
        romanMap.put('L', 50);
        romanMap.put('C', 100);
        romanMap.put('D', 500);
        romanMap.put('M', 1000);

        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && romanMap.get(s.charAt(i)) < romanMap.get(s.charAt(i + 1))) {
                res -= romanMap.get(s.charAt(i));
            } else {
                res += romanMap.get(s.charAt(i));
            }
        }
        return res;
    }

    public static void main(String[] args) {
        String str = "III";

        // String str = "LVIII";

        // String str = "MCMXCIV";
        
        System.out.println(romanToInt(str));
    }
}
