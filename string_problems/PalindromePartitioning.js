
// Problem link - https://leetcode.com/problems/palindrome-partitioning/description/?envType=problem-list-v2&envId=string

// utlity function to checking palindromic string
function isPalindromeString(str){
    let l = 0, r = str.length - 1;

    while(l < r){
        if(str[l] !== str[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

let partition = function(s) {
    // step 1 - store result in `res` array
    let res = [];

    // step 2 - use recursive function to explore all possible partitions
    function backtrack(start, path){
        // base case: if we have reached the end of string
        if(start === s.length){
            res.push([...path]);
            return;
        }

        // recursive case: explore all substrings from start to end
        for(let end = start; end<s.length; end++){
            const subStr = s.slice(start, end+1);

            // step 3 - check for pallindrome string
            if(isPalindromeString(subStr)){
                // choose current substring as it os palindrome
                path.push(subStr);

                // explore other substrings
                backtrack(end+1, path);

                // discard once done, to avoid duplicates
                path.pop();
            }
        }
    };

    // step 4 - intiate recursive `backtrack` function
    backtrack(0, []);
    
    // step 5 - return result `res`
    return res;
};

const s = "aab";

// const s = "a";
console.log(partition(s));
