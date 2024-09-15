
// Problem link : https://leetcode.com/problems/binary-prefix-divisible-by-5/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

import java.util.*;

public class BinaryPrefixDevisibleBy5 {
    public static List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> res = new ArrayList<>();
        int num = 0;

        for(int i=0; i<nums.length; i++){
            // incrementally build the binary number modulo 5
            num = (num * 2 + nums[i]) % 5;

            // check if divisible by 5
            if(num == 0){
                res.add(true);
            }else{
                res.add(false);
            } 
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {0, 1, 1};
        System.out.println(prefixesDivBy5(nums));
    }
}