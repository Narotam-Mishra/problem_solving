package Array_problems;

/**
 * FirstRepeatingNumber
 */
public class FirstRepeatingNumber {

    public static int firstRepeatingNumber(int[] arr){
        for(int i=0; i<arr.length; i++){
            for(int j=i+1; j<arr.length-1; j++){
                if(arr[i] == arr[j]){
                    return i+1;
                }
            }
        }
        return -1;
    }
}