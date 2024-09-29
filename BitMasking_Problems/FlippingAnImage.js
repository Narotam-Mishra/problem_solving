
// Problem link :- https://leetcode.com/problems/flipping-an-image/description/?envType=problem-list-v2&envId=bit-manipulation

let flipAndInvertImage = function(image) {
     // iterate through each row of the image matrix
    for(let row of image){
        // start pointer for the row (left side)
        let left = 0;

        // end pointer for the row (right side)
        let right = row.length - 1;

        // swap and invert simultaneously
        while(left <= right){
            // swap the left and right elements
            // XOR operation: 1 ^ 1 = 0, 0 ^ 1 = 1, so row[left] ^ 1 will invert the value
            let temp = row[left] ^ 1;
            row[left] = row[right] ^ 1;
            row[right] = temp;
            
            // move pointers towards the center
            left++;
            right--
        }
    }
    // return the modified image
    return image;
};

let image = [[1,1,0],[1,0,1],[0,0,0]];
console.log(flipAndInvertImage(image));
