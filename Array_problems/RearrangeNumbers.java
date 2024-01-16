package Array_problems;

// Problem link - https://leetcode.com/problems/rearrange-array-elements-by-sign/

/**
 * RearrangeNumbers
 */

public class RearrangeNumbers {
    public static int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int arr[] = new int[n];
        int[] pNums = new int[n/2];
        int[] nNums = new int[n/2];

        int i; int j;
        i = j = 0;

        // fill positive numbers into pNums array
        // & negative into nNums array
        for(int num : nums){
            if(num>0){
                pNums[i++] = num;
            }else{
                nNums[j++] = num;
            }
        }

        // now arrange the number as per problem
        int k = 0;
        for(int id=0; id<n; id+=2){
            arr[id] = pNums[k];
            arr[id + 1] = nNums[k];
            k++;
        }
        return arr; 
    }
}