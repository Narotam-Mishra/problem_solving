
// custom forEach() method

let arr = [2,3,5,1,6,8];

function customForEach(arr, callback){
    for(let i=0; i<arr.length; i++){
        callback(i,arr[i]);
    }
}

customForEach(arr,(index,element) => {
    console.log(`Array item at ${index}: ${element}`);
})
