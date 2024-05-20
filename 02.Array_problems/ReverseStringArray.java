
// Problem link - https://leetcode.com/problems/reverse-string/description/


package Array_problems;

/**
 * ReverseStringArray
 */
public class ReverseStringArray {

    public static void swap(char[] s, int i, int j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    public void reverseString(char[] s) {
        int st = 0;
        int e = s.length - 1;

        while(st<e){
            swap(s, st, e);
            st++;
            e--;
        }
    }
    
}