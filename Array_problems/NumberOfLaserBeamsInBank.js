
// Problem link - https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2025-10-27

let numberOfBeams = function(bank) {
    // store total number of laser beams
    let totalLaserBeams = 0;

    // store the count of devices in the previous non-empty row
    let prevDeviceCount = 0;
    
    // step 1 - iterate through each row of the bank
    for(let i=0; i<bank.length; i++){
        // step 2 - count the number of security devices ('1's) in the current row
        let currDeviceCount = 0;

        for(let j=0; j<bank[i].length; j++){
            if(bank[i][j] === '1'){
                currDeviceCount++;
            }
        }

        // step 3 - check if the current row has at least one device
        if(currDeviceCount > 0){
            // step 4 - calculate beams between previous non-empty row and current row
            // each device in the previous row connects to each device in current row
            totalLaserBeams += currDeviceCount * prevDeviceCount;

            // step 5 - update previous device count for the next iteration
            prevDeviceCount = currDeviceCount;
        }
    }

    // step 6 - return total number of laser beams in the bank
    return totalLaserBeams;
};

// const bank = ["011001","000000","010100","001000"];

const bank = ["000","111","000"];
console.log(numberOfBeams(bank));