package Array_problems;

public class SolutionBuildArray {
    
    public static int[] buildArray(int arr[]){
        int res[] = new int[arr.length];

        for(int i=0; i<arr.length; i++){
            res[i] = arr[arr[i]];
        }
        return res;
    }
}
