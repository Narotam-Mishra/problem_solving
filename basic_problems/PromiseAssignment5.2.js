
/*

Task - Write a Javascript function named prepareBreakfast() that simulates preparing breakfast consisting of tea and toast. This function should :-

1). call the makeTea() function from last task and wait for it to complete

2). Then, simulate making toast, which takes 3 seconds and resolves with the string "Toast is ready!"

3). Chain these actions so that they happen sequentially, not concurrently

4). catch any errors and log them to the console

Criteria :-

1). Use .then() for chaining

2). use setTimeout() to simulate the toast preparation

3). Ensure the proper sequence of breakfast preparation.

4). Use .catch() to handle errors.


*/

function makeTea(){
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve("Tea is ready!");
        }, 2000)
    })
}

function prepareBreakfast(){
    makeTea().then((teaResult) => {
        console.log(teaResult);
        return new Promise((resolve,reject) => {
            setTimeout(() => {
                resolve("Breakfast is ready!");
            }, 3000)
        })
    })
    .then((toastResult) => {
        console.log(toastResult);
    })
    .catch((error) => {
        console.log('Opps!!, Task not completed: '+error);
    })
}

prepareBreakfast();