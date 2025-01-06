
// Problem link : https://leetcode.com/problems/design-parking-system/description/?envType=problem-list-v2&envId=design

/**
 * @param {number} big
 * @param {number} medium
 * @param {number} small
 */
let ParkingSystem = function(big, medium, small) {
    // intialize an array to track the number of slots for each type of parking space
    this.slots = [big, medium, small];
};

/** 
 * @param {number} carType
 * @return {boolean}
 */
ParkingSystem.prototype.addCar = function(carType) {
    // check if there is available space for the given car type
    if(this.slots[carType - 1] > 0){
        // if parking space is available
        this.slots[carType - 1]--;
        // decrement the available slot count and return true
        return true;
    }
    // otherwise return false
    return false;
};

// create a parking system
let parkingSystem = new ParkingSystem(1, 1, 0);

// add cars of different types
console.log(parkingSystem.addCar(1)); // true (big car parked)
console.log(parkingSystem.addCar(2)); // true (medium car parked)
console.log(parkingSystem.addCar(3)); // false (no small slots available)
console.log(parkingSystem.addCar(1)); // false (no big slots left)

