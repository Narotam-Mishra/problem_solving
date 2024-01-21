
// Find output of below code 

/*

After promise
Resolved!

*/

let promise = new Promise((resolve, reject) => {
    setTimeout(() => resolve("Resolved!"), 1000);
  });
  promise.then(value => console.log(value));
  console.log("After promise");