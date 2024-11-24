
// Problem link : https://leetcode.com/problems/shuffle-string/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let restoreString = function(s, indices) {
    // step 1: Create an empty array of the same length as the string
    const shuffled = new Array(s.length);

    // step 2: iterate through each character of the string and place it at the correct index.
    for(let i=0; i<s.length; i++){
        shuffled[indices[i]] = s[i];
    }

    // step 3: Convert the array back to a string and return it.
    return shuffled.join('');
};

// let str = "codeleet", indices = [4,5,6,7,0,2,1,3];

let str = "abc", indices = [0,1,2];
console.log(restoreString(str, indices));
