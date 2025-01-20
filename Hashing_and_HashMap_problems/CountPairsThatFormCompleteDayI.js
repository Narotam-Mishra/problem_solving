
// Problem link : https://leetcode.com/problems/count-pairs-that-form-a-complete-day-i/description/?envType=problem-list-v2&envId=hash-table

let countCompleteDayPairs1 = function(hours) {
    let count = 0;
    for(let i=0; i<hours.length; i++) {
        for(let j=i+1; j<hours.length; j++) {
            if((hours[i] + hours[j]) % 24 === 0){
                count++;
            }
        }
    }
    return count;
};

let countCompleteDayPairs = function(hours) {
    // step 1 - initialize an array to count frequencies of remainders
    const freq = new Array(24).fill(0);

    // step 2 - calculate remainders and count their occurrences
    for(let hour of hours){
        const remainder = hour % 24;
        freq[remainder]++;
    }

    // step 3 - count pairs for each remainder
    let pairs = 0;
    for(let r=0; r<=12; r++){
        // special case : remainders 0 and 12 pair with themselves
        if(r === 0 || r === 12){
            // nc2 pairs
            pairs += Math.floor(freq[r] * (freq[r] -1) / 2);
        }else{
            // general case: Pair r with 24 - r
            pairs += freq[r] * freq[24-r]
        }
    }

    // step 4 - return pairs count
    return pairs;
};

const hours = [12,12,30,24,24];

// const hours = [72,48,24,3];
console.log(countCompleteDayPairs(hours));
