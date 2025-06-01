
// Problem link - https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/?envType=problem-list-v2&envId=string

package string_problems;

public class LexicographicallySmallestStringAfterSwap {
    // utility function check if two digits have same parity
    private static boolean haveSameParity(char a, char b){
        int num1 = Character.getNumericValue(a);
        int num2 = Character.getNumericValue(b);
        return (num1 % 2) == (num2 % 2);
    }

    public static String getSmallestString(String s) {
        // step 1 - convert string `s` to character array for easy iteration
        char[] digits = s.toCharArray();
        int n = digits.length;

        // step 2 - scan each digit from left to right
        for(int i=0; i<n-1; i++){
            char currChar = s.charAt(i);
            char nextChar = s.charAt(i+1);

            // step 3 - check if adjacent digits have same parity AND swapping would make string smaller
            if(haveSameParity(currChar, nextChar) && currChar > nextChar){
                // perform swapping as above conditions satisfied
                char temp = digits[i];
                digits[i] = digits[i+1];
                digits[i+1] = temp;

                // step 4 - return immediately after first swap (at most one swap allowed)
                return new String(digits);
            }
        }

        // step 5 - otherwise return original string `s`
        return s;
    }

    public static void main(String[] args) {
        // String s = "45320";

        String s = "001";
        System.out.println(getSmallestString(s));
    }
}