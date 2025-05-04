
// Problem link - https://leetcode.com/problems/number-of-valid-clock-times/description/?envType=problem-list-v2&envId=string

// Approach 1 - Brute Force
let countTime1 = function(time) {
    // step 1 - initialize counter to count the number of valid clock times
    let count = 0;

    // step 2 - try every possible hours from 00 to 23
    for(let h=0; h<24; h++){
        // find formatted hour
        let hh = h.toString().padStart(2, '0');

        // step 3 - try every possible minutes from 00 to 59
        for(let m=0; m<60; m++){
            // find formatted minutes
            let mm = m.toString().padStart(2, '0');

            // step 4 - form the full time 
            let t = hh + ":" + mm;

            // step 5 - check if it matches the input time `time`
            let isMatch = true;
            for(let i=0; i<5; i++){
                // if it's not `?` and the character don't match, it's invalid
                if(time[i] !== '?' && t[i] !== time[i]){
                    isMatch = false;
                    // for invalid time break the loop instantly
                    break;
                }
            }

            // step 6 - if all characters match, count it as valid
            if(isMatch){
                count++;
            }
        }
    }

    // step 7 - return valid clock times count
    return count;
};

// Approach 2 (Optimal approach using Maths)
let countTime = function(time) {
    // step 1 - store number of possible outcomes in `res` array
    const res = [];

    // step 2
    let [hours, minutes] = time.split(":");

    // step 3 - handling hours 
    if(hours == '??') res.push(24);
    else{
        if(hours[0] == '?'){
            hours[1] > 3 ? res.push(2) : res.push(3);
        }
        if(hours[1] == '?'){
            hours[0] == 2 ? res.push(4) : res.push(10);
        }
    }

    // step 3 - handling minutes
    if(minutes[0] == '?'){
        res.push(6);
    }
    if(minutes[1] == '?'){
        res.push(10);
    }

    // step 4 - multiplies the counts to get total valid combinations and return it
    return res.reduce((a,b) => a * b, 1);
};

// const time = "?5:00";

// const time = "0?:0?";

// const time = "??:??";

const time = "2?:??";
console.log(countTime(time));
