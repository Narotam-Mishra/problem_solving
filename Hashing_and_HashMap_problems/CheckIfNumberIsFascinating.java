
// Problem link : https://leetcode.com/problems/check-if-the-number-is-fascinating/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class CheckIfNumberIsFascinating {
    public static boolean isFascinating1(int n) {
        // step 1 - compute multiples as per problem
        int twice = 2 * n;
        int thrice = 3 * n;

        // step 2 - concatenate n, 2n, and 3n
        String concateNum = String.valueOf(n) + twice + thrice;

        // step 3 - check for required edge cases
        if(concateNum.length() != 9 || concateNum.contains("0")){
            return false;
        }

        // step 4 - check if all digits 1-9 appear exactly once
        Set<Character> digitSet = new HashSet<>();
        for(char digit : concateNum.toCharArray()){
            digitSet.add(digit);
        }

        return digitSet.size() == 9;
    }

    public static boolean isFascinating(int n) {
        // directly return true if n is one of the only four fascinating numbers
        return n == 192 || n == 219 || n == 273 || n == 327;
    }

    public static void main(String[] args) {
        int n = 192;

        // int n = 100;
        System.out.println(isFascinating(n));
    }
}