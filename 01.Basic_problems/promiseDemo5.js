
// Promise example - 5

function createAsyncPromise(){
    return new Promise((resolve,reject) => {
        // async code
        setTimeout(function timerCompleted(){
            // change state of promise
            const value = Math.random();
            if(value < 0.5){
                resolve(value);
            }else{
                reject(value);
            }
        }, 5000);
    });
}

const res = createAsyncPromise();

res.then(
  function fulfilledHandler(value) {
    console.log("promise1 fulfilled with value:", value);
  },
  function rejectedHandler(value) {
    console.log("promise1 rejected with value:", value);
  }
);

res.then(
    function fulfilledHandler(value) {
      console.log("promise2 fulfilled with value:", value);
    },
    function rejectedHandler(value) {
      console.log("promise2 rejected with value:", value);
    }
);

for(let i=0; i<1000000000; i++){
    // blocking code
}

