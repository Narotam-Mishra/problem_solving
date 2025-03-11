
// Problem link - https://leetcode.com/problems/count-items-matching-a-rule/description/?envType=problem-list-v2&envId=string

let countMatches = function(items, ruleKey, ruleValue) {
    // step 1 - map ruleKey to corresponding index
    let index;
    if(ruleKey === 'type'){
        index = 0;
    }else if(ruleKey === 'color'){
        index = 1;
    }else{
        index = 2;
    }

    // step 2 - initialize a counter to count the matching items
    let count = 0;
    
    // step 3 - traverse items array
    for(let i=0; i<items.length; i++){
        // check if the value at the corresponding index matches the ruleValue
        if(items[i][index] === ruleValue){
            count++;
        }
    }

    // step 4 - return count of matching items
    return count;
};

// const items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver";

const items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone";
console.log(countMatches(items, ruleKey, ruleValue));
