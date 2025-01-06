
#include<bits/stdc++.h>
using namespace std;

class ParkingSystem {
private:
    // vector to track available slots for big, medium, and small
    vector<int> slots;
public:
   // constructor to initialize the parking slots
    ParkingSystem(int big, int medium, int small) {
        slots = {big, medium, small};
    }
    
    bool addCar(int carType) {
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
};

int main(){
    ParkingSystem* parkingSystem = new ParkingSystem(1, 1, 0);

    cout << (parkingSystem->addCar(1) ? "true" : "false") << endl; // true (big car parked)
    cout << (parkingSystem->addCar(2) ? "true" : "false") << endl; // true (medium car parked)
    cout << (parkingSystem->addCar(3) ? "true" : "false") << endl; // false (no small slots available)
    cout << (parkingSystem->addCar(1) ? "true" : "false") << endl; // false (no big slots left)
    
    delete parkingSystem;
    return 0;
}