
// Sum of n-numbers using rest operator

function nSum(...numbers){
    let s = 0;
    for(let i=0; i<numbers.length; i++){
        s += numbers[i];
    }
    return s;
}

let res = nSum(4,5,6,7,8,9,1,3,5,9);
console.log(res);