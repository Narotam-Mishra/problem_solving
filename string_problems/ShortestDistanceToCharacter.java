
// Problem link : https://leetcode.com/problems/shortest-distance-to-a-character/description/?envType=problem-list-v2&envId=string&difficulty=EASY&status=TO_DO

package string_problems;

import java.util.Arrays;

public class ShortestDistanceToCharacter {
    public static int[] shortestToChar(String s, char c) {
        int len = s.length();

        int[] res = new int[len];
        // initialize result array with Infinity
        Arrays.fill(res, Integer.MAX_VALUE);

        // represents the last seen position of 'c' (left to right)
        int prev = Integer.MAX_VALUE;

        // traverse from left to right
        for(int i=0; i<len; i++){
            if(s.charAt(i) == c){
                // update the position of 'c'
                prev = i;
            }
            // calculate distance from the nearest 'c' so far
            res[i] = Math.abs(i - prev);
        }

        // reset prev for the second pass
        prev = Integer.MAX_VALUE;

        // traverse from right to left
        for(int i=len-1; i>=0; i--){
            if(s.charAt(i) == c){
                prev = i;
            }
            // take smaller absolute distance
            res[i] = Math.min(Math.abs(i - prev), res[i]);
        }
        // return the result array
        return res;
    }

    public static void main(String[] args) {
        // String str = "loveleetcode";
        // char ch = 'e';

        String str = "aaab";
        char ch = 'b';
        int[] res = shortestToChar(str, ch);
        System.out.println(Arrays.toString(res));
    }
}