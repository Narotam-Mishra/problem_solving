
function findSumofDigits(num){
    let digitsSum = 0;
    while(num>0){
        digitsSum += num%10;
        num = Math.floor(num/10);
    }
    return digitsSum;
}

let n = 32562;
console.log(findSumofDigits(n));