
// Problem link : https://leetcode.com/problems/largest-3-same-digit-number-in-string/

let largestGoodInteger = function(num) {
    // step 1: list all possible "good integers" in descending order
    const largeNums = ["999", "888", "777", "666", "555", "444", "333", "222", "111", "000"];
    
    // step 2: iterate through each potential good integer
    for(let strNum of largeNums){
        // step 3: check if the current good integer is a substring of num
        if(num.includes(strNum)){
            // if found, return it immediately as the list is ordered from largest to smallest
            return strNum;
        }
    }
    // step 4: if no good integer is found, return an empty string
    return "";
};

// let num = "6777133339";

// let num = "2300019";

let num = "42352338";
console.log(largestGoodInteger(num));
