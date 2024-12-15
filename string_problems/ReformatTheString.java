
// Problem link : https://leetcode.com/problems/reformat-the-string/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

public class ReformatTheString {
    public static String reformat(String s) {
        // step 1 - separate letters and digits into two lists
        StringBuilder letters = new StringBuilder();
        StringBuilder digits = new StringBuilder();

        for(char ch : s.toCharArray()){
            if(Character.isDigit(ch)){
                letters.append(ch);
            }else if(Character.isLetter(ch)){
                digits.append(ch);
            }
        }

        // step 2 - Check if it's impossible to reformat
        if(Math.abs(letters.length() - digits.length()) > 1){
            // return an empty string
            return "";
        }

        // step 3 - decide which group should start
        StringBuilder largerGrp = letters.length() >= digits.length() ? letters : digits;
        StringBuilder smallerGrp = letters.length() < digits.length() ? letters : digits;

        // step 4 - merge alternately
        StringBuilder res = new StringBuilder();
        int i = 0, j = 0;
        while(i < largerGrp.length() || j < smallerGrp.length()){
            if(i < largerGrp.length()) res.append(largerGrp.charAt(i++));
            if(j < smallerGrp.length()) res.append(smallerGrp.charAt(j++));
        }

        return res.toString();
    }

    public static void main(String[] args) {
        // String str = "a0b1c2";

        // String str = "leetcode";

        String str = "1229857369";
        System.out.println(reformat(str));
    }
}