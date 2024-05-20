
// Problem link - https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456

package BinarySearch_problems;

public class CountElementOccurence {

    public static int findLeftIndex(int[] arr, int target) {
        int s = 0, e = arr.length - 1;
        int leftIndex = -1;

        while (s <= e) {
            int mid = (s + e) / 2;
            if (arr[mid] >= target) {
                if (arr[mid] == target) {
                    leftIndex = mid;
                }
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return leftIndex;
    }

    public static int findRightIndex(int[] arr, int target) {
        int s = 0, e = arr.length - 1;
        int righttIndex = -1;

        while (s <= e) {
            int mid = (s + e) / 2;
            if (arr[mid] <= target) {
                if (arr[mid] == target) {
                    righttIndex = mid;
                }
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return righttIndex;
    }
    public static int count(int arr[], int n, int x) {
        int leftIndex = findLeftIndex(arr, x);
        int rightIndex = findRightIndex(arr, x);

        if(leftIndex != -1 && rightIndex != -1){
            return rightIndex - leftIndex + 1;
        }
        return 0;
    }
}
