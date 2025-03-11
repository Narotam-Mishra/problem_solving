
// Problem link - https://leetcode.com/problems/count-items-matching-a-rule/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.*;

public class CountItemsMatchingRule {
    public static int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        // step 1 - map ruleKey to corresponding index
        int index;
        if(ruleKey.equals("type")){
            index = 0;
        }else if(ruleKey.equals("color")){
            index = 1;
        }else{
            index = 2;
        }

        // step 2 - initialize a counter to count the matching items
        int count = 0;

        // step 3 - traverse list items 
        for(List<String> item : items){
            // step 4 - check if the value at the corresponding index matches the ruleValue
            if(item.get(index).equals(ruleValue)){
                count++;
            }
        }

        // step 5 - return count of matching items
        return count;
    }

    public static void main(String[] args) {
        List<List<String>> items = List.of(
                List.of("phone", "blue", "pixel"),
                List.of("computer", "silver", "lenovo"),
                List.of("phone", "gold", "iphone"));

        String ruleKey = "type";
        String ruleValue = "phone";
        System.out.println(countMatches(items, ruleKey, ruleValue));
    }
}