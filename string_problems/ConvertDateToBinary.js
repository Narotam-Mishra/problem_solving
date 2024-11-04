
// Problem link : https://leetcode.com/problems/convert-date-to-binary/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let convertDateToBinary = function(date) {
    // split the date into components (year, month, day)
    let dateArr = date.split("-");
    
    // convert each component to binary and join with '-'
    let res = dateArr.map(part => parseInt(part, 10).toString(2)).join("-");
    
    // return the result 'res`
    return res;
};

// let date = "2080-02-29";

let date = "1900-01-01";
console.log(convertDateToBinary(date));
