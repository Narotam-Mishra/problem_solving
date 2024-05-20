
// Find output of below code

/*

0
1
1
2
2
3

*/

for (var i = 0; i < 3; i++) {
    setTimeout((j) => {
        console.log(j);
        setTimeout(() => console.log(j + 1), 1000);
    }, i * 2000, i);
}