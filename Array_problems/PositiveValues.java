package Array_problems;

public class PositiveValues {

    public static void main(String[] args) {
        int arr[] = {2,6,-5,-1,0,4,-9};
        printPositiveValues(arr);
    }

    public static void printPositiveValues(int[] arr){
        for(int i=0; i<arr.length; i++){
            if(arr[i]>=0){
                System.out.println(arr[i]);
            }
        }
    }
}
