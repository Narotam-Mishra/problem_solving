
// CustomForEach new

Array.prototype.customForEach1 = function(cb){
    for(let i=0; i<this.length; i++){
        cb(this[i], this, i)
    }
}

let arr = [2,6,4,5,8];

arr.customForEach1((num) => {
    console.log(num);
})


Array.prototype.customForEach2 = function(callback, thisContext){
    if(typeof callback !== 'function'){
        throw `not a function`
    }

    const len = this.length;
    for(let i=0; i<len; i++){
        if(this.hasOwnProperty(i)){
            callback.call(thisContext, this[i], i)
        }
    }
}