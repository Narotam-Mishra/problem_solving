
// Problem link - https://leetcode.com/problems/sum-of-subarray-minimums/description/

// Approach - 1 (Brute force approach)

let sumSubarrayMins1 = function(arr) {
    let subSum = 0;
    const modNum = 1000000007;
    for(let i=0; i<arr.length; i++){
        let minNum = arr[i];
        for(let j=i; j<arr.length; j++){
            minNum = Math.min(minNum, arr[j]);
            subSum += minNum;
        }
    }
    return subSum % modNum;
};

// Approach - 2 ()

let sumSubarrayMins = function(arr) {
    const n = arr.length;
    // using two Arrays to maintain left and right sub-arrays count where arr[i] is minimum
    const leftSubArrCnt = new Array(n).fill(0);
    const rightSubArrCnt = new Array(n).fill(0);

    // using two Stacks to maintain the elements along with their sub-array counts
    const st1 = [];
    const st2 = [];

    // Find left sub-arrays count where arr[i] is minimum
    for(let i=0; i<n; i++){
        // intial sub-array count will be 1 because there will be atleast one sub-array where arr[i] will be minimum
        let cnt = 1;
        // Calculate sub-arrays count from stack until element greater than arr[i]
        while(st1.length > 0 && st1[st1.length - 1][0] > arr[i]){
            cnt += st1.pop()[1];
        }
        st1.push([arr[i], cnt]);
        leftSubArrCnt[i] = cnt;
    }

    // Find right sub-arrays count where arr[i] is minimum
    for(let i=n-1; i>=0; i--){
        let cnt = 1;
        // Calculate sub-arrays count from stack until element greater than arr[i]
        while(st2.length > 0 && st2[st2.length - 1][0] >= arr[i]){
            cnt += st2.pop()[1];
        }
        st2.push([arr[i], cnt]);
        rightSubArrCnt[i] = cnt;
    }

    // Calculate the required sub-arrays sum using formula --> arr[i] * leftSubArrCnt[i] * rightSubArrCnt[i] 
    let ans = 0;
    const modNum = 1000000007;
    for(let i=0; i<n; i++){
        ans = (ans + arr[i] * leftSubArrCnt[i] * rightSubArrCnt[i]) % modNum;
    }

    // return answer 'ans'
    return ans;
};

let arr = [11,81,94,43,3];
console.log(sumSubarrayMins(arr));