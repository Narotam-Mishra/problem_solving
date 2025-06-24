
// Problem link - https://leetcode.com/problems/relative-sort-array/description/?envType=problem-list-v2&envId=array

let relativeSortArray = function(arr1, arr2) {
    // step 1 - create a rank map for element in arr2
    const rankMap = {};
    for(let i=0; i<arr2.length; i++){
        rankMap[arr2[i]] = i;
    }

    // step 2 - sort `arr1` with a custom sort comparator
    arr1.sort((a,b) => {
        // step 3 - if both a and b are in arr2, sort based on their rank
        if(a in rankMap && b in rankMap){
            return rankMap[a] - rankMap[b];
        }

        // step 4 - if only `a` is in arr2, it comes before `b`
        if(a in rankMap) return -1;

        // step 5 - if only b is in arr2, it comes before a
        if(b in rankMap) return 1;

        // step 6 - if neither are in arr2, sort in ascending order
        return a - b;
    });

    // step 7 - return relative sorted `arr1`
    return arr1;
};

const arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6];

// const arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6];
console.log(relativeSortArray(arr1, arr2));