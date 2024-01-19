
// Find output of below code 

/*

C
A
B

*/

setTimeout(() => {
    console.log("A");
    setTimeout(() => console.log("B"), 1000);
}, 1000);
console.log("C");