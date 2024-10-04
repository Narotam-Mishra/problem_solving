
// Problem link : https://leetcode.com/problems/decode-xored-array/description/?envType=problem-list-v2&envId=bit-manipulation&favoriteSlug=&status=TO_DO&difficulty=EASY

// Key Concept : Inverse of XOR is XOR itself

let decode = function(encoded, first) {
    // initialize the original array with the first element.
    let arr = [first];

    // reconstruct the rest of the array using the encoded values.
    for(let i=0; i<encoded.length; i++){
        arr.push(encoded[i] ^ arr[i]);
    }

    // return reconstructed array 'arr'
    return arr;
};

// let arr = [1, 2, 3], first = 1;

let arr = [6,2,7,3], first = 4;
console.log(decode(arr, first));
