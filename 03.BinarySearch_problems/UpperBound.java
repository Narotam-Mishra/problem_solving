package BinarySearch_problems;

/**
 * UpperBound
 */
public class UpperBound {
    public static int findUpperBound(int[] arr, int x){
        int s = 0, e = arr.length - 1;
        int ans = -1;

        while(s <= e){
            int mid = (s + e)/2;
            // discard left half of array
            if(x >= arr[mid]){
                s = mid + 1;
            }else{
                // probable ans will available in right half
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = {2,2,3,3,5,5,8,8};
        int ans = findUpperBound(arr, 5);
        System.out.println(ans);
    }
}