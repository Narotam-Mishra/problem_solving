package string_problems;

public class CheckIfAllAAppearsBeforeAllB {
    public static boolean checkString(String s) {
        // step 1 - set flag to tack if we have seen `b`
        boolean seenB = false;

        // step 2 - iterate on each character of `s`
        for (char ch : s.toCharArray()) {
            // step 3 - mark true for every `b` that we have seen
            if (ch == 'b') {
                seenB = true;
            } else if (ch == 'a') {
                // step 4 - if we see an `a` after `b` then return false immediately
                if (seenB) {
                    return false;
                }
            }
        }

        // step 5 - return true as all characters follow the rule: 'a's before 'b's
        return true;
    }

    public static void main(String[] args) {
        // String s = "aaabbb";

        // String s = "abab";

        String s = "bbb";
        System.out.println(checkString(s));
    }
}
