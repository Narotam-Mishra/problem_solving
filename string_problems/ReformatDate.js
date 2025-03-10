
// Problem link - https://leetcode.com/problems/reformat-date/description/?envType=problem-list-v2&envId=string

let reformatDate = function(date) {
    // step 1 - split date into day, month and year
    let [day, month, year] = date.split(' ');

    // step 2 - remove last two characters from the day
    let numericDay = day.slice(0, -2).padStart(2, '0');

    // step 3 - create a mapping of months to their 2-digit numeric format
    const monthMap = {
        "Jan": "01", "Feb": "02", "Mar": "03", "Apr": "04",
        "May": "05", "Jun": "06", "Jul": "07", "Aug": "08",
        "Sep": "09", "Oct": "10", "Nov": "11", "Dec": "12"
    };

    // step 4 - convert month to numeric value using month map
    let numericMonth = monthMap[month];

    // step 5 - return the formatted date in YYYY-MM-DD
    return `${year}-${numericMonth}-${numericDay}`;
};

// const date = "20th Oct 2052";

// const date = "6th Jun 1933";

const date = "26th May 1960";
console.log(reformatDate(date));
