
// Find output of below code :

/*

0
1
2

*/


for (let i = 0; i < 3; i++) {
    setTimeout(() => console.log(i), 1000 * i);
}