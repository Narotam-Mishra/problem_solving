
// Problem link - https://leetcode.com/problems/capitalize-the-title/description/?envType=problem-list-v2&envId=string

let capitalizeTitle = function(title) {
    // step 1 - store result in `res`
    let res = [];

    // step 2 - iterate on each word and captialize as per given conditions
    for(let word of title.split(' ')){
        // if word is of length 1 or 2
        if(word.length === 1 || word.length === 2){
            res.push(word.toLowerCase());
        }else{
            // otherwise captialize first letter only
            res.push(word[0].toUpperCase() + word.slice(1).toLowerCase());
        }
    }

    // step 3 - return result `res` by joining it by space
    return res.join(' ');
};

// const title = "capiTalIze tHe titLe";

// const title = "First leTTeR of EACH Word";

const title = "i lOve leetcode";
console.log(capitalizeTitle(title));

