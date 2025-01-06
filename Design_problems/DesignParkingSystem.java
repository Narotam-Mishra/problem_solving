
// Problem link : https://leetcode.com/problems/design-parking-system/description/?envType=problem-list-v2&envId=design

package Design_problems;

class ParkingSystem {
    // array to track available slots for big, medium, and small
    private int[] slots;

    // intialize the parking lot using constructor
    public ParkingSystem(int big, int medium, int small) {
        slots = new int[] {big, medium, small};
    }
    
    public boolean addCar(int carType) {
        // check if there is available space for the given car type
        if(slots[carType - 1] > 0){
            // if parking space is available
            slots[carType - 1]--;
            // decrement the available slot count and return true
            return true;
        }
        // otherwise return false
        return false;
    }
}

public class DesignParkingSystem {
    public static void main(String[] args) {
        ParkingSystem ps = new ParkingSystem(1, 1, 0);

        System.out.println(ps.addCar(1)); // true (big car parked)
        System.out.println(ps.addCar(2)); // true (medium car parked)
        System.out.println(ps.addCar(3)); // false (no small slots available)
        System.out.println(ps.addCar(1)); // false (no big slots left)
    }
}
