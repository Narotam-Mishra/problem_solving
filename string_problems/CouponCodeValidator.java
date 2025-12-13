
// Problem link - https://leetcode.com/problems/coupon-code-validator/description/?envType=daily-question&envId=2025-12-13

package string_problems;

import java.util.*;

public class CouponCodeValidator {
    // helper class to store pair
    static class Pair {
        int priority;
        String code;

        Pair(int priority, String code) {
            this.priority = priority;
            this.code = code;
        }
    }

    // utility function to check if a coupon code is valid
    private static boolean isValidCode(String code) {
        if (code == null || code.isEmpty()) {
            return false;
        }
        for (char ch : code.toCharArray()) {
            if (!Character.isLetterOrDigit(ch) && ch != '_') {
                return false;
            }
        }
        return true;
    }

    public static List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {
        // map to store business line and its priorities
        Map<String, Integer> mp = new HashMap<>();
        mp.put("electronics", 0);
        mp.put("grocery", 1);
        mp.put("pharmacy", 2);
        mp.put("restaurant", 3);

        // {priority, index}
        List<Pair> res = new ArrayList<>();

        // step 1 - validate each coupon code
        for (int i = 0; i < code.length; i++){
            if(isActive[i] && isValidCode(code[i]) && mp.containsKey(businessLine[i])){
                res.add(new Pair(mp.get(businessLine[i]), code[i]));
            }
        }

        // step 2 - sort based on priority
        Collections.sort(res, (a, b) -> {
            if(a.priority != b.priority){
                return a.priority - b.priority;
            }
            return a.code.compareTo(b.code);
        });

        // step 3 - extract codes from sorted pairs
        List<String> result = new ArrayList<>();
        for (Pair p : res) {
            result.add(p.code);
        }

        // step 4 - return the result
        return result;
    }

    public static void main(String[] args) {
        // String[] code = {"SAVE20", "", "PHARMA5", "SAVE@20"};
        // String[] businessLine = {"restaurant","grocery","pharmacy","restaurant"};
        // boolean[] isActive = {true, true, true, true};

        String[] code = {"GROCERY15","ELECTRONICS_50","DISCOUNT10"};
        String[] businessLine = {"grocery","electronics","invalid"};
        boolean[] isActive = {false, true, true};
        
        List<String> res = validateCoupons(code, businessLine, isActive);
        System.out.println(res); 
    }
}
