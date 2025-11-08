
// Problem link - https://leetcode.com/problems/maximize-the-minimum-powered-city/description/?envType=daily-question&envId=2025-11-07

// utility function to check if it's possible to achieve minimum power of 'minPower' for all cities
function canAchieveMinPower(minPower, diff, r, k, n) {
    // create a copy to simulate building new power stations
    const tempDiff = [...diff];

    // iterate through each city to check if minPower is achievable
    let currentPower = 0;
    for (let i = 0; i < n; i++) {
        // update current city's power using difference array
        currentPower += tempDiff[i];

        // if current city has less power than required minimum
        if (currentPower < minPower) {
            // calculate how many power stations we need to add
            const stationsNeeded = minPower - currentPower;

            // if we don't have enough power stations left, this target is not achievable
            if (stationsNeeded > k) {
                return false;
            }

            // use the required power stations
            k -= stationsNeeded;

            // using DAT
            currentPower += stationsNeeded;
            if (i + 2 * r + 1 < n) {
                tempDiff[i + 2 * r + 1] -= stationsNeeded;
            }
        }
    }
    
    // return true, as successfully achieved minPower for all cities
    return true;
}

/**
 * @param {number[]} stations
 * @param {number} r
 * @param {number} k
 * @return {number}
 */
let maxPower = function(stations, r, k) {
    const n = stations.length;

    // step 1 - build initial difference array to calculate power for each city
    // diff[i] represents the change in power contribution at city i
    const diff = new Array(n).fill(0);
    
    for (let i = 0; i < n; i++) {
        // range should not be out of index
        diff[Math.max(0, i - r)] += stations[i];
        
        if (i + r + 1 < n) {
            diff[i + r + 1] -= stations[i];
        }
    }

    // step 2 - binary search on the answer (maximum possible minimum power)
    // lower bound: minimum power any city currently has
    let left = Math.min(...stations);
    
    // upper bound: if we place all k stations optimally, maximum possible power
    let right = stations.reduce((sum, station) => sum + station, 0) + k;

    // using binary search to find the maximum achievable minimum power
    let res = 0;
    while (left <= right) {
        const mid = left + Math.floor((right - left) / 2);

        // check if we can make every city have at least 'mid' power
        if (canAchieveMinPower(mid, diff, r, k, n)) {
            // if achievable, try for a higher minimum power
            res = mid;
            left = mid + 1;
        } else {
            // if not achievable, try for a lower minimum power
            right = mid - 1;
        }
    }

    // step 3 - return final result, res
    return res;
};

// const stations = [1,2,4,5,0], r = 1, k = 2;

const stations = [4,4,4,4], r = 0, k = 3;
console.log(maxPower(stations, r, k));