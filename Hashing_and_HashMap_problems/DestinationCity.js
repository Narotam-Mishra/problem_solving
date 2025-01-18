
// Problem link : https://leetcode.com/problems/destination-city/description/?envType=problem-list-v2&envId=hash-table

let destCity = function(paths) {
    // step 1 - collect all starting cities in `startingCities` set
    const startingCities = new Set();
    for(let [cityA, cityB] of paths){
        startingCities.add(cityA);
    }

    // step 2 - find destination city
    for(let [cityA, cityB] of paths){
        if(!startingCities.has(cityB)){
            return cityB;
        }
    }

    // if no city is found (though guaranteed in this problem), return null
    return null;
};

// const paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]];

const paths = [["B","C"],["D","B"],["C","A"]];
console.log(destCity(paths));
