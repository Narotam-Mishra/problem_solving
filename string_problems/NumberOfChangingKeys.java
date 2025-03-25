
// Problem link - https://leetcode.com/problems/number-of-changing-keys/description/?envType=problem-list-v2&envId=string

package string_problems;

public class NumberOfChangingKeys {
    public static int countKeyChanges(String s) {
        // step 1 - initialize count
        int count = 0;

        // step 2 - change input string `s` to lowercase
        s = s.toLowerCase();

        // step 3 - iterate on each character of `s`
        for(int i=1; i<s.length(); i++){
            // get current character of string
            char ch = s.charAt(i);

            // step 4 - check if current current is not equals to previous then increment counter
            if(ch != s.charAt(i-1)){
                count++;
            }
        }

        // step 5 - return count
        return count;
    }

    public static void main(String[] args) {
        // String s = "aAbBcC";

        String s = "AaAaAaaA";
        System.out.println(countKeyChanges(s));
    }
}