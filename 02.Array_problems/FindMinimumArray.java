package Array_problems;

public class FindMinimumArray {

    public static void main(String[] args) {
        int arr[] = {12, 18, 7, 3, 14, 28};
        System.out.println(findMinimum(arr));
    }

    public static int findMinimum(int[] arr){
        int minVal = arr[0];
        for(int i=1; i<arr.length; i++){
            if(arr[i] < minVal){
                minVal = arr[i];
            }
        }
        return minVal;
    }
}
