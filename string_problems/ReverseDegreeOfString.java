package string_problems;

public class ReverseDegreeOfString {
    public static int reverseDegree(String s) {
        // step 1 - initialize variable to store reverse degree `rd`
        int rd = 0;

        // step 2 - iterate on each character of `s`
        for(int i=0; i<s.length(); i++){
            // step 3 - calculate the reverse position in the alphabet
            int revPos = 26 - (s.charAt(i) - 'a');

            // step 4 - multiply with the 1-indexed position in the string
            rd += revPos * (i + 1);
        }

        // step 5 - return reverse degree `rd`
        return rd;
    }

    public static void main(String[] args) {
        // String s = "abc";

        String s = "zaza";
        System.out.println(reverseDegree(s));
    }
}