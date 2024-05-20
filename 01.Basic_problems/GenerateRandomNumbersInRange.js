
// WAP to generate random between two given numbers.

function randomInRange(minVal, maxVal){
    return Math.floor(Math.random() * (maxVal-minVal+1)) + minVal
}

console.log(randomInRange(10,50));