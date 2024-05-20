
// 

function createPromiseChain(t){
    return new Promise((res,rej) => {
        setTimeout(() => {
            rej(t);
        }, t)
    })
}

createPromiseChain(5000) // return promise say pr1 {value: undefined, state: pending, onFulFilled: [f], onRejected: []}
.then(function f (value){
    console.log('Value in first then', value);
    return value*2  // return promise pr2 {value: undefined, state: pending, onFulFilled: [g], onRejected: []}
},
function prRejector1(){
    console.log('promise1 rejected');
    throw 200;
}) 
.then(function g (value){
    console.log('Value in second then', value);
    return value*3 // return promise pr3 {value: undefined, state: pending, onFulFilled: [h], onRejected: []}
}, function prRejector1(){
    console.log('promise2 rejected, chill');
    return 420;
}) 
.then(function h(value){
    console.log('Value in third then', value);
    return value*4
}) // return promise pr4 {value: undefined, state: pending, onFulFilled: [], onRejected: []}
