

function binarySearch(arr, key) {
    var s = 0, e = arr.length - 1, mid;
    while (s < e) {
        mid = (s + e) / 2;
        if (key === arr[mid]) {
            return mid;
        }
        else if (key > arr[mid]) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return -1;
}
var arr = [3, 5, 7, 11, 16, 19, 21];
console.log(binarySearch(arr, 19));
