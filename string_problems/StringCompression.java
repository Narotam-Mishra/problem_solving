
// Goldman Sach Interview Problem

package string_problems;

public class StringCompression {
    public static String compressString(String input){
        // base case
        if(input == null || input.isEmpty()){
            return "";
        }

        // initialize compressed string in `res`
        StringBuilder res = new StringBuilder();
        char currChar = input.charAt(0);
        
        // input string contains atleast one character
        int count = 1;

        // iterate over input string
        for(int i=1; i<input.length(); i++){
            // check if previous character is equal to current character
            if(input.charAt(i) == currChar){
                // then increment count
                count++;
            }else{
                // otherwise store character and its count in `res`
                res.append(currChar).append(count);

                // move to next character
                currChar = input.charAt(i);

                // reset the count
                count = 1;
            }
        }

        // store last character in `res`
        res.append(currChar).append(count);

        // retuern the result from `res`
        return res.toString();
    }

    public static void main(String[] args) {
        // String str = "aabbbcccaa";

        // String str = "aa";

        // String str = "a";

        String str = "abc";
        System.out.println(compressString(str));
    }
}