
// Problem link : https://leetcode.com/problems/reverse-only-letters/?envType=problem-list-v2&envId=string&difficulty=EASY&status=TO_DO%2CATTEMPTED

package string_problems;

public class ReverseOnlyLetters {
    public static String reverseOnlyLetters(String s) {
        // convert string to char array for easy iteration
        char[] chArr = s.toCharArray();

        // initialize pointers
        int l = 0, r = chArr.length - 1;

        // process the characters until the two pointers meet
        while (l < r) {
            // move left pointer to the next letter
            while (l < r && !Character.isLetter(chArr[l])) {
                l++;
            }

            // move right pointer to the next letter
            while (l < r && !Character.isLetter(chArr[r])) {
                r--;
            }

            // swap letters at left and right pointers
            if(l < r){
                char temp = chArr[l];
                chArr[l] = chArr[r];
                chArr[r] = temp;
                l++;
                r--;
            }
        }
        // convert char array back to string
        return new String(chArr);
    }

    public static void main(String[] args) {
        // String str = "ab-cd";

        // String str = "a-bC-dEf-ghIj";

        String str = "Test1ng-Leet=code-Q!";
        System.out.println(reverseOnlyLetters(str));
    }
}