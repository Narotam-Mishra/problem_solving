
// CustomMap using Array.prototype

Array.prototype.CustomMap = function(callback){
    const result = [];
    for(let i=0; i<this.length; i++){
        result.push(callback(this,this[i],i));
    }
    return result;
}

const arr = [2,4,3,7,9];

const ans = arr.CustomMap((arr,num) => {
    return num*num;
})

console.log(arr);
console.log(ans);

