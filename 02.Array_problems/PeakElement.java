package Array_problems;

public class PeakElement {
    public static void main(String[] args) {
        int arr[] = {1, 1, 3, 4, 2, 3, 5, 7, 0};
        System.out.println(findPeakElement(arr));
    }

    public static int findPeakElement(int arr[])
    {
        int ans = 0;
        for(int i=1; i<arr.length-1; i++){
            if(arr[i] > arr[i-1] && arr[i]>arr[i+1]){
                ans = arr[i];
                break;
            }
        }
        return ans;
    }
}
