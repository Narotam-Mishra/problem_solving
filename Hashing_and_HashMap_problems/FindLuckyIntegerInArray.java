
// Problem link : https://leetcode.com/problems/find-lucky-integer-in-an-array/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

public class FindLuckyIntegerInArray {
    // utlity method to check if number is lucky or not
    private static boolean isLuckyNumber(int num, int count){
        return num == count;
    }

    public static int findLucky(int[] arr) {
        // step 1 - create frequency map array to store frquency of each number from array
        int[] freqArr = new int[501];
        for(int num : arr){
            freqArr[num]++;
        }

        // step 2 - iterate frquency array return largest Lucky number
        for(int i=freqArr.length - 1; i>0; i--){
            if(isLuckyNumber(i, freqArr[i])){
                return freqArr[i];
            }
        }

        // step 3 - otherwise return -1
        return -1;
    }

    public static void main(String[] args) {
        // int[] arr = {2,2,3,4};

        // int[] arr = {1,2,2,3,3,3};

        int[] arr = {2,2,2,3,3};
        System.out.println(findLucky(arr));
    }
}