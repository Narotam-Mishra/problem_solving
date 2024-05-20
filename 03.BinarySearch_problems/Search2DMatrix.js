
// Problem link - https://leetcode.com/problems/search-a-2d-matrix/

// Approach - 1 (Brute Force)
// TC - O(n^2)

let searchMatrix = function(matrix, target) {
    let ans = false;
    for(let i=0; i<matrix.length; i++){
        for(let j=0; j<matrix[i].length; j++){
            if(target === matrix[i][j]){
                ans = true;
                return ans;
            } 
        }
    }
    return ans;
};

// Approach - 2 (optimal solution using binary search)
// TC - O(logn)

let searchMatrix1 = function(matrix, target) {
    let m = matrix.length, n = matrix[0].length;
    let s = 0, e = m*n - 1 ;

    while(s <= e){
        let mid = s + Math.floor((e - s)/2);
        let rowIdx = Math.floor(mid/n);
        let colIdx = mid % n;
        if(target === matrix[rowIdx][colIdx]){
            return true;
        }else if(target > matrix[rowIdx][colIdx]){
            s = mid + 1;
        }else{
            e = mid -1;
        }
    }
    return false;
};