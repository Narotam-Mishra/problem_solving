
// Problem link - https://leetcode.com/problems/minimum-number-of-people-to-teach/?envType=daily-question&envId=2025-09-10

package GreedyAlgorithms_problems;

import java.util.*;

public class MinimumNumberOfPeopleToTeach {
    public static int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        // `sadUsers` are users who can't communicate with at least one friend
        Set<Integer> sadUsers = new HashSet<>();

        // step - 1 : identify all problematic friendships and collect sad users
        for(int[] friends : friendships){
            // convert this to 0-based indexing
            int u = friends[0] - 1;
            int v = friends[1] - 1;

            // step 2 - create a set of languages known by user `u`
            Set<Integer> langSetU = new HashSet<>();
            for(int lang : languages[u]){
                langSetU.add(lang);
            }

            // step 3 - check if users u and v can communicate (share any common language)
            boolean canTalk = false;
            for(int lang : languages[v]){
                if(langSetU.contains(lang)){
                    // found common language
                    canTalk = true;
                    break;
                }
            }

            // step 4 - if they can't talk then they are sad users
            if(!canTalk){
                sadUsers.add(u);
                sadUsers.add(v);
            }
        }

        // step 5 - find the language that is already known by most sad users
        // array to count how many sad users know each language
        int[] languageCount = new int[n+1];
        int mostKnownLang = 0;

        // step 6 - count language knowledge among sad users only
        for(int user : sadUsers){
            for(int lang : languages[user]){
                languageCount[lang]++;
                mostKnownLang = Math.max(mostKnownLang, languageCount[lang]);
            }
        }

        // step 7 - calculate minimum teachings needed and return
        // if we teach the most popular language among sad users,
        // we need to teach (total sad users - users who already know that language)
        return sadUsers.size() - mostKnownLang;
    }

    public static void main(String[] args) {
        // int n = 2;
        // int[][] languages = {{1},{2},{1,2}};
        // int[][] friendships = {{1,2},{1,3},{2,3}};

        int n = 3;
        int[][] languages = {{2},{1,3},{1,2},{3}};
        int[][] friendships = {{1,4},{1,2},{3,4},{2,3}};
        System.out.println(minimumTeachings(n, languages, friendships));
    }
}