
// sort array's numbers using merge sort algorithm

package Array_problems;

import java.util.Arrays;

/**
 * MergeSort
 */
public class MergeSort {

    public static int[] merge(int[] left, int[] right){
        int m = left.length, n = right.length;
        int i=0, j=0, k=0;
        int[] resArr = new int[m+n];

        // compare array's numbers from both left and right arrays
        while(i<m && j<n){
            if(left[i] < right[j]){
                resArr[k] = left[i];
                i++;
                k++;
            }else{
                // right[j] < left[i]
                resArr[k] = right[j];
                j++;
                k++;
            }
        }

        // if right[] is exhausted, copy remaining elements from left array to resArr[]
        while(i < m){
            resArr[k] = left[i];
            i++;
            k++;
        }
        
        // if left[] is exhausted, copy remaining elements from right array to resArr[]
        while(j < n){
            resArr[k] = right[j];
            j++;
            k++;
        }
        
        return resArr;
    }

    public static int[] mergeSortHelper(int[] arr, int start, int end){
        // Base case: array of single element is always sorted
        if(start == end){
            int[] res = new int[1];
            res[0] = arr[start];
            return res;
        }else{
            int mid = (int)(start + end)/2;
            // Recursive case1 : recursive call to left part of array
            int[] left = mergeSortHelper(arr, start, mid);

            // Recursive case2 : recursive call to right part of array
            int[] right = mergeSortHelper(arr, mid+1, end);

            // merge sorted array
            return merge(left, right);
        }
    }

    public static int[] mergeSort(int[] arr){
        int ans[] = mergeSortHelper(arr, 0, arr.length-1);
        return ans;
    }
    public static void main(String[] args) {
        int[] arr = {7,2,6,1,4,5,3};
        System.out.println("Unsorted Array:"+Arrays.toString(arr));
        int[] sortArr = mergeSort(arr);
        System.out.println("Sorted Array:"+Arrays.toString(sortArr));
    }
}