function rotateArrayByK(arr, k) {
    var n = arr.length;
    k = k % n;
    var res = [];
    for (var i = n - k; i < n; i++) {
        res.push(arr[i]);
    }
    for (var i = 0; i < n - k; i++) {
        res.push(arr[i]);
    }
    return res;
}
var arr = [1, 2, 3, 4, 5, 6, 7];
var k = 3;
console.log(rotateArrayByK(arr, k));
