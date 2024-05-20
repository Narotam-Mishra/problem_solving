
// Problem link - https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

package BinarySearch_problems;

public class PeakIndexInMoutainArray {
    public static int peakIndexInMountainArray(int[] arr) {
        int low = 0, high = arr.length-1;

        while(low < high){
            int mid = low + (high-low)/2;
            if(arr[mid] < arr[mid+1]){
                // dicard left half of array
                low = mid + 1;
            }else{
                // got first proabable peak element index
                high = mid;
            }
        }
        return high;
    }

    public static void main(String[] args) {
        int[] arr = {0,10,5,2};
        int ans = peakIndexInMountainArray(arr);
        System.out.println(ans);
    }
}
