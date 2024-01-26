
// Promise example-2

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
console.log("promise before:",res);

for(let i=0; i<10000000; i++){
    // blocking code
}

console.log("promise after:",res);

for(let i=0; i<100000000; i++){
    // blocking code
}

