
// Problem link - https://leetcode.com/problems/reverse-prefix-of-word/?envType=problem-list-v2&envId=string

package string_problems;

public class ReversePrefixOfWord {
    public static String reversePrefix(String word, char ch) {
        // step 1 - find the first occurrence of ch
        int chIndex = word.indexOf(ch);

        // step 2 - if ch doesn't exist in word, return original word
        if(ch == -1) return word;

        // step 3 - convert word to char array 
        char[] charArr = word.toCharArray();

        // step 4 - reverse segment in place
        int left = 0, right = chIndex;
        while(left < right){
            char temp = charArr[left];
            charArr[left] = charArr[right];
            charArr[right] = temp;

            left++;
            right--;
        }

        // step 5 - convert back to string and return 
        return new String(charArr);
    }

    public static void main(String[] args) {
        // String word = "abcdefd";
        // char ch = 'd';

        // String word = "xyxzxe";
        // char ch = 'z';

        String word = "abcd";
        char ch = 'z';
        System.out.println(reversePrefix(word, ch));
    }
}