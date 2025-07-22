
// Problem link - https://leetcode.com/problems/number-of-employees-who-met-the-target/description/?envType=problem-list-v2&envId=array

let numberOfEmployeesWhoMetTarget = function(hours, target) {
    // store the count of employees who worked at least target hours in `count`
    let count = 0;

    // step 1 - iterate on each hour
    for(let hour of hours){

        // step 2 - check if working hour is greater than or equal to target hour
        if(hour >= target){
            // increment counter
            count++;
        }
    }

    // step 3 - return counter `count`
    return count;
};

// const hours = [0,1,2,3,4], target = 2;

const hours = [5,1,4,2,2], target = 6;
console.log(numberOfEmployeesWhoMetTarget(hours, target));