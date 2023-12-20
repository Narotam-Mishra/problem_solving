package Array_problems;

public class SolutionLinearSearch {
    
    public static int linearSearch(int arr[], int key)
    {
        for(int i=0; i<arr.length; i++){
            if(arr[i] == key){
                return i;
            }
        }
        return -1;
    }
}
