package Array_problems;

public class FindSecondMax {
    
    public static int findSecondMax(int[] arr){
        int maxVal = SolutionFindMaximum.findMaximumInArray(arr);

        // traverse the array and mark the max value as minus infinity
        for(int i=0; i<arr.length; i++){
            if(arr[i] == maxVal){
                arr[i] = Integer.MIN_VALUE;
            }
        }

        // Now find second maximum in array
        int secondMax = SolutionFindMaximum.findMaximumInArray(arr);
        return secondMax;
    }
}
