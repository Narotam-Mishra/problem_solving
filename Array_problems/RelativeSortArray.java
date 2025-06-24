
// Problem link - https://leetcode.com/problems/relative-sort-array/description/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class RelativeSortArray {
    public static int[] relativeSortArray1(int[] arr1, int[] arr2) {
        // step 1 - create a rank map for element in arr2
        Map<Integer, Integer> rankMap = new HashMap<>();
        for(int i=0; i<arr2.length; i++){
            rankMap.put(arr2[i], i);
        }

        // step 2 - sort `arr1` with a custom sort comparator
        Integer[] arr1Boxed = Arrays.stream(arr1).boxed().toArray(Integer[]::new);
        Arrays.sort(arr1Boxed, (a, b) -> {
            // step 3 - if both a and b are in arr2, sort based on their rank
            if (rankMap.containsKey(a) && rankMap.containsKey(b)) {
                return rankMap.get(a) - rankMap.get(b);
            }
            // step 4 - if only `a` is in arr2, it comes before `b` 
            else if (rankMap.containsKey(a)) {
                return -1; // a is in arr2 but b isn't → a comes first
            }
            // step 5 - if only b is in arr2, it comes before a 
            else if (rankMap.containsKey(b)) {
                return 1;  // b is in arr2 but a isn't → b comes first
            }
            // step 6 - if neither are in arr2, sort in ascending order 
            else {
                return a - b; // both not in arr2 → sort ascending
            }
        });
        // unbox back to int[]
        for (int i = 0; i < arr1.length; i++) {
            arr1[i] = arr1Boxed[i];
        }

        // step 7 - return relative sorted `arr1`
        return arr1;
    }

    public static int[] relativeSortArray(int[] arr1, int[] arr2) {
        // step 1 - create frequency array to count occurrences of each number
        int[] frq = new int[1001];
        for(int num : arr1){
            frq[num]++;
        }

        // store result in `res`
        int[] res = new int[arr1.length];

        // step 2 -  first, place all elements that appear in arr2 in the order specified by arr2
        int idx = 0;
        for(int num : arr2){
            while(frq[num]-- > 0){
                res[idx++] = num;
            }
        }

        // step 3 - Place remaining elements (not in arr2) in ascending order
        for(int i=0; i<1001; i++){
            while(frq[i]-- > 0){
                res[idx++] = i;
            }
        }
        
        // step 4 - return the relatively sorted array
        return res;
    }

    public static void main(String[] args) {
        int[] arr1 = {2,3,1,3,2,4,6,7,9,2,19};
        int[] arr2 = {2,1,4,3,9,6};

        // int[] arr1 = {28,6,22,8,44,17};
        // int[] arr2 = {22,28,8,6};
        int[] res = relativeSortArray(arr1, arr2);
        System.out.println(Arrays.toString(res));
    }
}