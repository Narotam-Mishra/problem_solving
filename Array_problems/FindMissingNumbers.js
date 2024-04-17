
/*
find missing numbers in an array range of maximum and minimum number
*/

function findMissingNumbers(arr){
    // find maximum and minimum number in the list
    let maxNum = Math.max(...arr);
    let minNum = Math.min(...arr);

    // create set to mark presence of numbers
    const presentNums = new Set();

    // mark numbers from the input array as present
    for(const num of arr){
        if(num >= minNum && num <= maxNum){
            presentNums.add(num);
        }
    }

    // array missNums to store missing numbers
    let missNums = [];
    for(let n=minNum; n<=maxNum; n++){
        if(!presentNums.has(n)){
            missNums.push(n);
        }
    }

    // return missing numbers array
    return missNums;
}

let nums = [2,5,7];
let ans = findMissingNumbers(nums);
console.log("Missing Numbers:",...ans);