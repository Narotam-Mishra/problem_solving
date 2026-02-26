
// Problem link - https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/?envType=daily-question&envId=2026-02-26

let numSteps = function(s) {
    const addOne = (str) => {
        let arr = str.split('');
        let i = arr.length - 1;
        
        while (i >= 0 && arr[i] !== '0') {
            arr[i] = '0';
            i--;
        }
        if (i < 0) {
            return '1' + arr.join('');
        } else {
            arr[i] = '1';
            return arr.join('');
        }
    };
    
    let steps = 0;
    
    while (s.length > 1) {
        if (s[s.length - 1] === '0') {
            s = s.slice(0, s.length - 1);  // divide by 2
        } else {
            s = addOne(s);                  // add 1
        }
        steps++;
    }
    return steps;
};

const s = "1101";
console.log(numSteps(s));