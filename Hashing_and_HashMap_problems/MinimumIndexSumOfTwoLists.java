
// Probllem link : https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class MinimumIndexSumOfTwoLists {
    public static String[] findRestaurant(String[] list1, String[] list2) {
        // step 1 - create map to store index of each word in list1
        Map<String, Integer> map = new HashMap<>();
        for(int i=0; i<list1.length; i++){
            map.put(list1[i], i);
        }

        // store minimum index sum
        int minIndexSum = Integer.MAX_VALUE;

        // store words with the least index sum
        List<String> res = new ArrayList<>();

        // step 2 - iterate through list2 and find common words
        for(int j=0; j<list2.length; j++){
            // check if the list2 word exists in list1
            if(map.containsKey(list2[j])){
                // get index from list1
                int i = map.get(list2[j]);
                
                // calculate index sum
                int indexSum = i + j;

                // step 3 - update minimum index sum and store corresponding word
                if(indexSum < minIndexSum){
                    minIndexSum = indexSum;
                    // reset result with the new least sum word
                    res.clear();
                    res.add(list2[j]);
                }else if(indexSum == minIndexSum){
                    res.add(list2[j]);
                }
            }
        }

        // step 4 - return all common words with the least index sum
        return res.toArray(new String[0]);
    }

    public static void main(String[] args) {
        String[] list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
        String[] list2 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};

        // String[] list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
        // String[] list2 = {"KFC","Shogun","Burger King"};

        // String[] list1 = {"happy","sad","good"};
        // String[] list2 = {"sad","happy","good"};
        System.out.println(Arrays.toString(findRestaurant(list1, list2)));
    }
}