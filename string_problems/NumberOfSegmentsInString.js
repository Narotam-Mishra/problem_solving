
// Problem link : https://leetcode.com/problems/number-of-segments-in-a-string/description/?envType=problem-list-v2&envId=string&favoriteSlug=&status=TO_DO&difficulty=EASY

let countSegments = function(s) {
    // step 1: trim leading and trailing spaces
    // step 2: then split the string by space to get potential segments
    const strParts = s.trim().split(' ');

    // step 3: filter out empty strings (caused by multiple spaces)
    const segments = strParts.filter(str => str.length > 0);

    // step 4: return the number of valid segments
    return segments.length;
};

// let str = "Hello, my name is John";

// let str = "Hello";

let str = "           ";
console.log(countSegments(str));
