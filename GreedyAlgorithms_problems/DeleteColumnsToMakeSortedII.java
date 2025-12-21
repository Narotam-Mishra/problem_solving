
// Problem link - https://leetcode.com/problems/delete-columns-to-make-sorted-ii/description/?envType=daily-question&envId=2025-12-21

package GreedyAlgorithms_problems;

public class DeleteColumnsToMakeSortedII {
    public static int minDeletionSize(String[] strs) {
        // find row and column size
        int r = strs.length;
        int c = strs[0].length();

        // keep track of already sorted column
        // this is to avoid unnecessary deletion
        boolean[] alreadySorted = new boolean[r];

        // step 1 - process columns left to right
        int deletionCount = 0;
        for(int col=0; col<c; col++){
            boolean deleted = false;

            // step 2 - check if current column violates order
            for(int row=0; row<r-1; row++){
                if(!alreadySorted[row] && strs[row].charAt(col) > strs[row+1].charAt(col)){
                    // must delete this column
                    deletionCount++;
                    deleted = true;
                    break;
                }
            }

            // skip marking sorted pair if column was already deleted
            if(deleted) continue;

            // step 3 - update which pairs are now confirmed sorted
            for(int i=0; i<r-1; i++){
                alreadySorted[i] = alreadySorted[i] | (strs[i].charAt(col) < strs[i+1].charAt(col));
            }
        }

        // step 4 - return minimum deletion count
        return deletionCount;
    }

    public static void main(String[] args) {
        // String[] strs = {"ca","bb","ac"};

        // String[] strs = {"xc","yb","za"};

        String[] strs = {"zyx","wvu","tsr"};
        System.out.println(minDeletionSize(strs));
    }
}
