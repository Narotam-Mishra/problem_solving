
/*

You are given an integer array of size n and you are given element 'x'. Return the index of the first value greater than or equal to 'x'.

 */

package binarySearch_problems;

public class LowerBound {
    public static int findLowerBound(int[] arr, int x){
        int s = 0, e = arr.length - 1;
        int ans = -1;

        while(s <= e){
            int mid = (s + e)/2;
            // if x is greater than mid then discard left half of array
            if(x > arr[mid]){
                s = mid + 1;
            }else{
                // if x is less than or equal to mid then we get the first probable ans
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int arr[] = {2,2,3,3,3,4,4,6,6};
        int res = findLowerBound(arr, 4);
        System.out.println(res);
    }
}
