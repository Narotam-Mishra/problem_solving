package Array_problems;

public class SolutionFindMaximum {
    
    public static int findMaximumInArray(int[] arr){
        int maxNum = Integer.MIN_VALUE;

        for(int i=0; i<arr.length; i++){
            if(arr[i] > maxNum){
                maxNum = arr[i];
            }
        }
        return maxNum;
    }
}
