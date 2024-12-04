
// Problem link : https://leetcode.com/problems/long-pressed-name/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

public class LongPressedName {
    public static boolean isLongPressedName(String name, String typed) {
        // using two-pointers approach
        // pointer 'i' for name
        int i = 0;

        // pointer 'j' for typed
        int j = 0;

        // traverse through typed characters
        while (j < typed.length()) {
            // case 1 : character match case in both name and typed strings
            if(i < name.length() && name.charAt(i) == typed.charAt(j)){
                i++;
                j++;
            // case 2 : long-pressed scneario
            }else if(j > 0 && typed.charAt(j) == typed.charAt(j-1)){
                j++;
            // case 3 : invalid scenario, character in typed doesn't match
            }else{
                // name's current character or isn't a long press
                return false;
            }
        }

        // after processing typed, ensure all characters in name matched
        return i == name.length();
    }

    public static void main(String[] args) {
        // String name = "alex", typed = "aaleex";

        String name = "saeed", typed = "ssaaedd";
        System.out.println(isLongPressedName(name, typed));
    }
}