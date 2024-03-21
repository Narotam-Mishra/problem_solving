
/*

Task : Write a Javascript function named processData that simulates fetching data from an API and then processing it. This function should :

1). Simulate fetching data with a function fetchData() that returns a Promise that resolves with an array of numbers after a 2-second delay.

2). Write a function analyzeData that takes an array of numbers and returns a new Promise. This Promise should resolve with an object containing the sum and average of the numbers, but only if all numbers are positive. If any number is negative, the Promise should reject with an error message.

3). Use the fetchData function to get data, then process it with analyzeData(), handling both success and failure cases properly.

*/

// Simulate fetching data with a 2-second delay

function fetchData(){
    return new Promise((resolve) => {
        setTimeout(() => {
            const data = [3,5,7,2,1,4,-5];
            resolve(data);
        }, 2000)
    });
}

// Analyze data and return a Promise with sum and average

function analyzeData(numbers){
    return new Promise((resolve, reject) => {
        // check if any number is negative or not
        const hasNegative = numbers.some(num => num < 0);
        if(hasNegative){
            reject('Numbers can not be negative!!');
        }else{
            const sum = numbers.reduce((acc,val) => acc+val, 0);
            const averageOfNums =  sum / numbers.length;
            resolve({sum, averageOfNums});
        }
    })
}

// Process data using fetchData and analyzeData

async function processData(){
    try {
        const data = await fetchData();
        const result = await analyzeData(data);
        console.log('Data analysis result:', result);
    } catch (error) {
        console.log("Something went wrong:", error);
    }
}

// test the processData() function
processData();