
// Problem link - https://leetcode.com/problems/avoid-flood-in-the-city/description/?envType=daily-question&envId=2025-10-07

let avoidFlood = function(rains) {
    // get the total number of days
    const n = rains.length;
    
    // array to store indices of dry days (when rains[i] === 0)
    // these are the days we can choose to dry a lake
    const dryDays = [];
    
    // map to track which lakes are currently full
    // key: lake number, value: the day index when it was last filled
    const filledLakes = new Map();
    
    // result array `res` to store our answer
    // will contain -1 for rainy days and lake number for dry days
    const res = new Array(n);
    
    // step 1 - process each day sequentially
    for(let i = 0; i < n; i++) {
        const lake = rains[i];
        
        // step 2 - case 1: DRY DAY (rains[i] === 0)
        if(lake === 0) {
            // store this day index as an available dry day
            // we might need it later to prevent a flood
            dryDays.push(i);
            
            // set placeholder value (dry lake 1 by default)
            // this will be overwritten if we need to use this day
            res[i] = 1;
        }
        // step 3 - case 2: RAINY DAY (rains[i] > 0)
        else {
            // check if this lake is already full
            if(filledLakes.has(lake)) {
                // FLOOD ALERT! This lake is already full
                // we must have dried it using a dry day that occurred
                
                // get the day when this lake was last filled
                const lastFilledIndex = filledLakes.get(lake);
                
                // variable to store the dry day we'll use to prevent flood
                let index = -1;
                
                // index of the dry day in our dryDays array
                let removeIdx = -1;
                
                // step 4 - search through available dry days to find one that occurred
                // after the lake was last filled
                for(let j = 0; j < dryDays.length; j++) {
                    // check if this dry day is after the lake was filled
                    if(dryDays[j] > lastFilledIndex) {
                        // Found a valid dry day!
                        index = dryDays[j];
                        removeIdx = j;
                        break; 
                    }
                }
                
                // step 5 - if no valid dry day was found, flood is inevitable
                if(index === -1) {
                    // return empty array to indicate impossible scenario
                    return [];
                }
                
                // atep 6 - assign this dry day to dry the specific lake
                // that would have caused a flood
                res[index] = lake;
                
                // step 7 - remove this dry day from available list
                dryDays.splice(removeIdx, 1);
            }
            
            // step 8 - mark this lake as full (or update fill time)
            // store current day as the last time this lake was filled
            filledLakes.set(lake, i);
            
            // step 9 - for rainy days, the answer is always -1
            res[i] = -1;
        }
    }
    
    // step 10 - return the final result array
    return res;
};

// const rains = [1,2,3,4];

// const rains = [1,2,0,0,2,1];

const rains = [1,2,0,1,2];
console.log(avoidFlood(rains));