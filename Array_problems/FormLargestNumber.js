
function formLargestNumber(nums){
    // custom compare function
    const customCompare = (a,b) => {
        // concate a + b
        const order1 = `${a}${b}`;
        // concate b + a
        const order2 = `${b}${a}`;
        // sort in ascending order
        return order2 - order1;
    }
    nums.sort(customCompare);
    if(nums[0] === "0"){
        return "0";
    }
    return nums.join("");
}

let nums = [3,30,34,5,9];
let largestNum = formLargestNumber(nums);
console.log(largestNum);