
// Problem link : https://leetcode.com/problems/shuffle-string/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

public class ShuffleString {
    public static String restoreString(String s, int[] indices) {
        // step 1: Create an empty array of the same length as the string
        char[] shuffled = new char[s.length()];

        // step 2: iterate through each character of the string and place it at the correct index.
        for(int i=0; i<s.length(); i++){
            shuffled[indices[i]] = s.charAt(i);
        }

        // step 3: Convert the array back to a string and return it.
        return new String(shuffled);
    }

    public static void main(String[] args) {
        String str = "codeleet";
        int[] indices = {4,5,6,7,0,2,1,3};
        System.out.println(restoreString(str, indices));
    }
}