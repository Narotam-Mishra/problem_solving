package Array_problems;

public class NumberOfLaserBeamsInBank {
    public static int numberOfBeams(String[] bank) {
        // store total number of laser beams
        int totalLaserBeams = 0;

        // store the count of devices in the previous non-empty row
        int prevDeviceCount = 0;
        
        // step 1 - iterate through each row of the bank
        for(int i=0; i<bank.length; i++){
            
            // step 2 - count the number of security devices ('1's) in the current row
            int currDeviceCount = 0;
            for(int j=0; j<bank[i].length(); j++){
                if(bank[i].charAt(j) == '1'){
                    currDeviceCount++;
                }
            }

            // step 3 - check if the current row has at least one device
            if(currDeviceCount > 0){
                // step 4 - calculate beams between previous non-empty row and current row
                totalLaserBeams += currDeviceCount * prevDeviceCount;

                // step 5 - update previous device count for the next iteration
                prevDeviceCount = currDeviceCount;
            }
        }

        // step 6 - return total number of laser beams in the bank
        return totalLaserBeams;
    }

    public static void main(String[] args) {
        // String[] bank = {"011001","000000","010100","001000"};

        String[] bank = {"000","111","000"};
        System.out.println(numberOfBeams(bank));
    }
}
