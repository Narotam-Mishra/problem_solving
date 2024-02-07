
/*

Task - Write JavaScript function named prepareFullBreakfast() that simulates preparing a full breakfast of eggs, toast and tea concurrently. The function should :-

1). Have three separate functions that return Promises for making eggs (makeEggs), making toast (makeToast) and making tea (makeTea). Each function should resolve after a random delay between 1 to 5 seconds, simulating the unpredictable nature of cooking times.

2). Use Promise.all to wait for all three components of the breakfast to be ready.

3). After all components are ready, log "Full breakfast is ready!" to the console

4). Use async/await syntax for cleaner code and error handling

# Criteria :-

a). Properly implement makeEggs, makeToast and reuse makeTea with random delays.

b). Use Promise.all() to handle concurrent Promise execution

c). Use async/await syntax for handling asynchronous code.

d). catch and log any errors.

*/

function makeEggs(){
    return new Promise((resolve, reject) => {
        // Random delay between 1 to 5 seconds
        const delay = Math.floor(Math.random() * 5) + 1;
        setTimeout(() => {
            resolve("Eggs are ready!");
        }, delay*1000);
    })
}

function makeToast(){
    return new Promise((resolve, reject) => {
        // Random delay between 1 to 5 seconds
        const delay = Math.floor(Math.random() * 5) + 1;
        setTimeout(() => {
            resolve("Toast is ready!");
        }, delay*1000);
    })
}

function makeTea(){
    return new Promise((resolve, reject) => {
        // Random delay between 1 to 5 seconds
        const delay = Math.floor(Math.random() * 5) + 1;
        setTimeout(() => {
            resolve("Tea is ready!");
        }, delay*1000);
    })
}

async function prepareFullBreakfast(){
    try{
        const [eggsResult, toastResult, teaResult] =  await Promise.all([makeEggs(), makeToast(), makeTea()])
        console.log(eggsResult);
        console.log(toastResult);
        console.log(teaResult);
    }
    catch(error){
        console.log("Something went wrong, got this error: "+error);
    }
}

prepareFullBreakfast();