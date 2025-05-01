
// Problem link - https://leetcode.com/problems/check-distances-between-same-letters/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.Arrays;

public class CheckDistancesBetweenSameLetters {
    public static boolean checkDistances(String s, int[] distance) {
        // step 1 - array to store the index of first occurrence of each character
        int[] firstIndexArr = new int[26];
        // fill array elements with -1
        Arrays.fill(firstIndexArr, -1);

        // step 2 - iterate on each character of `s`
        for(int i=0; i<s.length(); i++){
            // convert each character to corresponding number
            // 'a' --> 0, 'b' --> 1, .... 'z' --> 25
            int charCode = s.charAt(i) - 'a';

            // step 3 - if first time seeing this character then store its index
            if(firstIndexArr[charCode] == -1){
                firstIndexArr[charCode] = i;
            }else{
                // step 4 - if second time seeing this, calculate the distance
                int actualDistance = i - firstIndexArr[charCode] - 1;

                // step 5 - check actual distance with distance array
                if(actualDistance != distance[charCode]){
                    return false;
                }
            }
        }

        // step 6 - all character matched the required distance, return true
        return true;
    }

    public static void main(String[] args) {
        // String s = "abaccb";
        // int[] distance = {1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

        String s = "aa";
        int[] distance = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        System.out.println(checkDistances(s, distance));
    }
}