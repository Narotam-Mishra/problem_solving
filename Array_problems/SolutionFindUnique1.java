package Array_problems;

public class SolutionFindUnique1 {
    
    public static int findUniquenumber(int arr[]){
        for(int i=0; i<arr.length; i++)
        {
            for(int j=i+1; j<arr.length; j++)
            {
                if(arr[i] == arr[j]){
                    arr[i] = -1;
                    arr[j] = -1;
                }
            }
        }

        int ans = -1;
        for(int i=0; i<arr.length; i++){
            if(arr[i] > 0){
                ans = arr[i];
            }
        }
        return ans;
    }
}
