
// Correct and Predict the output of below code

const strings = ['apple', 'banana', 'apple', 'orange', 'banana', 'apple'];

const count = strings.reduce((acc,str) => {
    acc[str] = acc[str] ? ++acc[str] : 1;
    return acc;
}, {});

console.log(count);