
// Problem link : https://leetcode.com/problems/two-out-of-three/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

let twoOutOfThree = function(nums1, nums2, nums3) {
    // define freqMap locally
    let freqMap = {};

    // function to update frequency map based on unique elements from the input array
    function updateFrequency(arr){
        arr = new Set(arr);
    
        for(let num of arr){
            if(freqMap[num]){
                freqMap[num] += 1
            }else{
                freqMap[num] = 1;
            }
        }
    }

    // update frequency map for each array
    updateFrequency(nums1);
    updateFrequency(nums2);
    updateFrequency(nums3);

    // collect numbers that appear in at least two arrays
    let res = [];
    for(let [num, count] of Object.entries(freqMap)){
        if(count >= 2){
            res.push(Number(num));
        }
    }
    // return resultant 'res' array
    return res;
};

// let nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3];

// let nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]

let nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
console.log(twoOutOfThree(nums1, nums2, nums3));
