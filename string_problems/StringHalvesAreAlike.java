
// Problem link : https://leetcode.com/problems/determine-if-string-halves-are-alike/description/?envType=problem-list-v2&envId=string

package string_problems;

public class StringHalvesAreAlike {

    private static boolean isVowel(char ch) {
        return "aeiou".indexOf(ch) != -1;
    }

    public static boolean halvesAreAlike1(String s) {
        // initialize counters to count the number of vowels in the first and second halves
        int fvc = 0, svc = 0;
        int n = s.length();

        // iterate over the first and second halves of the input string `s`
        for (int i = 0, j = n / 2; i < n / 2 && j < n; i++, j++) {
            // check for vowels and increment the respective counter
            if (isVowel(Character.toLowerCase(s.charAt(i))))
                fvc++;
            if (isVowel(Character.toLowerCase(s.charAt(j))))
                svc++;
        }

        // check if the count of vowels in the first and second halves are equal
        return fvc == svc;
    }

    public static boolean halvesAreAlike(String s) {
        // intialize counter to count number of vowels 
        // in first and second half of a input string `s`
        int fvc = 0, svc = 0;
        int n = s.length();

        // iterate over the input string `s`
        for(int i=0; i<n; i++){
            if(i < n/2){
                if(Character.toLowerCase(s.charAt(i)) == 'a' || Character.toLowerCase(s.charAt(i)) == 'e' || Character.toLowerCase(s.charAt(i)) == 'i' || Character.toLowerCase(s.charAt(i)) == 'o' || Character.toLowerCase(s.charAt(i)) == 'u')
                    fvc++;
            }else{
                if(Character.toLowerCase(s.charAt(i)) == 'a' || Character.toLowerCase(s.charAt(i)) == 'e' || Character.toLowerCase(s.charAt(i)) == 'i' || Character.toLowerCase(s.charAt(i)) == 'o' || Character.toLowerCase(s.charAt(i)) == 'u')
                    svc++;
            }
        }

        // check if count of vowels in first and second half are equal or not
        return fvc == svc;
    }

    public static void main(String[] args) {
        // String s = "book";

        String s = "textbook";
        System.out.println(halvesAreAlike(s));
    }
}