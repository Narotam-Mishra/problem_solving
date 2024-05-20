
// Very Very Important Question

package Array_problems;

import java.util.ArrayList;
import java.util.List;

/**
 * CountSmallerNumberAfterSelf
 */
public class CountSmallerNumberAfterSelf {

    static class Pair{
        int num; //for number
        int index; //for index

        Pair(int num, int index){
            this.num = num;
            this.index = index;
        }
    }

    // Merge function to merge two sorted lists and count smaller elements from the right side.
    public static List<Pair> mergeTask(List<Pair> left, List<Pair> right, int[] res){
        int i = 0, j = 0;
        List<Pair> sortedArr = new ArrayList<>();

        // compare element from both left and right array and merge
        while (i < left.size() || j < right.size()) {
            if(j == right.size() || (i < left.size() && left.get(i).num <= right.get(j).num)){
                sortedArr.add(left.get(i));

                // Count smaller elements from the right side by adding the current count (j) to result
                res[left.get(i).index] += j;
                i++;
            }else{
                sortedArr.add(right.get(j));
                j++;
            }
        }
        return sortedArr;
    }

    // Recursive merge sort function to sort the list of pairs and count smaller elements.
    public static List<Pair> mergeSort(List<Pair> arr, int[] res){
        // Base case: array of 1 element is always sorted, hence return
        if(arr.size() == 1) return arr;

        // calculate mid and recurively sort left and right half of array
        int mid = arr.size()/2;

        // recurively sort left and right half of array
        List<Pair> leftList = mergeSort(arr.subList(0, mid), res);
        List<Pair> rightList = mergeSort(arr.subList(mid, arr.size()), res);

        // merge both arrays and return
        return mergeTask(leftList, rightList, res);
    }

    public static List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        // Initialize result array with 0s
        int[] res = new int[n];

        // create a list of pairs where each pair contains the number and its original index
        List<Pair> indexedNums = new ArrayList<>();

        for(int i=0; i<n; i++){
            indexedNums.add(new Pair(nums[i], i));
        }

        // Perform merge sort and count smaller elements
        mergeSort(indexedNums, res);

        // Convert the result array to a list of integers before returning
        List<Integer> resList = new ArrayList<>();
        for(int count : res){
            resList.add(count);
        }

        return resList;
    }

    public static void main(String[] args) {
        int[] nums = {5,2,6,1};
        List<Integer> ans = countSmaller(nums);
        for(int num : ans){
            System.out.print(num+" ");
        }
        System.out.println();
    }
}