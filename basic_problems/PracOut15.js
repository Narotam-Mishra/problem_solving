
// Find output of below code 

/*
1
5
4
2
3


*/

console.log("1");
setTimeout(() => {
    console.log("2");
    setTimeout(() => console.log("3"), 1000);
}, 2000);
setTimeout(() => console.log("4"), 1000);
console.log("5");