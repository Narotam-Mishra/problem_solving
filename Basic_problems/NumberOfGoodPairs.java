
// /Problem link - https://leetcode.com/problems/number-of-good-pairs/

package Basic_problems;

import java.util.HashMap;

public class NumberOfGoodPairs {
    public static int numIdenticalPairs(int[] nums) {
        int count = 0;
        HashMap<Integer, Integer> hm = new HashMap<>();

        for(int num : nums){
            if(hm.containsKey(num)){
                count += hm.get(num);
                hm.put(num, hm.get(num) + 1);
            }else{
                hm.put(num, 1);
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[] nums = {1,1,1,1};
        System.out.println(numIdenticalPairs(nums));
    }
}