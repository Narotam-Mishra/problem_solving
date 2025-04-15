
// Problem link - https://leetcode.com/problems/capitalize-the-title/?envType=problem-list-v2&envId=string

package string_problems;

public class CapitalizeTheTitle {
    public static String capitalizeTitle(String title) {
        // step 1 - split title by space
        String[] words = title.split(" ");

        // store result in `res`
        StringBuilder res = new StringBuilder();

        // step 2 - iterate on each word of title
        // capitalize it as per given conditions
        for(String word : words){
            if(word.length() <= 2){
                // lowercase all characters if word is of length 1 or 2
                res.append(word.toLowerCase());
            }else{
                // otherwise capitalize the character of each word
                res.append(Character.toUpperCase(word.charAt(0)));
                // and keep all other characters in lowercase
                res.append(word.substring(1).toLowerCase());
            }
            // add space
            res.append(" ");
        }

        // step 3 - remove the trailing space at the end and return res
        return res.toString().trim();
    }

    public static void main(String[] args) {
        // String title = "capiTalIze tHe titLe";

        // String title = "First leTTeR of EACH Word";

        String title = "i lOve leetcode";
        System.out.println(capitalizeTitle(title));
    }
}