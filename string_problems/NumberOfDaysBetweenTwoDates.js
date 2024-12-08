
// Problem link : https://leetcode.com/problems/number-of-days-between-two-dates/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let daysBetweenDates = function(date1, date2) {
    // parse date inputs
    const d1 = new Date(date1);
    const d2 = new Date(date2);

    // get the timestamps in milliseconds
    const t1 = d1.getTime();
    const t2 = d2.getTime();

    // calculate the absolute difference in milliseconds
    const diffInMillis = Math.abs(t1 - t2);

    // convert the difference into days
    const diffInDays = diffInMillis / (1000 * 24 * 60 * 60);

    // return the number of days as an integer
    return Math.floor(diffInDays);
};

// let date1 = "2019-06-29", date2 = "2019-06-30";

let date1 = "2020-01-15", date2 = "2019-12-31";
console.log(daysBetweenDates(date1, date2));

