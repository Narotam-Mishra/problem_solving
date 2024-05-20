
function swapNumbers(a,b){
    console.log(`Original Values: a = ${a} b = ${b}`);
    a = a + b;
    b = a - b;
    a = a - b;
    console.log(`Swapped Values: a = ${a} b = ${b}`);
}

swapNumbers(12,45);