
// Problem link - https://leetcode.com/problems/count-asterisks/?envType=problem-list-v2&envId=string

package string_problems;

public class CountAsterisks {
    public static int countAsterisks(String s) {
        // step 1 - initialize counter to count `*`
        int count = 0;

        // step 2 - track whether we are inside `|` pair or not
        boolean insidePair = false;

        // step 3 - iterate on each character of input `s`
        for (char ch : s.toCharArray()) {
            if (ch == '|') {
                // step 4 - toggle the insidePair flag whenever we see `|`
                insidePair = !insidePair;
            } else if (ch == '*' && !insidePair) {
                // step 5 - only count `*` if we are outside of `|` pair
                count++;
            }
        }

        // step 6 - return count
        return count;
    }

    public static void main(String[] args) {
        // String s = "l|*e*et|c**o|*de|";

        // String s = "iamprogrammer";

        String s = "yo|uar|e**|b|e***au|tifu|l";
        System.out.println(countAsterisks(s));
    }
}