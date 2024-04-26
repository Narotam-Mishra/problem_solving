
// 2426. Number of Pairs Satisfying Inequality
// Problem Link - https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/


package BinarySearch_problems;

public class CountInequalitiyPairs {
    static long pairCount = 0;

    private static void countInequalitiyPairs(int[] arr, int s, int mid, int e, int diff){
        int i = s, j = mid+1;

        // count pairs as per given equation
        while (i <= mid && j <= e) {
            if(arr[i] <= arr[j] + diff){
                pairCount += (e -j + 1);
                i++;
            }else{
                j++;
            }
        }
    }

    private static void mergeSortedArray(int[] arr, int s, int mid, int e){
        int i = s, j = mid+1, k=0;
        int[] temp = new int[e-s+1];

        while(i<=mid && j<=e){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[j++];
            }
        }

        // copy back remaining elements from left sub array
        while(i <= mid){
            temp[k++] = arr[i++];
        }

        // copy back remaining elements from left sub array
        while(j <= e){
            temp[k++] = arr[j++];
        }

        // copy back temp array elements to original array arr
        for(int p=0; p<temp.length; p++){
            arr[s+p] = temp[p];
        }
    }
    private static void mergeSort(int[] arr, int s, int e, int diff){
        // Base case:
        if(s == e) return;

        // calculate mid
        int mid = (s + e)/2;

        // Recursively call mergeSort() on left half of array
        mergeSort(arr, s, mid, diff);

        // Recursively call mergeSort() on right half of array
        mergeSort(arr, mid+1, e, diff);

        // Count inequalities pairs
        countInequalitiyPairs(arr, s, mid, e, diff);

        // merge sorted array
        mergeSortedArray(arr, s, mid, e);
    }
    public static long numberOfPairs(int[] nums1, int[] nums2, int diff) {
        pairCount = 0;
        int size = nums1.length;
        int[] diffArr = new int[size];

        // calculate diff in diffArr
        for(int i=0; i<size; i++){
            diffArr[i] = nums1[i] - nums2[i];
        }

        mergeSort(diffArr, 0, size-1, diff);
        return pairCount;
    }

    public static void main(String[] args) {
        // int[] arr1 = {3,2,5};
        // int[] arr2 = {2,2,1};
        // int diff = 1;

        int[] arr1 = {-4, -4, 4, -1, -2, 5};
        int[] arr2 = {-2, 2, -1, 4, 4, 3};
        int diff = 1;

        long ans = numberOfPairs(arr1, arr2, diff);
        System.out.println(ans); 
    }
}
