
// Problem link : https://leetcode.com/problems/number-of-segments-in-a-string/description/?envType=problem-list-v2&envId=string&favoriteSlug=&status=TO_DO&difficulty=EASY

package string_problems;

public class NumberOfSegmentsInString {
    public static int countSegments(String s) {
        // step 1: trim leading and trailing spaces
        s = s.trim();

        // step 2: check if the string is empty after trimming
        if(s.isEmpty()){
            return 0;
        }

        // step 3: split the string by spaces and count non-empty segments
        String[] strSegments = s.split(" ");
        int count = 0;
        for(String str : strSegments){
            if(!str.isEmpty()) count++;
        }

        // return valid string segment count 
        return count;
    }

    public static void main(String[] args) {
        // String str = "Hello, my name is John";

        String str = "Hello";
        System.out.println(countSegments(str));
    }
}