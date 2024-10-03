
// Problem link - https://leetcode.com/problems/maximum-product-of-word-lengths/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class MaximumProductOfWordLength {
    public static int maxProduct(String[] words) {
        int n = words.length;
        int maxProd = 0;
        int[] mask = new int[n];

        // step1: convert each word to a bit mask
        for(int i=0; i<n; i++){
            String word = words[i];
            // create bit mask for current word
            for(char ch : word.toCharArray()){
                // set corresponding bit for each character
                // 'a' is 97 in ASCII, so char.charCodeAt(0) - 97 gives 0-25
                mask[i] |= 1 << (ch - 'a');
            }
        }

        // step2: compare each pair of words using their bit masks
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                // if AND of masks is 0, words have no common letters
                if((mask[i] & mask[j]) == 0){
                    // calculate maximum product
                    int prod = words[i].length() * words[j].length();
                    maxProd = Math.max(maxProd, prod);
                }
            }
        }
        // return maximum product 'maxprod'
        return maxProd;
    }
    public static void main(String[] args) {
        // String[] words = {"abcw","baz","foo","bar","xtfn","abcdef"};

        // String[] words = {"a","ab","abc","d","cd","bcd","abcd"};

        String[] words = {"a","aa","aaa","aaaa"};
        System.out.println(maxProduct(words));
    } 
}