
function friendPairing(n){
    // Base case:
    if(n === 0 || n === 1 || n === 2) return n;

    return friendPairing(n-1) + ((n-1) * friendPairing(n-2));
}

function numberOfWays(n){
    return friendPairing(n);
}

let n = 5;
console.log(numberOfWays(n));