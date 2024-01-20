
// Find output of below code :

/*

0
1
2

*/


for (var i = 0; i < 3; i++) {
    (function(j) {
        setTimeout(() => console.log(j), 2000 * j);
    })(i);
}