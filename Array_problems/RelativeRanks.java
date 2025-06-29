
// Problem link - https://leetcode.com/problems/relative-ranks/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class RelativeRanks {
    public static String[] findRelativeRanks(int[] score) {
        int n = score.length;

        // step 1 - create score to original index mapping
        int[][] scoreWithIndex = new int[n][2];
        for(int i=0; i<n; i++){
            scoreWithIndex[i][0] = score[i];
            scoreWithIndex[i][1] = i;
        }

        // step 2 - sort in descending order of score
        Arrays.sort(scoreWithIndex, (a,b) -> Integer.compare(b[0], a[0]));

        // step 3 - create mapping from score to rank
        Map<Integer, String> scoreToRank = new HashMap<>();

        // step 4 - iterate on each score to assign its rank
        for(int i=0; i<scoreWithIndex.length; i++){
            // step 5 - extract score from scoreWithIndex pairs
            int currentScore = scoreWithIndex[i][0];
            // rank is based on 1-based indexing
            int rank = i + 1;

            // step 6 - convert rank to appropriate string value
            String rankString = "";
            if(rank == 1){
                rankString = "Gold Medal";
            }else if(rank == 2){
                rankString = "Silver Medal";
            }else if(rank == 3){
                rankString = "Bronze Medal";
            }else{
                rankString = String.valueOf(rank);
            }

            scoreToRank.put(currentScore, rankString);
        }

        // step 7 - build result array using original order
        String[] res = new String[n];
        for(int i=0; i<n; i++){
            res[i] = scoreToRank.get(score[i]);
        }

        // step 8 - return resultant array res
        return res;
    }

    public static void main(String[] args) {
        // int[] score = {5,4,3,2,1};

        int[] score = {10,3,8,9,4};
        String[] res = findRelativeRanks(score);
        System.out.println(Arrays.toString(res));
    }
}