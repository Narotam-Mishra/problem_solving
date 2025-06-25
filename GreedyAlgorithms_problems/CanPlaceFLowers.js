
// Problem link - https://leetcode.com/problems/can-place-flowers/description/?envType=problem-list-v2&envId=array

let canPlaceFlowers = function(flowerbed, n) {
    // tack down number of flower planted
    let planted = 0;
    const len = flowerbed.length

    // step 1 - iterate on each flowerbed
    for(let i=0; i<len; i++){
        // step 2 - check if current flowerbed is empty
        if(flowerbed[i] === 0){
            // check left neighbour is empty or not
            const leftNeighbourEmpty = (i === 0) || (flowerbed[i-1] === 0);
            
            // check right neighbour is empty or not
            const rightNeighbourEmpty = (i === len-1) || (flowerbed[i+1] === 0);

            // step 3 - if both neighbors are safe(empty), we can plant here
            if(leftNeighbourEmpty && rightNeighbourEmpty){
                // plan flower
                flowerbed[i] = 1;

                // count planted flower
                planted++;

                // step 4 - early termination if we have planted enough flowers
                if(planted >= n){
                    return true;
                }
            }
        }
    }

    // step 5 - check and return if we planted at least 'n' flowers
    return planted >= n;
};

// const flowerbed = [1,0,0,0,1], n = 1;

const flowerbed = [1,0,0,0,1], n = 2;
console.log(canPlaceFlowers(flowerbed, n));