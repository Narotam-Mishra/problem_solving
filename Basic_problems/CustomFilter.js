
// create customFilter() method that mimicks Array.filter() method

Array.prototype.customFilter = function(callback){
    const resutArr = [];

    for(let i=0; i<this.length; i++){
        if(callback(this[i])){
            resutArr.push(this[i]);
        }
    }

    return resutArr;
}

const arr = [2,3,4,5,7,8,9,1,6];

const isEven = function(num){
    return num%2 === 0;
}

const isOdd = function(num){
    return num%2 !== 0;
}

const ans1 = arr.customFilter(isEven);
const ans2 = arr.customFilter(isOdd);

console.log(ans1);
console.log(ans2);