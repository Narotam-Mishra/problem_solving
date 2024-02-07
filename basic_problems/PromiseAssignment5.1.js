
/*

Task - Write a JS function named 'makeTea' that simulates the action of making tea. This function should return a Promise that 

1). Resolves after a delay of 2 seconds, simulating the time it takes to make the tea.
2). Resolves with the string "Tea is ready!"

*/

function makeTea(){
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve("Tea is ready!");
        }, 2000)
    })
}


// use the Promise

makeTea()
  .then((message) => {
    console.log(message);
  })
  .catch((error) => {
    console.error(error);
  });