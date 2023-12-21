package Array_problems;

public class SolutionLinearSearch {
    
    public static int linearSearch(int arr[], int key)
    {
        // edge case
        if(arr.length == 0){
            return -1;
        }
        
        for(int i=0; i<arr.length; i++){
            if(arr[i] == key){
                return i;
            }
        }
        return -1;
    }
}
