
// find missing numbers in an array range of maximum and minimum number

package Array_problems;

import java.util.*;

public class FindMissingNumbers {
    private static int findMinimum(int[] arr){
        int minNum = Integer.MAX_VALUE;
        for(int i=0; i<arr.length; i++){
            minNum = Math.min(minNum, arr[i]);
        }
        return minNum;
    }

    private static int findMaximum(int[] arr){
        int maxNum = Integer.MIN_VALUE;
        for(int i=0; i<arr.length; i++){
            maxNum = Math.max(maxNum, arr[i]);
        }
        return maxNum;
    }

    public static List<Integer> findMissingNumbers(int[] arr){
        // find maximum and minimum number in the list
        int minNum = findMinimum(arr);
        int maxNum = findMaximum(arr);

        // create set to mark presence of numbers
        Set<Integer> presentNums = new HashSet<Integer>();

        // mark numbers from the input array as present
        for(int num : arr){
            presentNums.add(num);
        }

        // list of missNums to store missing numbers
        List<Integer> missNums = new ArrayList<Integer>();
        for(int n=minNum; n<=maxNum; n++){
            if(!presentNums.contains(n)){
                missNums.add(n);
            }
        }
        return missNums;
    }

    public static void main(String[] args) {
        int [] arr = {2,5,7};
        List<Integer> ans = findMissingNumbers(arr);
        // for(int num : ans){
        //     System.out.print(num+" ");
        // }
        System.out.println(ans);
    }
}