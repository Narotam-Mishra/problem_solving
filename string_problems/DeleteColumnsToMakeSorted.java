
// Problem link - https://leetcode.com/problems/delete-columns-to-make-sorted/description/?envType=daily-question&envId=2025-12-20

package string_problems;

public class DeleteColumnsToMakeSorted {
    public static int minDeletionSize(String[] strs) {
        // get size of string array and each string
        int n = strs.length;
        int k = strs[0].length();

        // step 1 - iterate on each letter of string array
        int count = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 1; j < n; j++){
                // step 2 - check if current letter is less than previous letter
                if(strs[j].charAt(i) < strs[j-1].charAt(i)){
                    count++;
                    break;
                }
            }
        }

        // step 3 - return number of columns that you will delete
        return count;
    }

    public static void main(String[] args) {
        String[] strs = {"cba", "daf", "ghi"};
        System.out.println(minDeletionSize(strs));
    }
}
