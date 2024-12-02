
// Problem link : https://leetcode.com/problems/jewels-and-stones/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package Hashing_and_HashMap_problems;

import java.util.HashSet;

public class JewelsAndStones {
    public static int numJewelsInStones1(String jewels, String stones) {
        // convert jewels string to a Set for efficient lookup.
        HashSet<Character> jewelSet = new HashSet<>();
        for(char ch : jewels.toCharArray()){
            jewelSet.add(ch);
        }

        // initialize a counter to track the number of jewels in stones.
        int count = 0;

        // loop through each character in stones.
        for(char stone : stones.toCharArray()){
            // check if the current stone is in the jewelSet.
            if(jewelSet.contains(stone)){
                // increment the count if it is a jewel
                count++;
            }
        }

        // return the total count of jewels in stones.
        return count;
    }

    public static int numJewelsInStones(String jewels, String stones) {
        // initialize a counter to track the number of jewels in stones.
        int count = 0;

        // loop through each character in stones.
        for(char stone : stones.toCharArray()){
            // check if the current stone is in the jewel.
            if(jewels.indexOf(stone) != -1){
                // increment the count if it is a jewel
                count++;
            }
        }

        // return the total count of jewels in stones.
        return count;
    }

    public static void main(String[] args) {
        String jewels = "aA", stones = "aAAbbbb";

        // String jewels = "z", stones = "ZZ";
        System.out.println(numJewelsInStones(jewels, stones));
    }
}