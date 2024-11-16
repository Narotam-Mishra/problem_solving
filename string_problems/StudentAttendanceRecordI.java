package string_problems;

public class StudentAttendanceRecordI {
    public static boolean checkRecord(String s) {
        // step 1: count the number of absences ('A')
        int numOfAbsences = 0;
        for(char ch : s.toCharArray()){
            if(ch == 'A'){
                numOfAbsences++;
                if(numOfAbsences >= 2){
                    // early exit if absences are 2 or more
                    return false;
                }
            }
        }

        // step 2: check for 3 or more consecutive 'L's
        if(s.contains("LLL")){
            return false;
        }
        
        // if both conditions are satisfied, the student is eligible
        return true;
    }

    public static void main(String[] args) {
        // String str = "PPALLP";

        String str = "PPALLL";
        System.out.println(checkRecord(str));
    }
}