
// synchronous promise

function createSyncPromise(){
    return new Promise((res,rej) => {
        for(let i=0; i<10000000000; i++){
            // blocking code...
        }
        res(104);
    })
}

const res = createSyncPromise();
console.log("Hello");