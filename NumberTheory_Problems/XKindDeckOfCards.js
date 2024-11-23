
// Problem link :- https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/?envType=problem-list-v2&envId=number-theory&status=TO_DO&difficulty=EASY

// helper function to calculate the greatest common divisor (GCD) using Euclid's algorithm
function gcd(a, b){
    while(b !== 0){
        const temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

let hasGroupsSizeX = function(deck) {
    // step 1: create a frequency map to count occurrences of each number
    let objMap = {};

    for(let i=0; i<deck.length; i++){
        if(objMap[deck[i]]){
            // increment count if the number already exists in the map
            objMap[deck[i]]++
        }else{
            // initialize count for a new number
            objMap[deck[i]] = 1;
        }
    }

    // step 2: extract all frequency values into an array
    let counts = Object.values(objMap);

     // step 3: Find the GCD of all counts
    let overallGCD = counts[0];

    // start with the first frequency
    for(let i=1; i<counts.length; i++){
        overallGCD = gcd(overallGCD, counts[i]);

        // early exit: if at any point GCD becomes 1, no valid grouping is possible
        if(overallGCD === 1) return false;
    }

    // step 5: Return true if GCD is at least 2, otherwise false
    return overallGCD >= 2;
};

// let deck = [1,2,3,4,4,3,2,1];

let deck = [1,1,1,2,2,2,3,3];
console.log(hasGroupsSizeX(deck));
