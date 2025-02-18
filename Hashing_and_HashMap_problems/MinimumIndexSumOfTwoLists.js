
// Probllem link : https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/?envType=problem-list-v2&envId=hash-table

let findRestaurant = function(list1, list2) {
    // step 1 - create map to store index of each word in list1
    const map = new Map();
    for(let i=0; i<list1.length; i++){
        map.set(list1[i], i);
    }

    // store minimum index sum in `minIndexSum`
    let minIndexSum = Infinity;

    // store words with the least index sum
    let res = [];

    // step 2 - iterate through list2 and find common words
    for(let j=0; j<list2.length; j++){
        // check if the list2 word exists in list1
        if(map.has(list2[j])){
            // get index from list1
            let i = map.get(list2[j]);
            
            // calculate index sum
            let indexSum = i + j;

            // step 3 - update minimum index sum and store corresponding word
            if(indexSum < minIndexSum){
                minIndexSum = indexSum;
                // reset result with the new least sum word
                res = [list2[j]];
            }else if(indexSum === minIndexSum){
                // append to result if it has the same min sum
                res.push(list2[j]);
            }
        }
    }

    // step 4 - return all common words with the least index sum
    return res;
};

const list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"];

// const list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"];

// const list1 = ["happy","sad","good"], list2 = ["sad","happy","good"]
console.log(findRestaurant(list1, list2));
