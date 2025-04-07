
// Problem link - https://leetcode.com/problems/faulty-keyboard/?envType=problem-list-v2&envId=string

package string_problems;

public class FaultyKeyBoard {
    public static String finalString(String s) {
        // step - 1 - store final string to screen
        StringBuilder res = new StringBuilder();

        // step - 2 - loop through each character typed  on character
        for(char ch : s.toCharArray()){
            if(ch == 'i'){
                // step 3 - faulty behaviour : reverse the screen
                res.reverse();
            }else{
                // step 4 - normal behaviour : add character to screen
                res.append(ch);
            }
        }

        // step 5 - convert the character array to a string
        return res.toString();
    }

    public static void main(String[] args) {
        // String s = "string";

        String s = "poiinter";
        System.out.println(finalString(s));
    }
}