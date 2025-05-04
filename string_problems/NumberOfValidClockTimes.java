
// Problem link - https://leetcode.com/problems/number-of-valid-clock-times/?envType=problem-list-v2&envId=string

package string_problems;

public class NumberOfValidClockTimes {
    public static int countTime(String time) {
        // step 1 - store final result in `res`
        int res = 1;

        // step 2 - get hours and minutes
        String[] parts = time.split(":");
        String hours = parts[0];
        String minutes = parts[1];

        // step 3 - handling hours
        if(hours.equals("??")){
            res *= 24;
        }else{
            if(hours.charAt(0) == '?'){
                if(hours.charAt(1) > '3'){
                    res *= 2;
                }else{
                    res *= 3;
                }
            }

            if(hours.charAt(1) == '?'){
                if(hours.charAt(0) == '2'){
                    res *= 4;
                }else{
                    res *= 10;
                }
            }
        }

        // step 4 - handling minutes
        if(minutes.charAt(0) == '?'){
            res *= 6;
        }
        if(minutes.charAt(1) == '?'){
            res *= 10;
        }

        // step 5 - return final result
        return res;
    }

    public static void main(String[] args) {
        // String time = "?5:00";

        // String time = "0?:0?";

        String time = "??:??";
        System.out.println(countTime(time));
    }
}