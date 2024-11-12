
// Problem link : https://leetcode.com/problems/day-of-the-year/description/?envType=problem-list-v2&envId=string&difficulty=EASY&status=TO_DO

let dayOfYear = function(date) {
    // parse the input date string to create a Date object
    const dateVal = new Date(date);
    
    // create a Date object for the start of the year (January 1st of the same year)
    const startOfYear = new Date(dateVal.getFullYear(), 0, 1);

    // calculate the difference in milliseconds between the given date and January 1st
    const diffInMilliseconds = dateVal - startOfYear;

    // convert the difference from milliseconds to days and add 1 (since January 1st is day 1)
    const dayNumber = Math.floor(diffInMilliseconds / (1000 * 60 * 60 * 24)) + 1;
    
    // return dayNumber value
    return dayNumber;
};

// let dateInp = "2019-02-10";

// let dateInp = "2019-01-01";

let dateInp = "2019-10-29";
console.log(dayOfYear(dateInp));
