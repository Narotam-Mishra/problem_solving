
// Problem link - https://leetcode.com/problems/truncate-sentence/?envType=problem-list-v2&envId=string

package string_problems;

public class TruncateSentence {
    public static String truncateSentence(String s, int k) {
        // step 1 - split the sentence into word
        String[] words = s.split(" ");

        // step 2 - join first k words with a space
        StringBuilder trauncated = new StringBuilder();
        for(int i=0; i<k; i++){
            if(i > 0){
                trauncated.append(" ");
            }
            trauncated.append(words[i]);
        }

        // step 3 - return `trauncated` word in string
        return trauncated.toString();
    }

    public static void main(String[] args) {
        // String s = "Hello how are you Contestant";
        // int k = 4;

        // String s = "What is the solution to this problem";
        // int k = 4;

        String s = "chopper is not a tanuki";
        int k = 5;
        System.out.println(truncateSentence(s, k));
    }
}